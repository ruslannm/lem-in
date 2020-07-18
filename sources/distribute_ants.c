/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 17:35:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_many_paths(t_map *m)
{
	if (m->maxflow == 1 || m->ants == 1)
	{
		m->max_ants_in_path[0] = m->ants;
		return (0);
	}
	return (1);
}

static void	set_max_ants_in_path(t_map *m)
{
	int i;
	int j;
	int antsandrooms;

	i = 1;
	m->max_ants_in_path[0] = i;
	j = 1;
	while (1)
	{
		if (++i > m->ants)
			return ;
		if (j == m->maxflow)
			j = 1;
		antsandrooms = m->len_path[j - 1] + m->max_ants_in_path[j - 1];
		if (antsandrooms > m->len_path[j] + m->max_ants_in_path[j])
		{
			m->max_ants_in_path[j] += 1;
			++j;
		}
		else
		{
			m->max_ants_in_path[0] += 1;
			j = 1;
		}
	}
}

void		distribute_ants(t_map *m)
{
	int i;
	int j;

	if (is_many_paths(m))
		set_max_ants_in_path(m);
	i = 0;
	while (1)
	{
		j = -1;
		while (++j < m->maxflow)
		{
			if (m->max_ants_in_path[j])
			{
				if (++i > m->ants)
					return ;
				m->ants_path[i] = j;
				m->print_ants_in_path[j] += 1;
				m->max_ants_in_path[j] -= 1;
			}
		}
		if (i >= m->ants)
			return ;
	}
}
