/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_chain_link.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:36:17 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/23 10:59:43 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_type(t_sstat filestat, t_stat *stats)
{
	char	*dup;

	dup = NULL;
	if (S_ISREG(filestat.st_mode) == 1)
		stats->type = 8;
	if (S_ISLNK(filestat.st_mode) == 1)
	{
		dup = ft_strdup(stats->file_name);
		free(stats->file_name);
		stats->file_name = readlink_malloc(dup, stats->file_path);
		if (stats->file_name == NULL)
			stats->file_name = ft_strdup(dup);
		stats->type = 2;
	}
	if (S_ISDIR(filestat.st_mode) == 1 && S_ISLNK(filestat.st_mode) == 0)
		stats->type = 4;
	if (S_ISCHR(filestat.st_mode) == 1)
		stats->type = 3;
	if (S_ISBLK(filestat.st_mode) == 1)
		stats->type = 5;
	if (S_ISSOCK(filestat.st_mode) == 1)
		stats->type = 6;
}

void	get_stats_grps(t_sstat filestat, t_stat *stats)
{
	char *str;
	char *str2;

	str = NULL;
	str2 = NULL;
	if (getgrgid(filestat.st_gid) == NULL)
		str = ft_itoa(filestat.st_gid);
	else
		str = ft_strdup(getgrgid(filestat.st_gid)->gr_name);
	if ((getpwuid(filestat.st_uid) == NULL))
		str2 = ft_itoa(filestat.st_uid);
	else
		str2 = ft_strdup(getpwuid(filestat.st_uid)->pw_name);
	stats->groups = ft_strdup(str);
	stats->creator = ft_strdup(str2);
	free(str);
	free(str2);
}

int		fill_stats(t_stat *stats, char *d_name, char *path, t_arg *args)
{
	t_sstat		filestat;

	if (lstat(path, &filestat) == -1)
		return (1);
	stats->file_name = ft_strdup((d_name));
	stats->file_path = ft_strdup(path);
	stats->law = (char *)malloc(sizeof(char) * 11);
	get_type(filestat, stats);
	if (stats->type == 3 || stats->type == 5)
	{
		stats->size = minor(filestat.st_rdev);
		stats->minor = major(filestat.st_rdev);
		args->p_spc = 1;
	}
	else
		stats->size = filestat.st_size;
	stats->under_files = filestat.st_nlink;
	get_stats_grps(filestat, stats);
	stats->date = ft_strdup(ctime(&filestat.st_mtime));
	stats->time = (long)filestat.st_mtime;
	ft_get_law(stats, filestat);
	return (0);
}
