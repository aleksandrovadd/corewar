/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_header_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:17:41 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/22 18:01:18 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		g_comment_written;
static int		g_name_written;
static int		g_i;

static int		comment_comment(t_champion *header, int *i)
{
	if (space_before(&header->tlines[(*i)]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	header->tlines[(*i)].linetype = HEADER_TYPE;
	if (treat_comment_header((char *)header->tlines[(unsigned)(*i)].\
			line_content_trim, header, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	g_comment_written++;
	return (EXIT_SUCCESS);
}

static int		name_name(t_champion *header, int *i)
{
	if (space_before(&header->tlines[(*i)]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	header->tlines[(*i)].linetype = HEADER_TYPE;
	if (treat_name_header((char *)header->tlines[(*i)].\
				line_content_trim, header, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	g_name_written++;
	return (EXIT_SUCCESS);
}

static int		is_comment_macros(t_champion *header)
{
	return (ft_strequ(COMMENT_CMD_STRING, (const char *)\
				header->tlines[g_i].deintegrated_line[0]));
}

static int		is_name_macros(t_champion *header)
{
	return (ft_strequ(NAME_CMD_STRING, (const char *)\
				header->tlines[g_i].deintegrated_line[0]));
}

int				is_header_valid(t_champion *header)
{
	SET_TO_ZEROABC(g_i, g_comment_written, g_name_written);
	while ((header->tlines[g_i].command_index == -1) &&\
			(!header->tlines[g_i].label) &&\
			((unsigned)g_i < header->lines_count))
	{
		if (!header->tlines[g_i].line_content_trim[0])
			do_nothing();
		else if (g_comment_written == 1 && g_name_written == 1)
			break ;
		else if (is_comment_macros(header))
		{
			if (comment_comment(header, &g_i) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (is_name_macros(header))
		{
			if (name_name(header, &g_i) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			return (EXIT_FAILURE);
		g_i++;
	}
	header->commands_start_line_id = g_i;
	return (!(g_comment_written == 1 && g_name_written == 1));
}
