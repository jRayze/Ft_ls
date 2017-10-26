/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:53:05 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/12 10:06:30 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_unsigned_long(unsigned long n)
{
	if (n > 9 && n <= 4294967295)
		ft_print_unsigned_long(n / 10);
	ft_putchar(n % 10 + '0');
}
