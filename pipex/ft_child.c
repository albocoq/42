/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:54:39 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/28 09:40:03 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(char **argv, int fd1[2], char **env, int fd)
{
	char	**args1;
	char	*path1;

	if (fd == -1)
		exit(EXIT_FAILURE);
	args1 = split_cmd(argv[2]);
	path1 = get_path(args1[0], env);
	ft_checkexistedfile(path1, 0, args1[2]);
	close(fd1[0]);
	dup2(fd, STDIN_FILENO);
	dup2(fd1[1], STDOUT_FILENO);
	close(fd1[1]);
	close(fd);
	if (execve(path1, args1, env) == -1)
	{
		perror(path1);
		exit(EXIT_FAILURE);
	}
}
