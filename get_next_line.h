/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:24:48 by dshumba           #+#    #+#             */
/*   Updated: 2018/06/11 12:32:01 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9999

# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"

# define MAX_FD 1024 + 2
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

int             get_next_line(const int fd, char **line);

#endif
