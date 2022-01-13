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

int	main(int ac, char **ag, char **env)
{
	t_shell	shell;
	int		rl_catch_signals;

	if (ac != 1)
	{
		printf(SIL"%s: %s: No such file or directory\n"RESET,
			getenv("USER"), ag[1]);
		return (127);
	}
	rl_catch_signals = 0;
	rl_set_signals();
	ft_init(&shell, env);
	ft_signal_main();
	ft_loop(&shell);
	return (0);
}
