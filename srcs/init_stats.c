/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:11:45 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/13 14:11:56 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_arg(t_arg *args)
{
	args->arg_l = 0;
	args->arg_rmaj = 0;
	args->arg_a = 0;
	args->arg_rmin = 0;
	args->arg_t = 0;
	args->arg_u = 0;
	args->arg_f = 0;
	args->arg_g = 0;
	args->arg_d = 0;
	args->i = 0;
	args->arg = NULL;
	args->file = NULL;
	args->date = 0;
	args->p_spc = 0;
	return ;
}

int		ft_init_stat(t_stat *stats)
{
	if (!stats)
		return (0);
	stats->type = 0;
	stats->under_files = 0;
	stats->creator = NULL;
	stats->groups = NULL;
	stats->size = 0;
	stats->minor = 0;
	stats->date = NULL;
	stats->file_name = NULL;
	stats->i = 0;
	stats->j = 0;
	stats->time = 0;
	stats->file_path = NULL;
	stats->print_total = 0;
	stats->attrib = 0;
	stats->next = NULL;
	return (1);
}

t_stat	*ft_new_stat(char *file_path, char *d_name, t_arg *args)
{
	t_stat	*new_directory;

	new_directory = (t_stat*)malloc(sizeof(t_stat));
	ft_init_stat(new_directory);
	if ((fill_stats(new_directory, d_name, file_path, args)) != 0)
	{
		free(new_directory);
		return (NULL);
	}
	new_directory->next = NULL;
	return (new_directory);
}

t_stat	*push_stat(t_stat *stats, char *d_name, char *file_path, t_arg *args)
{
	t_stat	*new_file;
	t_stat	*current_file;

	current_file = stats;
	if ((new_file = ft_new_stat(file_path, d_name, args)) == NULL)
	{
		ft_memdel((void *)new_file);
		return (stats);
	}
	if (stats == NULL)
		return (new_file);
	while (current_file->next != NULL)
		current_file = current_file->next;
	current_file->next = new_file;
	current_file->next->next = NULL;
	return (stats);
}

int		ft_count_slash(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '/')
			i++;
		str++;
	}
	return (i);
}
