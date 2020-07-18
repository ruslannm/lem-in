/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 18:00:42 by rgero             #+#    #+#             */
/*   Updated: 2020/07/14 17:12:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_back(t_bfs *b, int i)
{
	b->queue[(b->front + b->len++) % Q_SIZE] = i;
}

int		pop_front(t_bfs *b)
{
	int v;

	v = b->queue[b->front];
	b->front = (b->front + 1) % Q_SIZE;
	--b->len;
	return (v);
}
