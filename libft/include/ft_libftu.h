/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:09:52 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 17:09:09 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTU_H
# define FT_LIBFTU_H

/*
**-------Standart libraries
*/
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>

/*
**-------My defines
*/
# define MAX(a, b) (intmax_t)a > (intmax_t)b ? a : b
# define FT_ABS(a) (intmax_t)a >= 0 ? a : -a
# define PF_SHARP		(1 << 0)
# define PF_SPACE		(1 << 1)
# define PF_PLUS		(1 << 2)
# define PF_MINUS		(1 << 3)
# define PF_ZERO		(1 << 4)
# define PF_H			(1 << 5)
# define PF_HH			(1 << 6)
# define PF_L			(1 << 7)
# define PF_LL			(1 << 8)
# define PF_J			(1 << 9)
# define PF_Z			(1 << 10)
# define PF_GOT_ML		(1 << 11)
# define PF_GOT_PRECI	(1 << 12)
# define PF_BUF			32
# define BUFF_SIZE		1024

/*
**-------Structures
*/
typedef struct			s_mylist
{
	int					fd;
	char				*str;
	struct s_mylist		*next;
}						t_mylist;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_printf
{
	int					ml;
	int					prec;
	short				t;
	int					base;
	uintmax_t			c;
}						t_printf;
typedef struct			s_pf
{
	va_list				ar;
	char				res[PF_BUF];
	int					ret;
	int					i;
	int					cb;
}						t_pf;
/*
**-------The main function
*/
int						ft_printf(const char *format, ...);
/*
**-------Getting the options functions
*/
char					*pf_flags(char **format, t_printf *arg);
char					*pf_min_len(char **format,
										t_pf *pf, t_printf *arg);
char					*pf_precision(char **format,
									t_pf *pf, t_printf *arg);
char					*pf_length(char **format, t_printf *arg);
/*
**-------Output functions
*/
void					pf_putescape(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putstr(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putwstr(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putchar(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putwchar(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putnull(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putfloat(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putint(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putuint(uintmax_t nbr, t_printf *arg,
										char *prefix, t_pf *pf);
void					pf_puthex(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putoct(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putptr(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putu(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putlong(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putbinary(char **format,
										t_pf *pf, t_printf *arg);
void					pf_putprinted(char **format,
										t_pf *pf, t_printf *arg);
/*
**-------Additional functions
*/
size_t					ft_strnlen(const char *str, size_t maxlen);
intmax_t				get_signed(va_list *args, t_printf *arg);
uintmax_t				ft_get_unsigned(va_list *args, t_printf *arg);
void					ft_putwchar(wchar_t chr, t_pf *pf);
size_t					ft_wstrlen(wchar_t *str);
size_t					pf_wstrlen(wchar_t *str, int prec, size_t i);
size_t					ft_nbrlen(uintmax_t nbr, int base);
size_t					pf_nbrlen(uintmax_t nbr,
											char *p, t_printf *arg);
void					ft_putnwstr(const wchar_t *str,
											size_t len, t_pf *pf);
void					pf_putpad(t_pf *pf, int strlen, int width, char c);
void					pf_buffer(char *str, int size, int print, t_pf *pf);
void					ft_char_cases(char **format, t_pf *pf, t_printf *sarg);
void					ft_num_cases(char **format, t_pf *pf, t_printf *sarg);
void					ft_other_cases(char **format, t_pf *pf, t_printf *sarg);
void					ft_putnbrbase(uintmax_t nbr, int base,
													t_pf *pf, t_printf *arg);
void					pf_put_nb_with_prefix(uintmax_t nbr,
										t_printf *arg, char *prefix, t_pf *pf);
void					pf_putnbr(uintmax_t nbr, t_printf *arg,
												unsigned nbr_len, t_pf *pf);
/*
**-------Libft
*/
int						ft_atoi(const char *str);
char					*ft_strcat(char *dest, char *src);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strcpy(char *dest, char *src);
char					*ft_strdup(char *src);
unsigned int			ft_strlcat(char *dest, char *src, unsigned int size);
size_t					ft_strlen(const char *str);
char					*ft_strncat(char *dest, char *src, int n);
int						ft_strncmp(char *s1, char *s2, unsigned int n);
char					*ft_strncpy(char *dest, const char *src,
														unsigned int n);
char					*ft_strstr(const char *str, const char *to_find);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
int						ft_isprint(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
char					*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char					*ft_strrchr(const char *s, int c);
char					*ft_strchr(const char *s, int c);
void					*ft_memcpy(void *dst, const void *src,
															size_t n);
void					*ft_memccpy(void *dst, const void *src,
													int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *memptr1,
						const void *memptr2, size_t num);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s,
									void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,
											unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
										void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *n);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_swap(int *a, int *b);
char					*ft_strrev(char *str);
int						ft_factorial(int nb);
int						ft_pow(int nb, int power);
int						ft_sqrt(int nb);
char					*ft_strcapitalize(char *str);
char					*ft_rotn(char *str, int n);
int						ft_lstsize(t_list *begin_list);
void					ft_lstaddend(t_list **alst, t_list *n);
void					ft_lstshift(t_list **alst);
char					**ft_strsplit(char const *s, char c);
void					ft_freearr(char **arr, size_t wrdcnt);
/*
**-------GNL
*/
int						get_next_line(const int fd, char **line);
#endif
