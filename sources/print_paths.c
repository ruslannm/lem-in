/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 14:49:36 by rgero             #+#    #+#             */
/*   Updated: 2020/07/18 18:18:43 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_rooms(t_map *m, int path)
{
	int i;

	i = 0;
	while (m->paths[path][i] > 0)
	{
		if (m->paths[path][i] == m->q_rooms - 1)
			ft_printf("%s", m->rooms[m->paths[path][i]]);
		else
			ft_printf("%s -> ", m->rooms[m->paths[path][i]]);
		i = m->paths[path][i];
	}
	ft_printf("\n");
}

void		print_paths(t_map *m)
{
	int i;

	ft_printf("Start: %s, End: %s\n", m->rooms[0], m->rooms[m->q_rooms - 1]);
	i = -1;
	while (++i < m->maxflow)
	{
		if (0 == i % 7)
			ft_printf("Path%3d :", i + 1);
		if (1 == i % 7)
			ft_printf("{red}Path%3d{reset} :", i + 1);
		if (2 == i % 7)
			ft_printf("{green}Path%3d{reset} :", i + 1);
		if (3 == i % 7)
			ft_printf("{cyan}Path%3d{reset} :", i + 1);
		if (4 == i % 7)
			ft_printf("{yellow}Path%3d{reset} :", i + 1);
		if (5 == i % 7)
			ft_printf("{blue}Path%3d{reset} :", i + 1);
		if (6 == i % 7)
			ft_printf("{magenta}Path%3d{reset} :", i + 1);
		ft_printf(" %4d ants : ", m->print_ants_in_path[i]);
		print_rooms(m, i);
	}
	ft_printf("\n");
}
