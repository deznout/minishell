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

int	ft_env(t_shell *shell)
{
	t_list	*tmp;

	tmp = shell->env;
	while (tmp->next)
	{
		if (ft_strrchr(tmp->content, '='))
			ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	if (ft_strrchr(tmp->content, '='))
		ft_putendl_fd(tmp->content, 1);
	return (0);
}
