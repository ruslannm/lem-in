/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:36:56 by rgero             #+#    #+#             */
/*   Updated: 2020/07/18 17:34:04 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_paths(t_map *m)
{
	int	i;
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	i = -1;
	while (++i < m->q_rooms)
	{
		if (m->tab[0][i])
			count[0]++;
		if (m->tab[m->q_rooms - 1][i])
			count[1]++;
	}
	return (count[0] < count[1] ? count[0] : count[1]);
}

void		create_paths(t_map *m)
{
	int i;

	m->q_path = count_paths(m);
	m->paths = (int**)ft_memalloc(sizeof(int*) * (m->q_path));
	m->len_path = (int*)ft_memalloc(sizeof(int) * (m->q_path));
	m->max_ants_in_path = (int*)ft_memalloc(sizeof(int) * (m->q_path));
	m->print_ants_in_path = (int*)ft_memalloc(sizeof(int) * (m->q_path));
	i = -1;
	while (++i < m->q_path)
		m->paths[i] = (int*)ft_memalloc(sizeof(int) * m->q_rooms);
}
