/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:06:53 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/12 09:15:25 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_tab_double(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = ft_get_nb_arg(tab);
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_arg(t_arg *args)
{
	if (args->arg != NULL)
		free_tab_double(args->arg);
	if (args->file != NULL)
		free_tab_double(args->file);
	ft_memdel((void **)&args);
}

void	free_list(t_stat *stats)
{
	t_stat	*tmp;

	while (stats != NULL)
	{
		tmp = stats;
		stats = stats->next;
		if (tmp->file_path != NULL)
			ft_memdel((void **)&tmp->file_path);
		if (tmp->law != NULL)
			free(tmp->law);
		if (tmp->file_name != NULL)
			ft_memdel((void **)&tmp->file_name);
		if (tmp->groups != NULL)
			ft_memdel((void **)&tmp->groups);
		if (tmp->creator != NULL)
			ft_memdel((void **)&tmp->creator);
		if (tmp->date != NULL)
			ft_memdel((void **)&tmp->date);
		if (tmp != NULL)
			ft_memdel((void **)&tmp);
	}
	return ;
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
