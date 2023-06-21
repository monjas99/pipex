/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:54:12 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/21 14:45:42 by dmonjas-         ###   ########.fr       */
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
	close(pipex->infile);
	close(pipex->outfile);
}

void	ft_error(char *cmd)
{
	char	*str;

	str = ft_strjoin(cmd, ": command not found");
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	free (str);
}

void ft_err(char *av)
{
	perror(av);
	exit (EXIT_FAILURE);
}
