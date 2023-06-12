/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:11:54 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/06/12 13:27:10 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int	infile;
	int	outfile;
	int	pipefd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	char	**envp;
	char	**cmd;
	char	*path;
}	t_pipex;

#endif
