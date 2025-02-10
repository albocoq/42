/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:01:35 by aboussem          #+#    #+#             */
/*   Updated: 2025/02/10 09:38:14 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd1[2];
	pid_t	pid1;
	int		fd;
	int		status;

	status = 1;
	if (argc != 5)
		printerror("Usage: ./pipex infile cmd1 cmd2 outfile", "");
	ft_checkexistedfile(argv[1], 1, argv[1]);
	fd = open(argv[1], O_RDONLY);
	pipe(fd1);
	pid1 = fork();
	if (pid1 == -1)
		printerror("Fork failed", "");
	else if (pid1 == 0)
		ft_child(argv, fd1, env, fd);
	else
		status = ft_parent(pid1, argv, fd1, env);
	return (status);
}
