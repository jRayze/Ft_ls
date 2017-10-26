/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:10:28 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/15 14:08:27 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_wt_link(char *str)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(str);
	while (str[j] != '>')
		j--;
	j -= 3;
	while (i <= j)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_deb_stats(t_stat *stats, t_max *max)
{
	ft_putstr(stats->law);
	(stats->attrib != -1) ? ft_putchar('@') : ft_putchar(' ');
	ft_putchar(' ');
	ft_put_space_int(stats->under_files, max->lgt_uf);
	ft_putchar(' ');
	if (stats->creator)
		ft_put_space_str(stats->creator, max->lgt_crea);
	ft_putstr("  ");
	if (stats->groups)
		ft_put_space_str(stats->groups, max->lgt_grp);
	ft_putstr("  ");
}

void	if_p_spc(int p_spc, t_stat *stats, t_max *max, int i)
{
	if (stats->type == 3 || stats->type == 5)
	{
		ft_put_space_int(stats->minor, max->lgt_minor);
		ft_putstr(", ");
	}
	else
	{
		while (i <= (max->lgt_minor + 1))
		{
			ft_putchar(' ');
			i++;
		}
	}
	p_spc = 1;
}

void	ft_print_stats(t_stat *stats, t_arg *args, t_max *max)
{
	int i;

	i = 0;
	if (args->arg_l == 1)
	{
		print_deb_stats(stats, max);
		if (args->p_spc == 1)
			if_p_spc(args->p_spc, stats, max, i);
		ft_put_space_int(stats->size, max->lgt_size);
		ft_putchar(' ');
		print_date(stats->date, args->date, stats->time);
		ft_putchar(' ');
	}
	if (stats->type == 2 && args->arg_l == 0)
		print_wt_link(stats->file_name);
	else
		ft_putstr(stats->file_name);
	ft_putchar('\n');
	return ;
}

t_stat	*print_list(t_stat *list, t_arg *args, size_t total)
{
	t_max	*max;
	t_stat	*stmp;
	int		i;

	i = 0;
	max = NULL;
	if (!list)
		return (NULL);
	stmp = list;
	stmp = do_sort_lst(args, stmp, list, total);
	list = stmp;
	get_acl(stmp);
	if (args->arg_l != 0)
	{
		max = (t_max *)malloc(sizeof(t_max));
		max = get_space(stmp, max);
	}
	while (stmp)
	{
		ft_print_stats(stmp, args, max);
		stmp = stmp->next;
	}
	if (max)
		ft_memdel((void **)&max);
	return (list);
}
