/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:32 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/22 10:50:37 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	check_arg(int argc, char **argv, char **envp);
char	*find_path(char *argv, char **envp);
char	**find_paths(int argc, char **argv, char **envp);
char	*find_flag(char *argv);
char	**find_flags(int argc, char **argv);
void	free_tabs(char **str);
int		size_tab(char **str);

#endif
