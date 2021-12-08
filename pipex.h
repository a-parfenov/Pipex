/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:06:58 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/08 15:09:34 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

void	error(char *str);

char	*collecting_path_cmd(char **path, char *command);
char	**pars_var_environ(char **env);
void	child_process(int *pipe_fd, char **argv, char **env);
void	parent_process(int *pipe_fd, char **argv, char **env);
int		main(int argc, char **argv, char **env);

#endif