#include "get_next_line.h"

static char  *readline(const int fd, char *buff int *ret)
{
	char 	temp[BUFF_SIZE + 1];
	char	temp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	temp[*ret] = '\0';
	temp2 = buff;
	if (!(buff = ft_strjoin(buff, temp)))
		return (NULL);
	ft_strdel(&temp2);
	return(buff);	
}

int		put@line(char **put, char **line)
{
	int len;

	if (ft_strchr(*put, '\n') != NULL)
	{
		len = ft_strchr(*put, '\n') - *put;
		line[0] = ft_strsub(*put, 0, len);
		*put = ft_strchr(*put. '\n') + 1;
		return (1);
	}
	line[0] = ft_strdup(*put);
	*put = NULL;
	return (0);
}

int get_next_line(const int fd, char **line)
{
	int 		ret;
	static char *put = NULL;
	char		*str;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	line[0] = ft_strnew(BUFF_SIZE);
	if (put != NULL)
		if (put@line(&put, &line))
		return (1);
	str = ft_strnew(BUFF_SIZE);
	if (ret = readline(&line[0], fd, &put, str)) == -1)
		return (-1);
	free(str);
	if (ret == 0 && ft_strlen(line[0]) == 0)
		return (0);
	return (1);
}
