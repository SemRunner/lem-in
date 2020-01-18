/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:18:13 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 13:57:50 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f_check_space(char c, char split_c)
{
	return (c == split_c ? 1 : 0);
}

static size_t	f_word_count(char *str, char split_c)
{
	size_t i;
	size_t w_count;

	i = 0;
	w_count = 0;
	while (str[i] != '\0')
	{
		if (!f_check_space(str[i], split_c))
		{
			while (str[i] != '\0' && (!f_check_space(str[i], split_c)))
				i++;
			w_count++;
		}
		else
			i++;
	}
	return (w_count);
}

static size_t	f_word_len_count(char *str, size_t pos, char split_c)
{
	size_t word_len;

	word_len = 0;
	while (str[pos] && !f_check_space(str[pos], split_c))
	{
		word_len++;
		pos++;
	}
	return (word_len);
}

static int		f_put_words(char **result, char *str, char split_c,
							size_t *w_ind)
{
	size_t j;
	size_t word_len;

	while (*str != '\0')
		if (f_check_space(*str, split_c))
			str++;
		else
		{
			word_len = f_word_len_count(str, 0, split_c);
			if (word_len > 0)
			{
				if (!(result[*w_ind] = malloc(sizeof(char) * (word_len + 1))))
					return (0);
				j = 0;
				while (j < word_len)
				{
					result[*w_ind][j] = *(str++);
					j++;
				}
				result[*w_ind][j] = '\0';
				(*w_ind)++;
			}
		}
	result[*w_ind] = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	word_cnt;
	size_t	i;
	int		res_put_words;

	if (!s)
		return (NULL);
	word_cnt = f_word_count((char*)s, c);
	if (!(result = (char**)malloc(sizeof(char*) * (word_cnt + 1))))
		return (NULL);
	word_cnt = 0;
	res_put_words = f_put_words(result, (char*)s, c, &word_cnt);
	if (res_put_words == 0)
	{
		i = 0;
		while (i < word_cnt)
		{
			ft_memdel((void**)(result[i]));
			i++;
		}
		free(result);
		return (NULL);
	}
	return (result);
}
