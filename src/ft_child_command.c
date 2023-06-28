/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:24:30 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/28 10:54:18 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_cmd(t_pipex pipex, char *av)
{
	int		i;
	char	*tmp;
	char	*path;

	if (access(av, X_OK) == 0)
		return (av);
	if (!pipex.envp)
		return (NULL);
	i = 0;
	tmp = ft_strjoin("/", pipex.cmd[0]);
	while (pipex.envp[i])
	{
		path = ft_strjoin(pipex.envp[i], tmp);
		if (access(path, F_OK) == 0)
		{
			free(tmp);
			return (path);
		}
		free(path);
		i++;
	}
	free (tmp);
	return (NULL);
}

void	ft_command(t_pipex pipex, char **av, char **envp)
{
	pipex.pid_1 = fork();
	if (pipex.pid_1 == 0)
	{
		close(pipex.pipefd[0]);
		dup2(pipex.pipefd[1], STDOUT_FILENO);
		dup2(pipex.infile, STDIN_FILENO);
		pipex.cmd = ft_split(av[2], ' ');
		pipex.path = ft_cmd(pipex, av[2]);
		if (!pipex.path)
		{
			ft_error(pipex.cmd[0]);
			exit (EXIT_FAILURE);
		}
		if (execve(pipex.path, pipex.cmd, envp) == -1)
			perror ("");
	}
}

void	ft_command2(t_pipex pipex, char **av, char **envp)
{
	pipex.pid_2 = fork();
	if (pipex.pid_2 == 0)
	{
		close(pipex.pipefd[1]);
		dup2(pipex.pipefd[0], STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		pipex.cmd = ft_split(av[3], ' ');
		pipex.path = ft_cmd(pipex, av[3]);
		if (!pipex.path)
		{
			ft_error(pipex.cmd[0]);
			exit (EXIT_FAILURE);
		}
		if (execve(pipex.path, pipex.cmd, envp) == -1)
			perror ("");
	}
}
