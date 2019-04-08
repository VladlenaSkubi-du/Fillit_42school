/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:17:02 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/08 14:24:43 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# define MALLOC_N(x) if (x == NULL) return (NULL);

typedef struct		s_lstmap
{
	char			**map;
	int				side;
}					t_lstmap;
t_list				*read_map(int fd);
t_list				*lstdel(t_list **list);
int					check_symbol_nb(char *map);
int					check_valid_tet(char *map);
t_list				*new_list_with_coord(int nb, char *tmp, t_list *begin_list);
void				learn_coord(char *tmp, char *list);
void				make_coord(char *tmp, char *list, int line, int column);
int					small_square(t_list *blist);
char				**new_square(int side);
int					recursion(t_list *list, t_lstmap *lstmap, int i, int j);
void				del_tet(char **map, t_list *list, int i, int j);
int					search(t_lstmap *lstmap, char *str, int *i, int *j);
int					try_tet(t_lstmap *lstmap, char *str, int i, int j);
void				put_tet(char **map, t_list *list, int i, int j);
t_lstmap			*new_lstmap(int side);
void				del_lstmap(t_lstmap *lstmap);

#endif
