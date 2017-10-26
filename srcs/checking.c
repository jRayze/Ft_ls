/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:14:11 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/13 11:56:09 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_tab_time(char **tab)
{
	int			i;
	int			tmp;
	t_sstat		filestat;
	long		date_1;
	long		date_2;

	i = 0;
	tmp = 0;
	while (tab[i] && tab[i + 1])
	{
		lstat(tab[i], &filestat);
		date_1 = filestat.st_mtime;
		lstat(tab[i + 1], &filestat);
		date_2 = filestat.st_mtime;
		tmp += date_1 < date_2 ? 1 : 0;
		i++;
	}
	return (tmp);
}

int		ft_check_tab(char **tab)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (tab[i] && tab[i + 1])
	{
		tmp += ft_strcmp(tab[i], tab[i + 1]) > 0 ? 1 : 0;
		i++;
	}
	return (tmp);
}

int		check(char **argv, int i, t_arg *args)
{
	int		cpt;
	t_sstat	filestat;

	cpt = 0;
	while (argv[i])
	{
		if (lstat(argv[i], &filestat) != -1)
		{
			if (ft_is_link(argv[i]) == 1 && args->arg_l == 1)
				cpt++;
			else if (ft_isdir(argv[i]) == 0)
				cpt++;
		}
		i++;
	}
	return (cpt);
}

int		chck_d(char **argv, int i, t_arg *args)
{
	int cpt;

	cpt = 0;
	while (argv[i])
	{
		if (ft_isdir(argv[i]) == 1)
			if ((ft_is_link(argv[i]) == 1 && args->arg_l == 0)
				|| ft_is_link(argv[i]) == 0)
				cpt++;
		i++;
	}
	return (cpt);
}

int		check_invalid(char **argv, int i)
{
	int				j;
	DIR				*dp;
	t_sstat			filestat;

	j = 0;
	dp = NULL;
	while (argv[i])
	{
		if (((dp = opendir(argv[i])) == NULL)
				&& lstat(argv[i], &filestat) == -1)
			j++;
		if (dp != NULL)
			closedir(dp);
		i++;
	}
	return (j);
}
