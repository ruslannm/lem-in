/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 19:36:23 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_empty(char *s)
{
	size_t i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

static t_map	*map_init_2(t_map *m)
{
	int i;
	int j;

	i = -1;
	m->init_2 = 1;
	m->tab = (int**)ft_memalloc(sizeof(int*) * m->q_rooms);
	m->tab_init = (int**)ft_memalloc(sizeof(int*) * m->q_rooms);
	m->ants_moving = (int*)ft_memalloc(sizeof(char*) * (m->ants + 1));
	m->ants_path = (int*)ft_memalloc(sizeof(char*) * (m->ants + 1));
	while (++i < m->q_rooms)
	{
		m->tab[i] = (int*)ft_memalloc(sizeof(int) * m->q_rooms);
		m->tab_init[i] = (int*)ft_memalloc(sizeof(int) * m->q_rooms);
		j = -1;
		while (++j < m->q_rooms)
		{
			m->tab[i][j] = 0;
			m->tab_init[i][j] = 0;
		}
	}
	return (m);
}

static void		read_map(t_map *m)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (m->ants == 0)
			count_ants(m, line);
		else if (line_with_room(m, line))
			links(m, line);
		else if ((m->started == 1 || m->started == 2) && !is_empty(line))
			rooms(m, line);
		else
		{
			if (line)
				free(line);
			exit_func(m, 1);
		}
		if (line)
			free(line);
	}
	if (!m->ants || !m->links[0])
		exit_func(m, 1);
	if (double_xy(m) || double_links(m))
		exit_func(m, 1);
	m = map_init_2(m);
}

static t_map	*map_init(char color)
{
	t_map *m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	m->links = (char**)ft_memalloc(sizeof(char*) * (MAX_ARR + 1));
	m->links_ind = 0;
	m->links_sp = (char**)ft_memalloc(sizeof(char*) * (MAX_ARR + 1));
	m->links_sp_ind = 0;
	m->ants_str = ft_strnew(1);
	m->rooms_list = (char**)ft_memalloc(sizeof(char*) * (MAX_ARR + 1));
	m->rooms_ind = 0;
	m->rooms = NULL;
	m->rooms_hash = NULL;
	m->q_rooms = 0;
	m->ants = 0;
	m->started = 0;
	m->init_2 = 0;
	m->good[0] = 0;
	m->good[1] = 0;
	m->rooms = NULL;
	m->tab = NULL;
	m->tab_init = NULL;
	m->paths = NULL;
	m->color = color;
	return (m);
}

int				main(int argc, char **argv)
{
	t_map	*m;
	char	color;

	color = 0;
	if (argc > 1)
	{
		if (!ft_strcmp("-h", argv[1]) || !ft_strcmp("--help", argv[1]))
		{
			print_usage();
			return (0);
		}
		else if (!ft_strcmp("-c", argv[1]) || !ft_strcmp("--color", argv[1]))
			color = 1;
	}
	m = map_init(color);
	read_map(m);
	if (!m->good[0] || !m->good[1])
		exit_func(m, 1);
	create_tab(m);
	create_paths(m);
	if (solution(m))
		result(m);
	else
		exit_func(m, 1);
	exit_func(m, 0);
}
