/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 22:26:42 by rgero             #+#    #+#             */
/*   Updated: 2020/06/28 21:06:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void set_error(t_lemin *lemin, char *str)
{
	lemin->error = 1;
	ft_printf("ERROR: %s\n", str);
}

int	ft_clear(t_lemin *lemin)
{
	//TODO free()	
	return (lemin->error);
}

int main(void)
{
	t_lemin lemin;
	int fd;

	ft_bzero(&lemin, sizeof(t_lemin)); 
	fd = 0; //open("map.txt", O_RDONLY);
	lemin.fd = fd;
	ft_read(&lemin);
	return (0);
}