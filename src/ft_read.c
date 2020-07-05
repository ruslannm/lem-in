/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:57:16 by rgero             #+#    #+#             */
/*   Updated: 2020/06/28 18:07:52 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_read(t_lemin *lemin)
{
	ft_read_ants(lemin);
	ft_read_vertices(lemin);
	ft_read_edges(lemin);
}