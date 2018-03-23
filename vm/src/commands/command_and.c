/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:32:05 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:32:07 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									int farg, int sarg)
{
	if (FLAGS->v && FLAGS->verbosity_four &&
		ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0 &&
		((ARGS[0].type == REG_CODE &&
			ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0) ||
		ARGS[0].type == DIR_CODE || ARGS[0].type == IND_CODE) &&
		((ARGS[1].type == REG_CODE &&
			ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0) ||
		ARGS[1].type == DIR_CODE || ARGS[1].type == IND_CODE))
	{
		ft_printf("P %4d | %s ", process->id, "and");
		ft_printf("%d %d r%d\n", farg, sarg, ARGS[2].arg);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

static int				get_value_ind(unsigned char *map, int pc, int arg)
{
	int		index;

	index = (pc + (arg % IDX_MOD)) % MEM_SIZE;
	index += index < 0 ? MEM_SIZE : 0;
	return (get_value_from_map(map, index, 4));
}

int						command_and(t_core *core, t_process *process)
{
	int		farg;
	int		sarg;

	farg = ARGS[0].type == IND_CODE ? get_value_ind(MAP, PC, ARGS[0].arg) : 0;
	if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0)
		farg = ARGS[0].type == REG_CODE ? REG[ARGS[0].arg - 1] : farg;
	farg = ARGS[0].type == DIR_CODE ? ARGS[0].arg : farg;
	sarg = ARGS[1].type == IND_CODE ? get_value_ind(MAP, PC, ARGS[1].arg) : 0;
	if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
		sarg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : sarg;
	sarg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : sarg;
	if (ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0
		&& ARGS[2].type == REG_CODE &&
		((ARGS[0].type == REG_CODE &&
			ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0) ||
		ARGS[0].type == DIR_CODE || ARGS[0].type == IND_CODE) &&
		((ARGS[1].type == REG_CODE &&
			ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0) ||
		ARGS[1].type == DIR_CODE || ARGS[1].type == IND_CODE))
	{
		REG[ARGS[2].arg - 1] = farg & sarg;
		process->carry = REG[ARGS[2].arg - 1] ? 0 : 1;
	}
	FLAGS->visual ? 0 : print_flag_v(core, process, farg, sarg);
	return (1);
}
