/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 22:29:00 by rgero             #+#    #+#             */
/*   Updated: 2020/03/21 22:37:46 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#define MAX	100


long ft_bfs(int s, int t)
{
	int q[MAX];
	int qh;
	int qt;
	int d[MAX];
	int v;

	qh = 0;
	qt = 0;
	q[qt++] = s;

  	ft_memset(d, -1, sizeof(d));
	d[s] = 0;
	d[t] = 1000000;
	while (qh < qt)
	{
		v = q[qh++];
	    for (int to = 1; to <= n; to++)
	      if ((d[to] == -1) && Cap[v][to])
	      {
	        q[qt++] = to;
	        d[to] = d[v] + 1;
	      }
	  }

  return d[n] != -1;
}