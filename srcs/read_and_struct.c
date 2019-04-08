/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:40:01 by sschmele          #+#    #+#             */
/*   Updated: 2019/01/13 17:36:25 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define READ_SIZE 21

void				make_coord(char *tmp, char *list, int line, int column)
{
	int				t;
	int				i;
	int				j;

	i = line;
	t = line / 5 * 5;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == '#')
		{
			list[j] = i / 5 - line / 5 + '0';
			j++;
			if (t == 0)
				list[j] = i - column + '0';
			else
				list[j] = i % t - column + '0';
			j++;
		}
		if (tmp[i] == '\n')
			t += 5;
		i++;
	}
}

void				learn_coord(char *tmp, char *list)
{
	int				line;
	int				column;
	int				t;
	int				i;

	line = ft_strchrlen(tmp, '#');
	i = 5;
	column = line % 5;
	while (tmp[i])
	{
		t = ft_strchrlen(tmp + i, '#');
		if (t < column)
			column = t % 5;
		i += 5;
	}
	make_coord(tmp, list, line, column);
}

t_list				*new_list_with_coord(int nb, char *tmp, t_list *begin_list)
{
	t_list			*list;
	t_list			*end;

	list = begin_list;
	while (list)
	{
		end = list;
		list = list->next;
	}
	MALLOC_N((list = (t_list*)malloc(sizeof(t_list))));
	if (!(list->content = ft_strnew(8)))
	{
		lstdel(&list);
		return (NULL);
	}
	list->content_size = nb + 64;
	list->next = NULL;
	if (nb == 1)
		begin_list = list;
	end->next = list;
	learn_coord(tmp, list->content);
	return (begin_list);
}

t_list				*lstdel(t_list **list)
{
	t_list			*clist;

	while (*list)
	{
		clist = *list;
		ft_lstdelcont(clist->content, clist->content_size);
		free(clist);
		clist = NULL;
		*list = (*list)->next;
	}
	return (NULL);
}

t_list				*read_map(int fd)
{
	int				iread;
	char			tmp[READ_SIZE + 1];
	t_list			*b;
	int				i;

	i = 1;
	b = NULL;
	while ((iread = read(fd, tmp, READ_SIZE)) >= (READ_SIZE - 1))
	{
		if (i > 26)
			return (lstdel(&b));
		if (iread == READ_SIZE)
			tmp[iread - 1] = '\0';
		tmp[iread] = '\0';
		if ((check_symbol_nb(tmp)) < 0)
			return (lstdel(&b));
		MALLOC_N((b = new_list_with_coord(i, tmp, b)));
		i++;
		if (iread == READ_SIZE - 1)
			break ;
	}
	return (iread == (READ_SIZE - 1) ? b : lstdel(&b));
}
