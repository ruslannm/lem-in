/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/05/01 00:00:00 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_rooms2(t_map *m)
{
	m->rooms = (char**)ft_memalloc(sizeof(char*) * (m->q_rooms + 1));
	m->rooms_hash = (int*)malloc(sizeof(int) * (m->q_rooms + 1));
	if (m->rooms_hash != NULL)
		ft_memset_int(m->rooms_hash, -1, m->q_rooms + 1);
}

int			double_xy2(t_map *m, char *rooms_i, char *rooms_j)
{
	char	**r;
	char	**next_r;

	r = ft_strsplit(rooms_i, ' ');
	next_r = ft_strsplit(rooms_j, ' ');
	if (ft_strcmp(r[1], next_r[1]) == 0 &&\
	ft_strcmp(r[2], next_r[2]) == 0)
	{
		free_array(r, m, 0);
		free_array(next_r, m, 0);
		return (1);
	}
	free_array(r, m, 0);
	free_array(next_r, m, 0);
	return (0);
}

int			double_links2(t_map *m, char *links_i, char *links_j)
{
	char	**l;
	char	**next_l;

	l = ft_strsplit(links_i, ' ');
	next_l = ft_strsplit(links_j, ' ');
	if ((ft_strcmp(l[0], next_l[0]) == 0 &&\
	ft_strcmp(l[1], next_l[1]) == 0)\
	|| (ft_strcmp(l[0], next_l[1]) == 0 &&\
	ft_strcmp(l[1], next_l[0]) == 0))
	{
		free_array(l, m, 0);
		free_array(next_l, m, 0);
		return (1);
	}
	free_array(l, m, 0);
	free_array(next_l, m, 0);
	return (0);
}

int			line_with_room2(t_map *m, char *line, char *str)
{
	char	*str2;

	str2 = ft_strsub(line, ft_strlen(str) + 1,\
	ft_strlen(line) - ft_strlen(str) - 1);
	if (is_room(m, str2))
	{
		links_sp(m, str, str2);
		ft_strdel(&str2);
		return (1);
	}
	return (0);
}
