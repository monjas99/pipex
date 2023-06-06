/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:22:05 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/06 08:24:03 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int	infile;
	int errno;
	//int outfile;

	if (ac != 5)
		return (0);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno)); 
		perror("Error al abrir el archivo");
	}
	//outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR);
	//if (outfile < 0)
	//	return (0);
	

	return (0);
}
