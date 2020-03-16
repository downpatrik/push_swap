/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:37:49 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/16 20:11:36 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <fcntl.h>
# define BUFF_SIZE 8

# ifndef MIN
#  define MIN(a, b) (((a)<(b))?(a):(b))
# endif
# ifndef MAX
#  define MAX(a, b) (((a)>(b))?(a):(b))
# endif

typedef unsigned char	t_u8;
typedef unsigned short	t_u16;
typedef unsigned int	t_u32;
typedef unsigned long	t_u64;
typedef signed char		t_i8;
typedef signed short	t_i16;
typedef signed int		t_i32;
typedef signed long		t_i64;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isxdigit(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_islower(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);

int						ft_pow(int nb, int power);
int						ft_abs(int c);

void					ft_bzero(void *s, size_t n);

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t count);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memrcpy(void *dest, const void *src, size_t n);

int						ft_atoi(const char *str);
double					ft_atof(const char *str);

char					*ft_itoa(int n);

size_t					ft_strlen(const char *c);
size_t					ft_strnlen(const char *str, size_t size);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t nb);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strnstr(const char *str,
							const char *to_find, size_t nb);
char					*ft_strstr(const char *str, const char *to_find);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strdup(const char *s);
void					ft_strdel(char **as);
void					ft_strclr(char *s);

void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
char					*ft_strrev(char *str);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(t_u32 i, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)(t_u32 j, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, t_u32 start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int						ft_free_array(char **array, int ret_val);

int						get_next_line(const int fd, char **line);

#endif
