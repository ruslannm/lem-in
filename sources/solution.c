/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:58:33 by rgero             #+#    #+#             */
/*   Updated: 2020/07/18 18:01:06 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	rebuild(t_map *m, t_bfs *b, int k, int flow)
{
	if (b->parent[k] == -1)
		return ;
	rebuild(m, b, b->parent[k], flow);
	m->tab[b->parent[k]][k] -= flow;
	m->tab[k][b->parent[k]] += flow;
	if (m->tab[b->parent[k]][k] && m->tab[k][b->parent[k]])
	{
		m->tab[b->parent[k]][k] = -1;
		m->tab[k][b->parent[k]] = -1;
	}
}

static int	find_flow(t_map *m, t_bfs *b)
{
	int k;

	k = 0;
	k = b->parent[k];
	while (-1 != k)
	{
		if (k == m->q_rooms - 1)
			return (1);
		k = b->parent[k];
	}
	return (0);
}

static int	delete_notusededge(t_map *m)
{
	int	i;
	int j;
	int notusededge;

	notusededge = 0;
	i = -1;
	while (++i < m->q_rooms)
	{
		j = -1;
		while (++j < m->q_rooms)
		{
			if (m->tab[i][j] == -1 || m->tab[i][j] == 1)
			{
				m->tab[i][j] = -3;
				notusededge = 1;
			}
			else if (m->tab[i][j] != -3)
				m->tab[i][j] = m->tab_init[i][j];
		}
	}
	return (notusededge);
}

static int	prepare_map(t_map *m)
{
	int		notusededge;
	t_bfs	*b;
	int		flow;
	int		maxflow;

	b = (t_bfs*)ft_memalloc(sizeof(t_bfs));
	maxflow = 0;
	notusededge = 1;
	while (notusededge)
	{
		notusededge = 0;
		while (1)
		{
			bfs(m, b, m->q_rooms - 1);
			flow = find_flow(m, b);
			if (flow == 0)
				break ;
			maxflow += flow;
			rebuild(m, b, 0, flow);
		}
		notusededge = delete_notusededge(m);
	}
	free(b);
	return (maxflow);
}

int			solution(t_map *m)
{
	t_bfs	*b;
	int		flow;
	int		maxflow;

	if (0 == prepare_map(m))
		return (0);
	b = (t_bfs*)ft_memalloc(sizeof(t_bfs));
	maxflow = 0;
	while (1)
	{
		bfs(m, b, m->q_rooms - 1);
		flow = find_flow(m, b);
		if (flow == 0)
			break ;
		save_path(m, b, maxflow);
		maxflow += flow;
		rebuild(m, b, 0, flow);
	}
	free(b);
	m->maxflow = maxflow;
	return (maxflow);
}
