/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:59:39 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/12/13 12:57:54 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_hex(unsigned int num, char format);
int		ft_print_int(int n);
int		ft_print_ptr(void *ptr);
int		ft_print_str(char *str);
int		ft_print_uint(unsigned int num);
int		ft_print_char(char c);