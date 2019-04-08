/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:42:54 by sschmele          #+#    #+#             */
/*   Updated: 2019/01/18 19:57:59 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				try_tet(t_lstmap *lstmap, char *str, int i, int j)
{
	int			k;

	k = 0;
	while (k < 8)
	{
		if (!(i + (str[k] - '0') < lstmap->side))
			return (-1);
		if (!(j + (str[k + 1] - '0') < lstmap->side))
			return (-1);
		if (lstmap->map[i + (str[k] - '0')][j + (str[k + 1] - '0')] != '.')
			return (-1);
		k += 2;
	}
	return (1);
}

int				search(t_lstmap *lstmap, char *str, int *i, int *j)
{
	while (*i < lstmap->side)
	{
		if (*i >= lstmap->side - 1 && *j >= lstmap->side - 1)
			return (-1);
		if (*i < lstmap->side - 1 && lstmap->map[*i + 1][*j] == '.')
			if ((try_tet(lstmap, str, *i, *j)) == 1)
				return (1);
		if (*j < lstmap->side - 1 && lstmap->map[*i][*j + 1] == '.')
			if ((try_tet(lstmap, str, *i, *j)) == 1)
				return (1);
		if (*j == lstmap->side - 1)
		{
			*j = 0;
			(*i)++;
		}
		else
			(*j)++;
	}
	return (-1);
}

int				recursion(t_list *list, t_lstmap *lstmap, int i, int j)
{
	if (list == NULL)
		return (1);
	while (search(lstmap, list->content, &i, &j) == 1)
	{
		put_tet(lstmap->map, list, i, j);
		if (recursion(list->next, lstmap, 0, 0) == 1)
			return (1);
		else
		{
			del_tet(lstmap->map, list, i, j);
			if (j == lstmap->side - 1)
			{
				j = 0;
				i++;
			}
			else
				j++;
		}
	}
	return (-1);
}

int				small_square(t_list *blist)
{
	int			nb;
	int			side;
	int			root;
	t_lstmap	*lstmap;

	nb = ft_lstsize(blist);
	side = 2;
	while ((root = ft_nb_root(side, 2)) < nb * 4)
		side++;
	lstmap = new_lstmap(side);
	while (recursion(blist, lstmap, 0, 0) < 0)
	{
		del_lstmap(lstmap);
		side++;
		lstmap = new_lstmap(side);
	}
	ft_printmap(lstmap->map, lstmap->side);
	del_lstmap(lstmap);
	return (1);
}
