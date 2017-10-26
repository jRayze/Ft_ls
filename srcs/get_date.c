/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:49:14 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/12 09:50:14 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compare_date(long timer, long date)
{
	int		res;
	long	i;

	i = 15768000;
	res = 0;
	if (((date - timer) > i) || (timer > date))
		res = 1;
	return (res);
}

void	print_segment(char *str, int beg, int end)
{
	while (str[beg] && beg <= end)
	{
		ft_putchar(str[beg]);
		beg++;
	}
}

void	print_date(char *str, long date, long timer)
{
	int i;
	int j;

	j = compare_date(timer, date);
	i = 4;
	if (j >= 1)
	{
		i = 4;
		print_segment(str, i, 10);
		i = 20;
		ft_putchar(' ');
		print_segment(str, i, 23);
	}
	else
	{
		i = 4;
		while (str[i + 9] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
