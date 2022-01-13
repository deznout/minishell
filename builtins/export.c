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

#include "minishell.h"

static bool	ft_isexport(char *exp)
{
	int	i;

	i = -1;
	if (exp[0] == '=' || ft_isdigit(exp[0]) || !ft_isalpha(exp[0]))
		return (ft_export_error(exp));
	while (exp[++i] && exp[i] != '=')
		if (!ft_isalpha(exp[i]) && !ft_isdigit(exp[i]))
			return (ft_export_error(exp));
	return (false);
}

int	ft_export(char **argv, t_shell *shell)
{
	size_t	i;
	bool	ret_vel;

	i = 0;
	ret_vel = false;
	if (ft_split_len(argv) == 1)
	{
		ft_sort_env(shell, ft_split_len(shell->arr_env));
		print_export(shell->arr_env);
		return (ret_vel);
	}
	while (argv[++i])
	{
		if (!ft_isexport(argv[i]))
			ft_update_el_env(shell, argv[i]);
		else
			ret_vel = true;
	}
	return (ret_vel);
}
