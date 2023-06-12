/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:11:54 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/12 10:52:57 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "errno.h"

typedef struct s_pipex
{
	int	infile;
	int	outfile;
	int	pipefd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	char	**path;
}	t_pipex;

#endif
