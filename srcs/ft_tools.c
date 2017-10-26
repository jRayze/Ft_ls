/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:49:48 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/12 10:00:42 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_search(char *s, int c)
{
	int i;

	i = 0;
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (1);
	return (0);
}

int		ft_isdir(char *argv)
{
	t_sstat		file;
	int			i;

	i = 0;
	stat(argv, &file);
	i = S_ISDIR(file.st_mode);
	return (i);
}

int		ft_is_link(char *argv)
{
	t_sstat		file;
	int			i;

	i = 0;
	lstat(argv, &file);
	i = S_ISLNK(file.st_mode);
	return (i);
}

char	*dofile_path(char *name, char *file_path)
{
	char	*new;
	char	*buf;

	buf = ft_strjoin(file_path, "/");
	new = ft_strjoin(buf, name);
	free(buf);
	ft_memdel((void**)&name);
	ft_memdel((void **)&file_path);
	return (new);
}

char	*readlink_malloc(char *name, char *file_path)
{
	char	*buff;
	char	*tmp;
	char	*tmp2;
	int		ret;

	buff = (char *)malloc(sizeof(char) * 100);
	if ((ret = readlink(file_path, buff, 100)) == -1)
		return (NULL);
	buff[ret] = '\0';
	tmp = ft_strjoin(name, " -> ");
	tmp2 = ft_strjoin(tmp, buff);
	ft_memdel((void **)&buff);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&name);
	return (tmp2);
}
