/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:06:06 by sschmele          #+#    #+#             */
/*   Updated: 2019/01/12 17:59:04 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_list	*blist;

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	if ((blist = read_map(open(argv[1], O_RDONLY))) == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (small_square(blist) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (0);
}
