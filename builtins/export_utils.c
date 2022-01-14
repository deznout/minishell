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

int	ft_export_error(char *exp)
{
	ft_putstr_fd(RED"export: '", 2);
	ft_putstr_fd(exp, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static int	ft_custom_strcmp(void *s1, void *s2)
{
	char	*one;
	char	*two;
	int		i;

	one = (char *) s1;
	two = (char *) s2;
	i = 0;
	while (one[i] == two[i] && two[i] && one[i])
		i++;
	if (one[i] == two[i])
		return (0);
	return (one[i] - two[i]);
}

void	ft_sort_env(t_shell *shell, int len_env)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (++i < len_env)
	{
		j = -1;
		while (++j < len_env - 1)
		{
			if (ft_custom_strcmp(shell->env_arr[j], shell->env_arr[j + 1]) > 0)
			{
				tmp = shell->env_arr[j];
				shell->env_arr[j] = shell->env_arr[j + 1];
				shell->env_arr[j + 1] = tmp;
			}
		}
	}
}
