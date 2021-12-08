/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:30:05 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/08 15:07:24 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*collecting_path_cmd(char **path, char *command)
{
	int		i;
	int		valid;
	char	*dir;
	char	*full_dir;

	i = 0;
	while (path[i])
	{
		dir = ft_strjoin(path[i], "/");
		full_dir = ft_strjoin(dir, command);
		free(dir);
		valid = access(full_dir, F_OK);
		if (valid < 0)
			free(full_dir);
		else
			return (full_dir);
		++i;
	}
	return (NULL);
}

char	**pars_var_environ(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			if (!path)
				error("Error_7: split");
			return (path);
		}
		++i;
	}
	perror("'PATH=' not found");
	exit(0);
}

void	child_process(int *pipe_fd, char **argv, char **env)
{
	int		file1;
	char	**path;
	char	**command;
	char	*all_file_path;
	int		i;

	i = -1;
	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
		error("File not found");
	dup2(file1, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	path = pars_var_environ(env);
	command = ft_split(argv[2], ' ');
	if (!command)
		error("Error_3: split");
	all_file_path = collecting_path_cmd(path, command[0]);
	while (path[++i])
		free(path[i]);
	free(path);
	if (!all_file_path)
		perror("Command not found {child_process}");
	execve(all_file_path, command, env);
}

void	parent_process(int *pipe_fd, char **argv, char **env)
{
	int		file2;
	char	**path;
	char	**command;
	char	*all_file_path;
	int		i;

	i = -1;
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file2 < 0)
		error("File not found");
	dup2(pipe_fd[0], 0);
	dup2(file2, 1);
	close(pipe_fd[1]);
	path = pars_var_environ(env);
	command = ft_split(argv[3], ' ');
	if (!command)
		error("Error_6: split");
	all_file_path = collecting_path_cmd(path, command[0]);
	while (path[++i])
		free(path[i]);
	free(path);
	if (!all_file_path)
		perror("Command not found {ft_parent_process}");
	execve(all_file_path, command, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		return (0);
	if (pipe(pipe_fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		perror("Error creating a new process");
		return (0);
	}
	if (pid == 0)
		child_process(pipe_fd, argv, env);
	else
		parent_process(pipe_fd, argv, env);
	return (0);
}
