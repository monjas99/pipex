/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:22:05 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/28 10:52:52 by dmonjas-         ###   ########.fr       */
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
	if (!fpath)
		return (NULL);
	path = ft_split(fpath, ':');
	return (path);
}

void	ft_close_child(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

void	ft_pipex(char **av, char **envp)
{
	t_pipex	pipex;

	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_err(av[1]);
	pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		ft_err(av[4]);
	if (pipe(pipex.pipefd) < 0)
		return (perror("Pipe"));
	pipex.envp = ft_get_envp(envp);
	ft_command(pipex, av, envp);
	ft_command2(pipex, av, envp);
	ft_close_child(&pipex);
	ft_close_parent(&pipex);
	waitpid(pipex.pid_1, NULL, 0);
	waitpid(pipex.pid_2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		ft_pipex(av, envp);
	else
		return (ft_printf("Invalid number of arguments"));
	return (0);
}
