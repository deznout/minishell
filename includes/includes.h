/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:09:43 by hbrent            #+#    #+#             */
/*   Updated: 2022/01/13 20:09:49 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

// DEBUG (change to prod)
# include "../Lib/libft.h"
// DEBUG

typedef struct s_cmd
{
	char			**arg;
	t_list			*lst;
	t_list			*redirects;
	int				pipe_fd[2];
	int				std_in;
	int				std_out;
	pid_t			pid;
	bool			is_fork;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char	*ps;
	t_list	*env;
	t_cmd	*cmd;
	t_cmd	*cmds;
	int		old_in;
	int		old_out;
	int		cmd_status;
	char	**arr_env;
	char	**buil_cmd;
}	t_shell;

#endif //INCLUDES_H
