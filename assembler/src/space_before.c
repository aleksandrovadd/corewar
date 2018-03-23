/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_before.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:27:21 by daleksan          #+#    #+#             */
/*   Updated: 2018/03/22 17:28:38 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int						space_before(t_line *tline)
{
	if (!tline->deintegrated_line || !tline->deintegrated_line[1])
		return (EXIT_FAILURE);
	if (tline->deintegrated_line[1][0] == START_QUOTES)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
