/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:33:14 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/20 17:33:15 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int			ft_to_bin(unsigned int k)
{
	return (k == 0 || k == 1 ? k : ((k % 2) + 10 * ft_to_bin(k / 2)));
}
