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

#ifndef MINISHELL_H
# define MINISHELL_H

# include "logic.h"
# include "parser.h"
# include "builtins.h"
# include "includes.h"

// COLORS
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define CYN   "\x1B[36m"
# define SIL   "\x1B[37m"
# define RESET "\x1B[0m"

// BUILTINS
# define BUIL_CMD   "cd:echo:env:exit:pwd:unset:export:help"

// ERRORS
# define ERR_PIPE	"shell: Syntax error near unexpected token '|'"
# define ERR_NEWL	"shell: Syntax error near newline"
# define ERR_MLC    "shell: Cannot allocate memory"
# define ERR_TKN	"shell: syntax error near unexpected token"

int		g_status;

int		rl_set_signals(void);
int		ft_print_errno(void);
int		ft_split_len(char **arr);

char	*ft_lst_to_str(t_list *lst);
char	**ft_get_paths(t_shell *shell);
char	**ft_lst_to_array(t_list *lst);

void	*ft_allocate(size_t size);
void	ft_cmd_add_back(t_cmd **lst, t_cmd *new);
void	ft_raise_error_n(char *error_msg, int code);
void	rl_replace_line(const char *buffer, int val);
void	ft_envadd_back(t_list	**chars, char *env_val);
void	ft_raise_error(char *error_msg, char *errno_msg);
void	ft_delete_el_env(t_shell *shell, const char *key);
void	ft_update_el_env(t_shell *shell, const char *keyval);
void	ft_critical_error(char *msg, char *errno_msg, int err);
void	ft_add_keyword(t_shell *shell, t_list **chars, bool is_redirect);

t_cmd	*ft_allocate_cmd(void);
size_t	ft_keylen(const char *keyval);
t_list	*ft_lstpop_find(t_list **lst, const char *key);
t_list	*ft_lstfind(t_list *lst, const char *key);

#endif //MINISHELL_H
