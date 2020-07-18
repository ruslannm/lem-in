/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:29:13 by rgero             #+#    #+#             */
/*   Updated: 2020/07/18 17:54:41 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** delete_extraedge() saves only path's edges, and deletes others edges,
** connected to vertices in path, exclude start and finish
*/

static void	delete_extraedge(t_map *m, t_bfs *b, int from, int k)
{
	int to;
	int i;

	if (k == -1)
		return ;
	to = b->parent[k];
	if (to == -1)
		return ;
	i = -1;
	while (++i < m->q_rooms)
	{
		if (!(i == from || i == to))
		{
			m->tab[k][i] = 0;
			m->tab[i][k] = 0;
		}
	}
}

void		save_path(t_map *m, t_bfs *b, int i)
{
	int k;
	int len;

	len = 0;
	k = 0;
	while (b->parent[k])
	{
		m->paths[i][k] = b->parent[k];
		if (b->parent[k] > 0 && b->parent[k] < m->q_rooms)
			delete_extraedge(m, b, k, b->parent[k]);
		k = b->parent[k];
		len++;
	}
	m->len_path[i] = len - 1;
}
