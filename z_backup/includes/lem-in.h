/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/06/28 21:05:55 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM-IN_H
# define LEM-IN_H

# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define START	1
# define MIDDLE	2
# define END	3

typedef struct
{
	int				fd;
	int 			error;
}					t_lemin;

typedef struct
{
	char* 			room;
	unsigned char	height;
	vertice*		left;
	vertice*		right;
}					vertice;

void 				set_error(t_lemin *lemin, char *str);
int					ft_clear(t_lemin *lemin);
unsigned char		get_height(vertice *node);
int 	bfactor(vertice *node);

#endif
