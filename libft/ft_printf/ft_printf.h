/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:04:46 by apoque            #+#    #+#             */
/*   Updated: 2018/08/23 15:52:08 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define F p->format[p->idx2]

# define POUND 0
# define ZERO 1
# define MORE 2
# define LESS 3
# define SPACE 4

# define HH 0
# define H 1
# define LL 2
# define L 3
# define J 4
# define Z 5

typedef struct			s_printf
{
	va_list				ap;
	const char			*format;
	char				*buf;
	char				modif[6];
	char				flag[5];
	int					idx1;
	int					idx2;
	int					len;
	int					txt;
	int					error;
	int					dot;
	int					precision;
	int					size;
}						t_printf;

int						ft_printf(const char *format, ...);
void					ft_buf(t_printf *p);
void					ft_percent(t_printf *p);
void					ft_int(t_printf *p);
void					ft_p(t_printf *p);
void					ft_long(t_printf *p);
void					ft_uint(t_printf *p);
void					ft_umajint(t_printf *p);
void					ft_oint(t_printf *p);
void					ft_omajint(t_printf *p);
void					ft_xint(t_printf *p);
void					ft_xmajint(t_printf *p);
void					ft_str(t_printf *p);
void					ft_wstr(t_printf *p);
void					ft_char(t_printf *p);
void					ft_wchar(t_printf *p);
void					ft_treatment2(t_printf *p);
int						ft_opt(t_printf *p);
void					ft_opt_modif(t_printf *p);
void					ft_opt_precision_size(t_printf *p);
void					ft_init_options(t_printf *p);
void					ft_put_space(t_printf *p, int flag);
void					ft_put_precision(t_printf *p, int zeros);
void					ft_conv_wchar(t_printf *p, wchar_t c, char *str);
void					ft_print_x2(t_printf *p, unsigned long u, int zeros);
int						ft_wchar_len(wchar_t c);
int						ft_wstrlen(wchar_t *str);
int						ft_get_a(wchar_t c);
int						ft_char_size(int a, int nb);
void					ft_text_parser(t_printf *p);
void					ft_print_buf(t_printf *p);
void					ft_txt(t_printf *p);
void					ft_is_option(t_printf *p);
void					ft_opt_flag(t_printf *p);
void					ft_treatment(t_printf *p);
void					ft_print_percent(t_printf *p);
void					ft_bint(t_printf *p);
void					ft_bmajint(t_printf *p);

char					*ft_strdup(char *str);
char					*ft_strnew(int len);
int						ft_strlen(char *str);
int						ft_isdigit(int c);
int						ft_atoi(char *str);
char					*ft_itoa(intmax_t nb);
char					*ft_uitoa(unsigned int nb);
char					*ft_uitoabase(unsigned int nb, int base);
char					*ft_itoabase_u(uintmax_t nb, char *str);
char					*ft_ltoa(long int nb);
char					*ft_litoabase(long int nb, int base);
void					ft_putstr(char *str);
void					ft_putchar(int c);
void					ft_putwchar(wchar_t c);
char					ft_toupper(int c);
void					ft_bzero(void *s, int n);
char					*ft_strndup(const char *src, int n);
char					*ft_strjoin(const char *s1, const char *s2);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strrev(char *str);
char					*ft_strjoinfree(char *to_free, const char *s2);
char					*ft_strndupfree(char *to_free, int n);
int						ft_int_strstr(const char *src, const char *find);
int						ft_int_strchar(const char *src, const char find);
#endif
