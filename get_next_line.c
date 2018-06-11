/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:21:46 by dshumba           #+#    #+#             */
/*   Updated: 2018/06/11 12:40:00 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int			check_line(char **book, char **line)
{
	char			*page_book;
	char			*find_eof;
	int				i;

	i = 0;
	find_eof = *book;
	while (find_eof[i] != '\n')
		if (!find_eof[i++])
			return (0);
	page_book = &find_eof[i];
	*page_book = '\0';
	*line = ft_strdup(*book);
	*book = ft_strdup(page_book);
	return (1);
}

static int			read_file(int fd, char *page, char **book, char **line)
{
	int				ret;
	char 			*page_book;

	while ((ret = read(fd, page, BUFF_SIZE)) > 0)
	{
		page[ret] = '\0';
		if (*book)
		{
			page_book = *book;
			*book = ft_strjoin(page_book, page);
			free(page_book);
			page_book = NULL;
		}
		else
			*book = ft_strdup(page);
		if (check_line(book, line))
			break ;
	}
	return (RET_VALUE(ret));
}

int					get_next_line(int const fd, char **line)
{
	static char 	*book[MAX_FD];
	char			*page;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, book[fd], 0) < 0) \
		|| !(page = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (book[fd])
		if (check_line(&book[fd], line))
			return (1);
	i = 0;
	while ( i < BUFF_SIZE)
		page[i++] = '\0';
	ret = read_file(fd, page, &book[fd], line);
	free(page);
	if (ret != 0 || book[fd] == NULL || book[fd][0] == '\0')
	{
		if(!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = book[fd];
	book[fd] = NULL;
	return (1);
}
