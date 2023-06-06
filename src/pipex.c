/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:22:05 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/06 12:34:03 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(char **av, char **envp)
{
	t_pipex	pipex;

	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		perror("Error infile");
	pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		perror("Error outfile");	
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		ft_pipex(av, envp);
	else
		return (ft_printf("Invalid number of arguments"));
	return (0);
}
