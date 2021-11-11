/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:06:58 by aleslie           #+#    #+#             */
/*   Updated: 2021/11/11 20:28:03 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BED		0
# define GOOD		1
# define READ_END	2

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <string.h>

char	*ft_collecting_path_cmd(char **path, char *command);
char	**ft_pars_var_environ(char **env);
void	ft_child_process(int *pipe_fd, char **argv, char **env);
void	ft_parent_process(int *pipe_fd, char **argv, char **env);
int		main(int argc, char **argv, char **env);

#endif