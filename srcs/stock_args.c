/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:43:28 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/15 14:08:30 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			malloc_tabs(t_arg *args, char **av, int i)
{
	if (check(av, i, args) > 0)
		args->file = (char **)malloc(sizeof(char *) * (check(av, i, args) + 1));
	if (chck_d(av, i, args) > 0)
		args->arg = (char **)malloc(sizeof(char *) * (chck_d(av, i, args) + 1));
	if (check(av, i, args) == 0 && chck_d(av, i, args) == 0)
		return (1);
	return (0);
}

int			end_stock(size_t *nb, char **inval, t_arg *args)
{
	if (nb[0] > 0)
	{
		inval[nb[0]] = NULL;
		inval = print_invalid(inval, nb[0]);
		free_tab_double(inval);
	}
	if (nb[2] > 0)
		args->arg[nb[2]] = NULL;
	if (nb[1] > 0)
		args->file[nb[1]] = NULL;
	if (nb[0] > 0)
	{
		if (nb[1] == 0 && nb[2] == 0)
			return (-1);
	}
	return (0);
}

void		do_stock(char **inval, char *argv, t_arg *args, size_t *nb)
{
	DIR				*dp;
	t_sstat			filestat;

	dp = NULL;
	if (((dp = opendir(argv)) == NULL)
			&& lstat(argv, &filestat) == -1)
	{
		inval[nb[0]] = ft_strdup(argv);
		args->i = 1;
		nb[0]++;
	}
	else
		stock_by_type(argv, args, nb);
	if (dp != NULL)
		closedir(dp);
}

void		stock_by_type(char *argv, t_arg *args, size_t *nb)
{
	if ((ft_is_link(argv) && args->arg_l)
			|| ft_isdir(argv) == 0)
	{
		args->file[nb[1]] = ft_strdup(argv);
		nb[1]++;
	}
	else if (ft_isdir(argv) == 1)
	{
		if ((ft_is_link(argv) == 1 && args->arg_l == 0)
				|| ft_is_link(argv) == 0)
		{
			args->arg[nb[2]] = ft_strdup(argv);
			nb[2]++;
		}
	}
}

int			ft_stock(char **argv, t_arg *args, int i)
{
	size_t			nb[3];
	char			**inval;

	nb[0] = 0;
	nb[1] = 0;
	nb[2] = 0;
	inval = NULL;
	if (check_invalid(argv, i) > 0)
		inval = (char **)malloc(sizeof(char *) * (check_invalid(argv, i) + 1));
	if (malloc_tabs(args, argv, i) == 1 && check_invalid(argv, i) == 0)
		return (0);
	while (argv[i] && (i > 0))
	{
		do_stock(inval, argv[i], args, nb);
		i++;
	}
	return (end_stock(nb, inval, args));
}
