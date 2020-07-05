/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:06:19 by rgero             #+#    #+#             */
/*   Updated: 2020/07/05 18:56:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static unsigned char	height(vertice *node)
{
	return (node ? node->height : 0);
}

int 	bfactor(vertice *node)
{
	return (height(node->right) - height(node->left));
}

unsigned char 	get_height(vertice *node)
{
	unsigned char hl = height(node->left);
	unsigned char hr = height(node->right);
	return ((hl > hr ? hl : hr) + 1);
}
