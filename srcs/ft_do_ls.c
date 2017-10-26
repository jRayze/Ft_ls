/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:55:07 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/15 14:08:34 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		*stock_flag(t_arg *args, char c)
{
	if (args->arg_l != 1)
		args->arg_l = ((c == 'l') ? 1 : 0);
	if (args->arg_rmaj != 1)
		args->arg_rmaj = ((c == 'R') ? 1 : 0);
	if (args->arg_a != 1)
		args->arg_a = ((c == 'a') ? 1 : 0);
	if (args->arg_rmin != 1)
		args->arg_rmin = ((c == 'r') ? 1 : 0);
	if (args->arg_t != 1)
		args->arg_t = ((c == 't') ? 1 : 0);
	if (args->arg_u != 1)
		args->arg_u = ((c == 'u') ? 1 : 0);
	if (args->arg_f != 1)
		args->arg_f = ((c == 'f') ? 1 : 0);
	if (args->arg_g != 1)
		args->arg_g = ((c == 'g') ? 1 : 0);
	if (args->arg_d != 1)
		args->arg_d = ((c == 'd') ? 1 : 0);
	return (args);
}

int			ft_pars_arg(char **av, t_arg *args)
{
	int i;
	int j;

	i = 0;
	while (av[++i] && (av[i][0] == '-' && (av[i][1] && av[i][1] != '-')))
	{
		j = 1;
		if (!(av[i][j]))
			return (print_no_file(av[i]));
		while (av[i][j])
		{
			if (av[i][j] == '-' && ((av[i][j + 1]) || j == 2))
				return (ft_error(av[i][j]));
			if (ft_search(VALID_ARG, av[i][j]) != 1 && av[i][j] != '-')
				return (ft_error(av[i][j]));
			args = stock_flag(args, av[i][j]);
			j++;
		}
	}
	i = (av[i] && ft_strcmp(av[i], "--") == 0) ? i + 1 : i;
	if (av[i] && av[i][0] == '-' && av[i][1] == '-' && ft_strlen(av[i]) > 2)
		return (ft_error('-'));
	if (av[i])
		return (ft_stock(av, args, i));
	return (0);
}
