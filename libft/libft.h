/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:05:07 by epfennig          #+#    #+#             */
/*   Updated: 2021/05/13 15:28:49 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_putchar(int c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
char				*ft_strcat(char *dest, char *src);
char				*ft_strcpy(char *dest, char *src);
int					ft_toupper(int c);
int					ft_tolower(int c);
unsigned int		ft_strlen(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);

int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_strdup(char *src);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
