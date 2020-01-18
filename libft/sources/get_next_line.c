/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:54:55 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 21:12:23 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	crash_f(char **str1, char **str2)
{
	if (str1 != NULL)
		ft_memdel((void**)str1);
	if (str2 != NULL)
		ft_memdel((void**)str2);
	return (-1);
}

static int	str_is_not_null(char **str, char **line)
{
	char *chr_n;
	char *ptr;

	if ((chr_n = ft_strnstr(*str, "\n", ft_strlen(*str))))
	{
		if (!(*line = ft_strnjoin(line, *str, (size_t)(chr_n - *str))))
			return (0);
		if (ft_strlen(*str) == (size_t)(chr_n - *str + 1))
			ft_memdel((void**)str);
		else
		{
			if (!(ptr = ft_strdup(chr_n + 1)))
				return (0);
			ft_memdel((void**)str);
			*str = ptr;
		}
		return (1);
	}
	else
	{
		if (!(*line = ft_strnjoin(line, *str, ft_strlen(*str))))
			return (0);
		ft_memdel((void**)str);
	}
	return (2);
}

static int	readfile(const int fd, char **line, char **str)
{
	int		read_count;
	char	*chr_n;
	char	buff[BUFF_SIZE + 1];

	while ((read_count = read(fd, buff, BUFF_SIZE)))
	{
		if (read_count < 0)
			return (crash_f(NULL, NULL));
		buff[read_count] = '\0';
		if ((chr_n = ft_strnstr(buff, "\n", read_count)))
		{
			if (!(*line = ft_strnjoin(line, buff, (int)(chr_n - buff))))
				return (crash_f(NULL, NULL));
			if (read_count != (chr_n - buff + 1))
				if (!(*str = ft_strnjoin(str, chr_n + 1,
						read_count - (chr_n - buff + 1))))
					return (crash_f(NULL, NULL));
			return (1);
		}
		else if (!(*line = ft_strnjoin(line, buff, read_count)))
			return (crash_f(NULL, NULL));
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char			*files[1024];
	int					res;

	if (line == NULL)
		return (-1);
	if (!(*line = (char*)ft_memalloc(1)))
		return (crash_f(&files[fd], NULL));
	if (files[fd] != NULL)
	{
		res = str_is_not_null((char**)&(files[fd]), line);
		if (res == 0)
			return (crash_f((char**)&(files[fd]), line));
		else if (res == 1)
			return (1);
	}
	res = readfile(fd, line, (char**)&(files[fd]));
	if (res == -1)
		return (crash_f((char**)&(files[fd]), line));
	else if (res == 1 || ft_strlen(*line) != 0)
		return (1);
	return (0);
}
