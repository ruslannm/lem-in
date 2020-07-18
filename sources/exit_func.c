/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 18:11:23 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_paths(t_map *m)
{
	int	i;

	i = -1;
	while (++i < m->q_path)
	{
		if (m->paths[i])
			free(m->paths[i]);
	}
	if (m->paths)
		free(m->paths);
}

static void	free_tabs(t_map *m)
{
	int	i;

	i = -1;
	while (++i < m->q_rooms)
	{
		if (m->tab[i])
			free(m->tab[i]);
		if (m->tab_init[i])
			free(m->tab_init[i]);
	}
	if (m->tab)
		free(m->tab);
	if (m->tab_init)
		free(m->tab_init);
}

void		exit_func(t_map *m, int error)
{
	free(m->ants_str);
	free(m->len_path);
	free(m->max_ants_in_path);
	free_array(m->links, m, 0);
	free_array(m->links_sp, m, 0);
	free_array(m->rooms_list, m, 0);
	if (m->init_2)
	{
		free_array(m->rooms, m, 0);
		free(m->ants_moving);
		free(m->ants_path);
		free(m->rooms_hash);
		free_paths(m);
		free_tabs(m);
	}
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}
