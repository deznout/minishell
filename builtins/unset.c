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

int	ft_unset(char **argv, t_shell *shell)
{
	t_list	*env;
	int		i;

	i = 1;
	if (!argv)
		return (false);
	else if (argv[1] == NULL)
		return (true);
	while (argv[i])
	{
		env = shell->env;
		while (env && env->next)
		{
			if (argv[i][0] != '\0')
				ft_delete_el_env(shell, argv[i]);
			env = env->next;
		}
		i++;
	}
	return (true);
}
