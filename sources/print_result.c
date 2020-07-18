/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 18:01:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ant(t_map *m, int ant, char *room)
{
	int i;

	i = m->ants_path[ant];
	if (0 == i % 7 || 0 == m->color)
		ft_printf("L%d-%s ", ant, room);
	else if (1 == i % 7)
		ft_printf("L%d-{red}%s{reset} ", ant, room);
	else if (2 == i % 7)
		ft_printf("L%d-{green}%s{reset} ", ant, room);
	else if (3 == i % 7)
		ft_printf("L%d-{cyan}%s{reset} ", ant, room);
	else if (4 == i % 7)
		ft_printf("L%d-{yellow}%s{reset} ", ant, room);
	else if (5 == i % 7)
		ft_printf("L%d-{blue}%s{reset} ", ant, room);
	else if (6 == i % 7)
		ft_printf("L%d-{magenta}%s{reset} ", ant, room);
}

static void	start_ants(t_map *m, int *ant)
{
	int path;

	if (*ant > m->ants)
		return ;
	path = m->ants_path[*ant];
	m->ants_moving[*ant] = m->paths[path][0];
	*ant = *ant + 1;
	while (*ant <= m->ants)
	{
		path = m->ants_path[*ant];
		if (0 == path)
			return ;
		m->ants_moving[*ant] = m->paths[path][0];
		*ant = *ant + 1;
	}
}

static int	move_ants(t_map *m, int current_ant)
{
	int path;
	int ant;
	int current_room;
	int next_room;
	int finish;

	finish = 1;
	ant = 0;
	while (++ant <= m->ants)
	{
		path = m->ants_path[ant];
		current_room = m->ants_moving[ant];
		if (current_room > 0)
		{
			next_room = m->paths[path][current_room];
			m->ants_moving[ant] = m->paths[path][current_room];
			if (next_room > 0)
				finish = 0;
		}
	}
	if (current_ant <= m->ants)
		return (0);
	return (finish);
}

static void	print_result(t_map *m)
{
	int ant;
	int i;
	int room;

	ant = 1;
	start_ants(m, &ant);
	while (1)
	{
		i = 0;
		while (++i <= m->ants)
		{
			if ((room = m->ants_moving[i]) > 0)
				print_ant(m, i, m->rooms[room]);
		}
		ft_putchar('\n');
		if (move_ants(m, ant))
			break ;
		start_ants(m, &ant);
	}
}

void		result(t_map *m)
{
	int i;

	ft_putendl(m->ants_str);
	i = -1;
	while (++i < m->rooms_ind)
		ft_putendl(m->rooms_list[i]);
	i = -1;
	while (++i < m->links_ind)
		ft_putendl(m->links[i]);
	ft_putchar('\n');
	distribute_ants(m);
	if (m->color)
		print_paths(m);
	print_result(m);
}
