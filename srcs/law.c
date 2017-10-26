/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   law.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 11:59:07 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/15 14:08:29 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_getacl(char c, t_sstat filestat, int i)
{
	if ((filestat.st_mode & S_ISVTX) && (filestat.st_mode & S_IXUSR))
		c = 't';
	else if (filestat.st_mode & S_ISVTX)
		c = 'T';
	else
		c = ((filestat.st_mode & S_IXUSR) && i == 2) ? 'x' : '-';
	return (c);
}

char	ft_law(char c, t_sstat filestat, int i)
{
	if (i == 0)
	{
		if ((filestat.st_mode & S_ISUID) && (filestat.st_mode & S_IXUSR))
			c = 's';
		else if (filestat.st_mode & S_ISUID)
			c = 'S';
		else
			c = ((filestat.st_mode & S_IXUSR) && i == 0) ? 'x' : '-';
	}
	else if (i == 1)
	{
		if ((filestat.st_mode & S_ISGID) && (filestat.st_mode & S_IXUSR))
			c = 's';
		else if (filestat.st_mode & S_ISGID)
			c = 'S';
		else
			c = ((filestat.st_mode & S_IXUSR) && i == 1) ? 'x' : '-';
	}
	else if (i == 2)
		c = ft_getacl(c, filestat, i);
	return (c);
}

void	ft_get_law(t_stat *stats, t_sstat filestat)
{
	if (stats->type == 2)
		stats->law[0] = 'l';
	else if (stats->type == 3)
		stats->law[0] = 'c';
	else if (stats->type == 4)
		stats->law[0] = 'd';
	else if (stats->type == 5)
		stats->law[0] = 'b';
	else if (stats->type == 6)
		stats->law[0] = 's';
	else
		stats->law[0] = '-';
	stats->law[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
	stats->law[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
	stats->law[3] = ft_law(stats->law[3], filestat, 0);
	stats->law[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
	stats->law[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
	stats->law[6] = ft_law(stats->law[6], filestat, 1);
	stats->law[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
	stats->law[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
	stats->law[9] = ft_law(stats->law[9], filestat, 2);
	stats->law[10] = '\0';
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

t_stat	*get_acl(t_stat *stats)
{
	t_stat		*tmp;
	int			len;
	int			lenx;
	char		name[256];
	char		*link;

	tmp = stats;
	link = NULL;
	while (tmp)
	{
		len = 0;
		lenx = 0;
		lenx = listxattr(tmp->file_path, name, sizeof(name), 0);
		if (tmp->type == 2)
		{
			link = ft_strchr(tmp->file_name, '>') + 2;
			len = getxattr(link, name, 0, 0, 0, 0);
		}
		else
			len = getxattr(tmp->file_path, name, 0, 0, 0, 0);
		tmp->attrib = len;
		tmp = tmp->next;
	}
	return (stats);
}
