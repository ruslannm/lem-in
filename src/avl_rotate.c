/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:14:43 by rgero             #+#    #+#             */
/*   Updated: 2020/07/05 18:56:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

vertice *rotate_right(vertice *p)
{
	vertice *q;

	q = p->left;
	p->left = q->right;
	q->right = p;
	p->height = height_new(p);
	q->height = height_new(q);
	return (q);
}

vertice *rotate_left(vertice *q)
{
	vertice *p;

	p = q->right;
	q->right = p->left;
	p->left = q;
	q->height = height_new(q);
	p->height = height_new(p);
	return (p);
}

vertice *balance(vertice *p)
{
	p->height = get_height(p);	// check line or delete
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotate_right(p->right);
		return (rotate_left(p));
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotate_left(p->left);
		return (rotate_rigth(p));
	}
	return (p);
}

vertice	*create_vertice(char *str)
{
	char	**split;
	vertice	*ret;

	split = ft_strsplit(str, ' ');
	
	vert = (t_vert *)ft_memalloc(sizeof(t_vert));
	vert->name = ft_strdup(split[0]);
	vert->number = number;
	vert->x = ft_atoi(split[1]);
	vert->y = ft_atoi(split[2]);
	vert->len = INT_MAX;
	vert->next = NULL;
	ft_free_split_array(split);
	return (vert);
}



vertice	*insert(t_lemin *lemin, vertice *p, char *str, int )
{
	vertice	*new;

	if (!p)
	{
		if (!(new = (t_lemin *)malloc(sizeof(t_lemin))))
			set_error(lemin, "not enough memmory");
		if (lemin->error)
			return (NULL);
		if (!(p->room == ft_strdup(str)))
		{
			free (new);
			set_error(lemin, "not enough memmory");
			return (NULL);
		}
		return (new);
	}
	if (0 == ft_strcmp(p->room, str))
	{
		set_error(lemin, "room dublicates");
		return (NULL);
	}
	if (ft_strcmp < p->room)
		p->left = 
}