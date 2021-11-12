/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:06:58 by aleslie           #+#    #+#             */
/*   Updated: 2021/11/12 13:55:21 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*collecting_path_cmd(char **path, char *command);
char	**pars_var_environ(char **env);
void	child_process(int *pipe_fd, char **argv, char **env);
void	parent_process(int *pipe_fd, char **argv, char **env);
int		main(int argc, char **argv, char **env);

#endif