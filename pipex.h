/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:44:02 by amagomad          #+#    #+#             */
/*   Updated: 2024/08/05 14:56:04 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_pipex
{
	char		**av;
	char		**envp;
	int			pipefd[2];
	int			fd_in;
	int			fd_out;
}	t_pipex;

void		ft_close(int a, int b, int c, int d);
void		ft_process(char *cmd, int fd_in, int fd_out, char **envp);
void		create_pipe(int pipefd[2]);
void		create_child(t_pipex *pipex, int *status1, int *status2);
int			ft_open(char *file, int flags, int mode);
int			child_status(int status);

#endif
