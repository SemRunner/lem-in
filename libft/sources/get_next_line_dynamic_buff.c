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

static int	crash_f(char **str1, char **str2, t_dict **files, t_dict **file)
{
	if (str1 != NULL)
		ft_memdel((void**)str1);
	if (str2 != NULL)
		ft_memdel((void**)str2);
	if (files != NULL)
		ft_dictdelelement(files, file, NULL);
	return (-1);
}

static int	return_ok(int ok, char **str1, t_dict **files, t_dict **file)
{
	if (str1 != NULL)
		ft_memdel((void**)str1);
	if (files != NULL)
		if ((*file)->content == NULL)
			ft_dictdelelement(files, file, NULL);
	return (ok);
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
	char	*buff;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((read_count = read(fd, buff, BUFF_SIZE)))
	{
		if (read_count < 0)
			return (crash_f(&buff, NULL, NULL, NULL));
		buff[read_count] = '\0';
		if ((chr_n = ft_strnstr(buff, "\n", read_count)))
		{
			if (!(*line = ft_strnjoin(line, buff, (int)(chr_n - buff))))
				return (crash_f(&buff, NULL, NULL, NULL));
			if (read_count != (chr_n - buff + 1))
				if (!(*str = ft_strnjoin(str, chr_n + 1,
						read_count - (chr_n - buff + 1))))
					return (crash_f(&buff, NULL, NULL, NULL));
			return (return_ok(1, &buff, NULL, NULL));
		}
		else if (!(*line = ft_strnjoin(line, buff, read_count)))
			return (crash_f(&buff, NULL, NULL, NULL));
	}
	return (return_ok(0, &buff, NULL, NULL));
}

int			get_next_line_dyn(const int fd, char **line)
{
	static t_dict		*files;
	t_dict				*file;
	int					read_count;

	if (line == NULL)
		return (-1);
	if (!(file = ft_dictgetoraddvalue(&files, fd)))
		return (-1);
	if (!(*line = (char*)ft_memalloc(1)))
		return (crash_f(NULL, NULL, &files, &file));
	if (file->content != NULL)
	{
		read_count = str_is_not_null((char**)&(file->content), line);
		if (read_count == 0)
			return (crash_f((char**)&(file->content), line, NULL, NULL));
		else if (read_count == 1)
			return (return_ok(1, NULL, &files, &file));
	}
	read_count = readfile(fd, line, (char**)&(file->content));
	if (read_count == -1)
		return (crash_f((char**)&(file->content), line, &files, &file));
	else if (read_count == 1 || ft_strlen(*line) != 0)
		return (return_ok(1, NULL, &files, &file));
	return (return_ok(0, NULL, &files, &file));
}
