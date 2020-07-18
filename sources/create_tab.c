/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 19:34:05 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_edges(t_map *m, int r_1, int r_2)
{
	m->tab[r_1][r_2] = 1;
	m->tab[r_2][r_1] = 1;
	m->tab_init[r_1][r_2] = 1;
	m->tab_init[r_2][r_1] = 1;
}

void		create_tab(t_map *m)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**links;
	char	**l;

	i = -1;
	links = m->links_sp;
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		l = ft_strsplit(links[i], ' ');
		if ((r_1 = room_index(m, l[0])) >= m->q_rooms ||
			(r_2 = room_index(m, l[1])) >= m->q_rooms)
		{
			exit_func(m, 1);
		}
		if (r_2 || r_1)
			set_edges(m, r_1, r_2);
		free_array(l, m, 0);
	}
}
