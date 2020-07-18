/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/16 20:18:36 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*join_str(char *s1, char *s2, int clean)
{
	char *new_s;

	if (s1[0] == 0)
	{
		free(s1);
		return (ft_strdup(s2));
	}
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	new_s = ft_strcat(new_s, s1);
	new_s = ft_strcat(new_s, "\n");
	new_s = ft_strcat(new_s, s2);
	ft_strdel(&s1);
	if (clean)
		ft_strdel(&s2);
	return (new_s);
}
