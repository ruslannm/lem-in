/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/16 21:39:42 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_ants(t_map *m, char *line)
{
	int		i;
	char	*s;

	i = 0;
	m->started = 1;
	m->ants_str = join_str(m->ants_str, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((m->ants = ft_atoi(s)) <= 0)
	{
		free(s);
		exit_func(m, 1);
	}
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
		{
			free(s);
			exit_func(m, 1);
		}
	}
	free(s);
}
