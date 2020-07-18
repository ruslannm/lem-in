/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 18:53:35 by rgero             #+#    #+#             */
/*   Updated: 2020/07/18 09:54:14 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*ft_memset_int(int *b, int c, size_t len)
{
	size_t	i;
	int		*set;

	i = 0;
	set = b;
	while (i < len)
	{
		set[i] = c;
		i++;
	}
	return (b);
}

void		bfs(t_map *m, t_bfs *b, int v)
{
	int		from;
	int		to;

	ft_memset_int(b->parent, -1, m->q_rooms);
	ft_memset_int(b->used, 0, m->q_rooms);
	b->front = 0;
	b->len = 0;
	push_back(b, v);
	b->used[v] = 1;
	while (b->len)
	{
		from = pop_front(b);
		if (from == 0)
			return ;
		to = -1;
		while (++to < m->q_rooms)
		{
			if ((m->tab[from][to] > 0) && (!b->used[to]))
			{
				b->used[to] = 1;
				b->parent[to] = from;
				push_back(b, to);
			}
		}
	}
}
