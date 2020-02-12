#include "libft.h"

int				ft_ishex(char *str)
{
	int		i;
	int		len_str;

	len_str = ft_strlen(str);
	if (len_str < 3 || len_str > 18)
		return (0);
	if (str[0] != '0' || str[1] != 'x')
		return (0);
	i = 1;
	while (++i < len_str)
	{
		if ('0' <= str[i] && str[i] <= '9')
			continue ;
		else if ('A' <= str[i] && str[i] <= 'F')
			continue ;
		else if ('a' <= str[i] && str[i] <= 'f')
			continue ;
		else
			return (0);
	}
	return (1);
}

int				ft_atoihex(char *str)
{
	int		res;
	int		i;
	int		len_str;

	res = 0;
	len_str = ft_strlen(str);
	if (len_str < 2)
		return (0);
	i = 1;
	while (++i < len_str)
	{
		if ('0' <= str[i] && str[i] <= '9')
			res = res * 16 + (str[i] - '0');
		else if ('A' <= str[i] && str[i] <= 'F')
			res = res * 16 + (10 + str[i] - 'A');
		else if ('a' <= str[i] && str[i] <= 'f')
			res = res * 16 + (10 + str[i] - 'a');
		else
			return (0);
	}
	return (res);
}
