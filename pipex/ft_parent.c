/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:57:12 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/28 09:39:53 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_childofparent(char **argv, int fd1[2], int fd2[2], char **env)
{
	int		fd;
	char	**args2;
	char	*path2;

	args2 = split_cmd(argv[3]);
	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (access(argv[4], W_OK) == -1)
		printerror("pipex: permission denied: ", argv[4]);
	if (!args2)
		printerror("Failed to split arguments for cmd2: ", argv[4]);
	path2 = get_path(args2[0], env);
	close(fd1[1]);
	ft_checkexistedfile(path2, 0, args2[0]);
	dup2(fd1[0], STDIN_FILENO);
	close(fd1[0]);
	close(fd2[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd2[1]);
	close(fd);
	if (execve(path2, args2, env) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

int	ft_parent(int pid1, char **argv, int fd1[2], char **env)
{
	int		status;
	int		fd2[2];
	pid_t	pid2;

	status = 0;
	pipe(fd2);
	pid2 = fork();
	if (pid2 == -1)
		printerror("Fork Failed ", "");
	else if (pid2 == 0)
		ft_childofparent(argv, fd1, fd2, env);
	else
	{
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[1]);
		waitpid(pid1, &status, 0);
		if (WEXITSTATUS(status) != 0)
			exit(EXIT_FAILURE);
		waitpid(pid2, &status, 0);
		if (WEXITSTATUS(status) != 0)
			exit(EXIT_FAILURE);
	}
	return (status);
}
