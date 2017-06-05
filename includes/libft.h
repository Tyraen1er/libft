/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:21:24 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/05 21:50:43 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_quad
{
	t_point			tl;
	t_point			br;
}					t_quad;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_realloc(void *str, int len_str,
		int add_bytes, int reading_speed);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_power(int a, int b);
int					ft_root(int a, int b);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char*, void (*f)(char*));
void				ft_striteri(char*, void (*f)(unsigned int, char *));
char				*ft_strmap(char const*, char (*f)(char));
char				*ft_strmapi(char const*, char (*f)(unsigned int, char));
int					ft_strequ(char const*, char const*);
int					ft_strnequ(char const*, char const*, size_t);
char				*ft_strsub(char const*, unsigned int, size_t);
char				*ft_strjoin(char const*, char const*);
char				*ft_strtrim(char const*);
char				**ft_strsplit(char const*, char);
char				*ft_itoa(int);
void				ft_putchar(char);
void				ft_putstr(char const*);
void				ft_putendl(char const*);
void				ft_putnbr(int);
void				ft_putchar_fd(char, int);
void				ft_putstr_fd(char const*, int);
void				ft_putendl_fd(char const*, int);
void				ft_putnbr_fd(int, int);
t_list				*ft_lstnew(void const*, size_t);
void				ft_lstdelone(t_list**, void (*del)(void*, size_t));
void				ft_lstdel(t_list**, void (*del)(void*, size_t));
void				ft_lstadd(t_list**, t_list*);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list*, t_list *(*f)(t_list *elem));
int					ft_isletter(char);
t_point				ft_point_in_quad_to_ratio(t_quad, t_point);
t_point				ft_point_ratio_to_quad(t_point, t_quad);
t_quad				ft_create_quad(t_point, t_point);
t_point				ft_point_change_quad(t_point, t_quad, t_quad);

#endif
