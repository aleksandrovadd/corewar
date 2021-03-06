/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:31:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 16:31:37 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int					get_players_size(t_player *players)
{
	t_player		*iter;
	int				size;

	size = 0;
	iter = players;
	if (players->id)
	{
		while (iter)
		{
			size++;
			iter = iter->next;
		}
	}
	return (size);
}
