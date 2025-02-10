/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:57:33 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/23 10:53:42 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_checkexistedfile(char *file, int isfile, char *command)
{
	int	fd;

	fd = access(file, F_OK);
	if (fd == -1)
	{
		if (isfile)
			ft_putstr_fd("pipex: no such file or directory: ", 2);
		else
			ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
		return ;
	}
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(allpath);
	ft_free_tab(s_cmd);
	return ("null");
}

void	printerror(char *message, char *arg)
{
	ft_putstr_fd(message, 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	exit(EXIT_FAILURE);
}
