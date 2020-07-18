/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:41:30 by rgero             #+#    #+#             */
/*   Updated: 2020/07/17 18:32:07 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_pow2(t_map *m)
{
	int	i;

	i = 0;
	m->pow2[i] = 1;
	while (++i < HASH_SIZE)
		m->pow2[i] = (m->pow2[i - 1] * 2);
	i = -1;
	while (++i < m->q_rooms)
		m->rooms_hash[i] = -1;
}

int		hash(t_map *m, char *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (s[++i] != '\0')
		ret = (ret + (s[i] * m->pow2[i]) % MODUL) % MODUL;
	return (ret);
}
