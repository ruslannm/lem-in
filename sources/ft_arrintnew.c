/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrintnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:25:01 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 05:58:48 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	*ft_arrintnew(size_t size)
{
	int		*new;
	size_t	i;

	if (size + 1 <= size)
		return (NULL);
	new = (int *)malloc(sizeof(int) * size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		new[i++] = 0;
	return (new);
}
