/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:04:59 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/11/17 15:25:56 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *message)
{
	if (message)
	{
		write(2, *(&message), ft_strlen(message));
		exit(0);
	}
	exit(0);
}
