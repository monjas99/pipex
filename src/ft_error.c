/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:54:12 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/19 12:25:28 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_child(char *path, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free (cmd[i]);
		i++;
	}
	free (path);
}

void	ft_close_parent(t_pipex *pipex)
{
	int	i;

	close(pipex->infile);
	close(pipex->outfile);
	i = 0;
	while (pipex->envp[i])
	{
		free (pipex->envp[i]);
		i++;
	}
}

void	ft_error(char *str)
{
	str = ft_strjoin(strerror(errno), ft_strjoin(": ", str));
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	free(str);
}

int	ft_str_error(char *str, char *cmd)
{
	str = ft_strjoin(str, cmd);
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	free (str);
	return (2);
}
