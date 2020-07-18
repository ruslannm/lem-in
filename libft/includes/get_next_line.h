/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:20:52 by lnickole          #+#    #+#             */
/*   Updated: 2019/09/01 20:22:12 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif
