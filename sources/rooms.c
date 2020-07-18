/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 09:13:01 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	is_number(char **r, t_map *m, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				free_array(r, m, 1);
		}
	}
	else
		free_array(r, m, 1);
}

static void	validate_room(t_map *m, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[1] == NULL || r[2] == NULL || r[3] != NULL)
		free_array(r, m, 1);
	is_number(r, m, r[1]);
	is_number(r, m, r[2]);
	free_array(r, m, 0);
}

int			line_with_room(t_map *m, char *line)
{
	int		i;
	char	*str;

	if ('\0' == line[0] || '#' == line[0] || ft_strchr(line, ' '))
		return (0);
	if (NULL == m->rooms)
		add_rooms(m);
	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == '-')
		{
			str = ft_strsub(line, 0, i);
			if (is_room(m, str))
			{
				if (line_with_room2(m, line, str))
				{
					ft_strdel(&str);
					return (1);
				}
			}
			ft_strdel(&str);
		}
	}
	return (0);
}

void		rooms(t_map *m, char *line)
{
	m->started = 2;
	m->rooms_list[m->rooms_ind++] = ft_strdup(line);
	if (line[0] == '#')
		return ;
	validate_room(m, line);
	m->q_rooms++;
}

int			is_room(t_map *m, char *str)
{
	int		i;
	int		str_hash;
	char	**rooms;

	i = -1;
	if (NULL == m->rooms_list[0])
		return (0);
	str_hash = hash(m, str);
	rooms = m->rooms;
	while (m->rooms_hash[++i] >= 0)
	{
		if (str_hash == m->rooms_hash[i])
		{
			if (rooms[i][0] != '#')
			{
				if (ft_strcmp(rooms[i], str) == 0)
					return (1);
			}
		}
	}
	return (0);
}
