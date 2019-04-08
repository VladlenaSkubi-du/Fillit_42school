/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:48:24 by sschmele          #+#    #+#             */
/*   Updated: 2019/01/17 15:44:14 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			del_lstmap(t_lstmap *lstmap)
{
	ft_mapdel(lstmap->map, lstmap->side - 1);
	free(lstmap);
}

t_lstmap		*new_lstmap(int side)
{
	t_lstmap	*lstmap;

	MALLOC_N((lstmap = (t_lstmap*)malloc(sizeof(t_lstmap))));
	lstmap->map = new_square(side);
	lstmap->side = side;
	return (lstmap);
}

char			**new_square(int side)
{
	char		**map;
	int			i;

	i = 0;
	MALLOC_N((map = (char**)malloc(sizeof(char*) * side)));
	while (i < side)
	{
		if (!(map[i] = ft_strnew(side)))
			ft_mapdel(map, i - 1);
		ft_memset(map[i], '.', side);
		i++;
	}
	return (map);
}

void			put_tet(char **map, t_list *list, int i, int j)
{
	int			k;
	char		*str;

	k = 0;
	str = list->content;
	while (k < 8)
	{
		map[i + (str[k] - '0')][j + (str[k + 1] - '0')] = list->content_size;
		k += 2;
	}
}

void			del_tet(char **map, t_list *list, int i, int j)
{
	int			k;
	char		*cont;

	k = 0;
	cont = list->content;
	while (k < 8)
	{
		map[i + (cont[k] - '0')][j + (cont[k + 1] - '0')] = '.';
		k += 2;
	}
}
