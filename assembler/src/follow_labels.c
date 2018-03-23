/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remember_all_labels.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:41:54 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/22 18:09:47 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		g_line;

/*
**	Підраховуємо кількість рядків і записуємо лейбли в структуру
*/

static void		set_debug_info(t_champion *champion, char *line)
{
	champion->nerrorline = g_line;
	champion->serrorline = (unsigned char *)line;
}

int				remember_all_labels_and_count_lines(t_champion *champion)
{
	char		*line;
	char		**deintegrated;

	g_line = 1;
	while ((line = get_raw_line_fd(champion->fdin)))
	{
		champion->lines_count++;
		delete_comments((unsigned char *)line);
		deintegrated = ft_split_whitespace(line);
		if (ft_endswithchar(deintegrated[FIRST_ITEM], LABEL_CHAR))
		{
			deintegrated[FIRST_ITEM][ft_strlen(
					deintegrated[FIRST_ITEM]) - 1] = '\0';
			if (validate_remember_label(deintegrated[FIRST_ITEM], champion)
					== EXIT_FAILURE)
			{
				set_debug_info(champion, line);
				return (EXIT_FAILURE);
			}
		}
		ft_delete_deintegrated(deintegrated);
		free(line);
		g_line++;
	}
	return (EXIT_SUCCESS);
}
