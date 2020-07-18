/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 07:27:01 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		links(t_map *m, char *line)
{
	if (m->started == 2)
		m->started = 3;
	if (m->started != 3)
		exit_func(m, 1);
	m->links[m->links_ind] = ft_strdup(line);
	m->links_ind++;
}

void		links_sp(t_map *m, char *link1, char *link2)
{
	char	*str;
	int		len;

	len = ft_strlen(link1) + ft_strlen(link2) + 1;
	str = ft_strnew(len);
	str = ft_strcat(str, link1);
	str = ft_strcat(str, " ");
	str = ft_strcat(str, link2);
	m->links_sp[m->links_sp_ind] = ft_strdup(str);
	m->links_sp_ind++;
	free(str);
}

int			double_links(t_map *m)
{
	int		i;
	int		j;
	char	**links;

	i = -1;
	links = m->links_sp;
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		j = i;
		while (links[++j])
		{
			if (links[j][0] == '#')
				continue ;
			if (double_links2(m, links[i], links[j]))
				return (1);
		}
	}
	return (0);
}
