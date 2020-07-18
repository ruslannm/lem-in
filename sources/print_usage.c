/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:46:34 by rgero             #+#    #+#             */
/*   Updated: 2020/07/18 18:42:40 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_usage(void)
{
	ft_printf("usage: ./lem-in [option]\n options:\n");
	ft_printf("          --help  : to read the manual\n");
	ft_printf("          --color : print colored paths\n");
	ft_printf("          -c      : print colored paths\n");
}
