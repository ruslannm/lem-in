/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:12:28 by rgero             #+#    #+#             */
/*   Updated: 2019/09/13 17:12:01 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (!(ft_strchr(s, c)))
		return (NULL);
	while (*s)
		s++;
	while (*s != c)
		s--;
	return ((char *)s);
}