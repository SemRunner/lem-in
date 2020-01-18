/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:59:45 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/28 19:48:31 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include "terminal_draw.h"

# define BUFF_SIZE 128

# define NO_DEFINE -2147483648

# define ABS(value) (((value) < 0) ? ((value) * (-1)) : (value))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dict
{
	void			*content;
	size_t			content_size;
	int				key;
	struct s_dict	*next;
	struct s_dict	*prev;
}					t_dict;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_queue
{
	int				len;
	t_dlist			*top;
	t_dlist			*bottom;
}					t_queue;

/*
** memory management
*/

void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t size);
void				ft_memdel(void **ap);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, void *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list*(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
void				ft_lstaddback(t_list *alst, t_list *new);
t_list				*ft_lsti(t_list *alst, size_t nbr);
void				ft_lstdeli(t_list **alst, size_t nbr, void (*del)(void *,
								size_t));
void				ft_printstrsplit(char **tab);
void				*ft_strnjoin(char **s1, const char *s2, size_t n);

/*
** dictionary
*/

t_dict				*ft_dictnew(void const *content, size_t content_size,
								int key);
void				ft_dictadd(t_dict **adict, t_dict *new);
t_dict				*ft_dictgetoraddvalue(t_dict **dict, int key);
void				ft_dictclearzero(t_dict **dict);
void				ft_dictdelelement(t_dict **dict, t_dict **element,
									void (*del)(void *, size_t));
t_dict				*ft_dictgetvalue(t_dict *dict, int key);
void				ft_dictdelbykey(t_dict **dict, int key,
									void (*del)(void *, size_t));

int					get_next_line(const int fd, char **line);
const char			*ft_skip_digits(const char *str);
char				*ft_zerostr(void);
void				ft_free(void *data, size_t size);
void				ft_getsnbr_base(long long int nbr,
									char *base, char *output);
void				ft_getunbr_base(unsigned long long int nbr,
										char *base, char *output);
int					ft_pow(int n, int pow);
t_list				*ft_lstfind(t_list *head, void *search_d,
							int (*f)(void *, void *));
void				ft_strset(char *str, char c, int len);
int					ft_nbrlen(long int a);
int					ft_printf(const char *format, ...);
void				ft_del_strsplit(char ***strings);
int					ft_isint(char *str);
int					ft_intlen(int a);

/*
** matrix
*/

void				ft_print_intmatrix(int **matrix,
						int num_of_lines, int num_of_cols);
void				ft_delmatrix(void ***matrix, int num_of_lines);

/*
** dlist
*/

t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
void				ft_dlst_addback(t_dlist **alst, t_dlist *new);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				*ft_dlst_addcontent_back(t_dlist **list, void *content,
											size_t content_size);
void				*ft_dlst_addcontent(t_dlist **list, void *content,
										size_t content_size);
int					ft_dlst_len(t_dlist *lst);

/*
** int content
*/

void				del_intcontent(void *content, size_t size);
int					int_content(t_dlist *list);

/*
** queue
** qi - queue with integer values
*/

void				queue_init(t_queue *queue);
void				qi_del(t_queue *queue);
void				*qi_push(t_queue *queue, int value);
int					qi_pop(t_queue *queue);
int					qi_front(t_queue *queue);
int					qi_back(t_queue *queue);
int					qi_empty(t_queue *queue);
void				qi_print(t_queue *q);

/*
** max, min of array of int
*/

int					ft_max_intarray(int *arr, int size);
int					ft_min_intarray(int *arr, int size);

/*
** vector int
*/

void				vector_int_assign(int *vector, int len, int value);
void				vector_int_print(int *vector, int len, int fd);

/*
** sorting
*/

void				ft_sort_bubble(void **array, int len, int (*cmp)());
void				ft_sort_quick(void **array, int first, int last,
									int (*cmp)());

#endif
