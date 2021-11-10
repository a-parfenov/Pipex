/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:21:27 by aleslie           #+#    #+#             */
/*   Updated: 2021/11/11 01:37:45 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *env[])
{
	int		i;
	int		fd[2];
	int		file1;
	int		file2;
	char	*cat[3];
	char	*wc[3];
	pid_t	pid;
	

	cat[0] = "/bin/cat";
	cat[1] = "-e";
	cat[2] = NULL;
	wc[0] = "/usr/bin/ws";
	wc[1] = "-l";
	wc[2] = NULL;
	file1 = open("file1", O_RDONLY, 0666);
	file2 = open("file2", O_CREAT | O_TRUNC | O_WRONLY, 0666);

	i = 0;
	while (env[++i])
		{
			if (!strncmp("PATH=", env[i], 5))
				printf("%s", env[i]);
		}
	pipe(fd);
	pid = fork();
	if (!pid)
	{
		dup2(file1, 0);
		close(file1);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execle(cat[0], (const char *)cat, env);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
	}

	pid = fork();
	if (!pid)
	{
		dup2(file2, 1);
		close(file2);
		dup2(fd[0], 0);
		close(fd[0]);
		execle(cat[0], (const char *)wc, env);
	}
	else
	{
		close(fd[0]);
		wait(NULL);
	}
}