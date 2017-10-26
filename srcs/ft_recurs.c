/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:55:43 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/15 14:08:24 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		do_recurs(char *file_path, t_arg *args)
{
	char		*tmp;

	tmp = NULL;
	ft_putchar('\n');
	tmp = ft_strdup(file_path);
	args->i = 1;
	ft_recurs(tmp, args);
	free(tmp);
	return (1);
}

int		ft_recurs(char *path, t_arg *args)
{
	t_stat			*elem;
	t_stat			*beg;
	size_t			total[1];

	total[0] = 0;
	if (args->arg && (args->i == 1 || ((args->arg[1] || args->file))))
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (!(elem = read_directory(path, args, total)))
		return (0);
	elem->next = print_list(elem->next, args, total[0]);
	beg = elem;
	if (args->arg_rmaj)
		while (beg->next && (beg = beg->next))
		{
			if (beg->type == 4 && (ft_strcmp(beg->file_name, ".") != 0
				&& ft_strcmp(beg->file_name, "..") != 0))
				do_recurs(beg->file_path, args);
		}
	if (elem != NULL)
		free_list(elem->next);
	free(elem);
	return (1);
}

void	collect_total(t_arg *args, char *file_path, size_t *total)
{
	t_sstat			filestat;

	args->date = (long)time(NULL);
	lstat(file_path, &filestat);
	total[0] += filestat.st_blocks;
}

t_stat	*read_directory(char *path, t_arg *args, size_t *total)
{
	DIR				*dp;
	t_stat			*elem;
	t_stat			*tmp;
	struct dirent	*ep;
	char			*file_path;

	if (!(dp = opendir(path)))
		return (print_error_permission(path));
	elem = (t_stat *)malloc(sizeof(t_stat));
	ft_init_stat(elem);
	tmp = elem;
	while ((ep = readdir(dp)))
	{
		file_path = dofile_path(ft_strdup(ep->d_name), ft_strdup(path));
		if (ep->d_name[0] != '.' || args->arg_a)
		{
			push_stat(elem, ep->d_name, file_path, args);
			collect_total(args, file_path, total);
		}
		ft_memdel((void **)&file_path);
	}
	closedir(dp);
	if (ep)
		ft_memdel((void **)&ep);
	return (tmp);
}
