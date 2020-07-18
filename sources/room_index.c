/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 19:32:31 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	room_index(t_map *m, char *room_name)
{
	int index;
	int	room_hash;

	room_hash = hash(m, room_name);
	index = -1;
	while (++index < m->q_rooms && m->rooms_hash[index] >= 0)
	{
		if (room_hash == m->rooms_hash[index])
		{
			if (ft_strcmp(m->rooms[index], room_name) == 0)
				return (index);
		}
	}
	return (index);
}
