/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:46:49 by sschmele          #+#    #+#             */
/*   Updated: 2019/01/06 17:48:12 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_valid_tet(char *map)
{
	int		re;
	int		i;

	i = 0;
	re = 0;
	while (i < 21)
	{
		if (map[i] == '#')
		{
			if (i > 0 && map[i - 1] == '#')
				re++;
			if (i > 4 && map[i - 5] == '#')
				re++;
			if (i < 19 && map[i + 1] == '#')
				re++;
			if (i < 15 && map[i + 5] == '#')
				re++;
		}
		i++;
	}
	if (re < 5)
		return (-1);
	return (1);
}

int			check_symbol_nb(char *map)
{
	int		i;
	int		re;

	i = 0;
	re = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '.' && map[i] != '#' && i % 5 < 4)
			return (-1);
		if (map[i] == '#')
			re++;
		if (i % 5 == 4 && map[i] != '\n')
			return (-1);
		re++;
		i++;
	}
	if (re != 24)
		return (-1);
	return (check_valid_tet(map));
}
