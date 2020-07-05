/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:04:18 by rgero             #+#    #+#             */
/*   Updated: 2020/07/05 18:56:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	is_command(char *str)
{
	if (0 == ft_strcmp(str, "##start"))
		return (START);
	else if (0 == ft_strcmp(str, "##end"))
		return (START);
	return (0);
}

int	is_comment(char *str)
{
	if (0 == is_command && 0 )
}

