/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:21:46 by dshumba           #+#    #+#             */
/*   Updated: 2018/06/08 12:04:16 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		put2line(char **put, char **line)
{
	int len;

	if (ft_strchr(*put, '\n') != NULL)
	{
		len = ft_strchr(*put, '\n') - *put;
		line[0] = ft_strsub(*put, 0, len);
		*put = ft_strchr(*put, '\n') + 1;
		return (1);
	}
	line[0] = ft_strdup(*put);
	*put = NULL;
	return (0);
}

int			read_f(char **line, const int fd, char **stock, char *str)
{
	char	*tmp;
	int		len;
	int		ret;

	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		str[ret] = '\0';
		tmp = ft_strdup(line[0]);
		free(line[0]);
		line[0] = ft_strjoin(tmp, str);
		free(tmp);
		if (ft_strchr(line[0], '\n'))
		{
			len = ft_strchr(line[0], '\n') - line[0];
			*stock = ft_strdup(ft_strchr(line[0], '\n') + 1);
			tmp = ft_strdup(line[0]);
			free(line[0]);
			line[0] = ft_strsub(tmp, 0, len);
			free(tmp);
			break ;
		}
	}
	return (ret);
}

int					get_next_line(const int fd, char **line)
{	
	int				ret;
	static char		*stock = NULL;
	char			*str;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	line[0] = ft_strnew(BUFF_SIZE);
	if (stock != NULL)
		if (put2line(&stock, &line[0]))
			return (1);
	str = ft_strnew(BUFF_SIZE);
	if ((ret = read_f(&line[0], fd, &stock, str)) == -1)
		return (-1);
	free(str);
	if (ret == 0 && ft_strlen(line[0]) == 0)
		return (0);
	return (1);

