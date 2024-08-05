/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:43:13 by amagomad          #+#    #+#             */
/*   Updated: 2024/08/05 14:54:46 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_args(int ac)
{
	if (ac != 5)
	{
		ft_printf("5 arguments are required\n");
		exit(EXIT_FAILURE);
	}
}

void	create_child(t_pipex *pipex, int *status1, int *status2)
{
	pid_t	child1;
	pid_t	child2;

	child1 = fork();
	if (child1 == 0)
	{
		close(pipex->pipefd[0]);
		ft_process(pipex->av[2], pipex->fd_in, pipex->pipefd[1], pipex->envp);
		perror("child1 failed");
		exit(EXIT_FAILURE);
	}
	child2 = fork();
	if (child2 == 0)
	{
		close(pipex->pipefd[1]);
		ft_process(pipex->av[3], pipex->pipefd[0], pipex->fd_out, pipex->envp);
		perror("child2 failed");
		exit(EXIT_FAILURE);
	}
	close(pipex->fd_in);
	close(pipex->fd_out);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(child1, status1, 0);
	waitpid(child2, status2, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex			pipex;
	int				status1;
	int				status2;

	ft_args(ac);
	pipex.fd_in = ft_open(av[1], O_RDONLY, 0);
	if (pipex.fd_in == -1)
	{
		fprintf("Error opening input file: %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	pipex.fd_out = ft_open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex.fd_out == -1)
	{
		fprintf("Error opening output file: %s\n", av[4]);
		close(pipex.fd_in);
		exit(EXIT_FAILURE);
	}
	create_pipe(pipex.pipefd);
	pipex.av = av;
	pipex.envp = envp;
	create_child(&pipex, &status1, &status2);
	close(pipex.fd_in);
	close(pipex.fd_out);
	return (child_status(status2));
}
