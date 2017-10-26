/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:06:21 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/15 14:08:32 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_next(t_stat *tmpcur, t_stat *list, t_stat *tmpprev)
{
	t_stat *tmp2;

	tmp2 = NULL;
	if (tmpcur != list)
	{
		tmpprev->next = list;
		tmp2 = list->next;
		list->next = tmpcur->next;
		tmpcur->next = tmp2;
	}
}

t_stat	*sort_list(t_stat *list)
{
	t_stat	*current;
	t_stat	*tmpcur;
	t_stat	*prev;
	t_stat	*tmpprev;

	if (!list || !list->next)
		return (list);
	current = list;
	tmpcur = list->next;
	prev = list;
	tmpprev = list;
	while (current != NULL)
	{
		if (ft_strcmp(current->file_name, tmpcur->file_name) < 0)
		{
			tmpcur = current;
			tmpprev = prev;
		}
		prev = current;
		current = current->next;
	}
	sort_next(tmpcur, list, tmpprev);
	tmpcur->next = sort_list(tmpcur->next);
	return (tmpcur);
}

t_stat	*sort_list_rev(t_stat *list)
{
	t_stat	*new;
	t_stat	*next;
	t_stat	*prev;

	new = list;
	next = NULL;
	prev = NULL;
	while (new != NULL)
	{
		next = new->next;
		new->next = prev;
		prev = new;
		new = next;
	}
	list = prev;
	return (list);
}

t_stat	*sort_list_time(t_stat *list)
{
	t_stat	*current;
	t_stat	*tmpcur;
	t_stat	*prev;
	t_stat	*tmpprev;

	if (!list || !list->next)
		return (list);
	current = list;
	tmpcur = list;
	prev = list;
	tmpprev = list;
	while (current != NULL)
	{
		if (current->time > tmpcur->time || (current->time == tmpcur->time
			&& ft_strcmp(current->file_path, tmpcur->file_path) < 0))
		{
			tmpcur = current;
			tmpprev = prev;
		}
		prev = current;
		current = current->next;
	}
	sort_next(tmpcur, list, tmpprev);
	tmpcur->next = sort_list_time(tmpcur->next);
	return (tmpcur);
}

t_stat	*do_sort_lst(t_arg *args, t_stat *stmp, t_stat *list, size_t total)
{
	if (list && args->arg_l == 1 && list->print_total == 0)
	{
		ft_putstr("total ");
		ft_print_unsigned_long(total);
		ft_putchar('\n');
	}
	if (args->arg_t == 1)
	{
		stmp = sort_list(stmp);
		stmp = sort_list_time(stmp);
	}
	if (args->arg_rmin == 1 && args->arg_t == 0)
	{
		stmp = sort_list(stmp);
		stmp = sort_list_rev(stmp);
	}
	else if (args->arg_rmin == 1 && args->arg_t == 1)
		stmp = sort_list_rev(stmp);
	else if (args->arg_t == 0 && args->arg_rmin == 0)
		stmp = sort_list(stmp);
	return (stmp);
}
