/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:47:45 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 20:47:47 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_process				*init_process(void)
{
	t_process			*process;
	static int			id = 0;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	process->pc = -1;
	process->player = 0;
	process->reg = (int *)malloc(REG_SIZE * REG_NUMBER);
	ft_bzero(process->reg, REG_NUMBER);
	process->id = ++id;
	process->cycle = 0;
	process->carry = 0;
	process->is_live = 0;
	process->iter = -1;
	process->players_last_live = 0;
	process->last_live = 0;
	process->cycles_to_exec = 0;
	process->command = 0;
	process->codage = 0;
	process->octal = 0;
	process->step = 0;
	process->args = (t_args *)malloc(sizeof(t_args) * MAX_ARGS_NUMBER);
	ft_bzero(process->args, MAX_ARGS_NUMBER);
	process->next = NULL;
	return (process);
}
