/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfloat_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:56:08 by lnickole          #+#    #+#             */
/*   Updated: 2020/02/08 14:56:09 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "put_padding.h"

int			get_size(long nbr)
{
	int size;

	size = 0;
	if (nbr == 0)
		size++;
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

long double	power(long double nb, int power)
{
	long double tmp;

	tmp = nb;
	if (power == 0)
		return (1);
	if (power < 1)
		return (0);
	while (--power)
		nb *= tmp;
	return (nb);
}

char		*pf_strnew(int size, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
	{
		data->ret = -1;
		return (NULL);
	}
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

void		rev_str(char *str, int len)
{
	int		i;
	int		len_tmp;
	char	tmp;

	i = 0;
	len_tmp = len;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	str[len_tmp] = '\0';
}

void		pf_strdel(char **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}
