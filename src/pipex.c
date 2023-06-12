/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:22:05 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/12 14:04:35 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_envp(char **envp)
{
	char	*fpath;
	char	**path;
	int		i;

	i = 0;
	fpath = NULL;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			{
				fpath = (envp[i] + 5);
				break ;
			}
		i++;
	}
	path = ft_split(fpath, ':');		
	return (path);
}

char	*ft_cmd(t_pipex pipex)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	tmp = ft_strjoin("/", pipex.cmd[0]);
	while (pipex.envp[i])
	{
		path = ft_strjoin(pipex.envp[i], tmp);
		free(tmp);
		if (access(path, F_OK == 0))
			return (path);
		i++;
	}
	return (0);
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
		pipex.path	= ft_cmd(pipex);
		execve(pipex.path, pipex.cmd, envp);
		perror("Erorr en execve:");
		exit(1);
	}
	//free(pipex.path);
	pipex.pid_2 = fork();
	if (pipex.pid_2 == 0)
	{
		close(pipex.pipefd[1]);
		dup2(pipex.pipefd[0], STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		pipex.cmd = ft_split(av[3], ' ');
		pipex.path = ft_cmp(pipex);
		execve(pipex.path, pipex.cmd, envp);
		perror("Error en execve:");
		exit(1);
	}
	close(pipex.pipefd[0]);
	close(pipex.pipefd[1]);
	waitpid(pipex.pid_1, NULL, 1);
	waitpid(pipex.pid_2, NULL, 1);
}

void	ft_pipex(char **av, char **envp)
{
	t_pipex	pipex;

	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		perror("Error infile");
	pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		perror("Error outfile");
	pipe(pipex.pipefd);
	pipex.envp = ft_get_envp(envp);
	ft_command(pipex, av, envp);	
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		ft_pipex(av, envp);
	else
		return (ft_printf("Invalid number of arguments"));
	return (0);
}
