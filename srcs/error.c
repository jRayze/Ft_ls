/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:17:40 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/23 10:59:50 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_error(char c)
{
	write(2, "ft_ls: illegal option -- ", 25);
	write(2, &c, 1);
	write(2, "\n", 1);
	ft_putstr_fd("usage: ft_ls [-lRart] [file ...]\n", 2);
	return (-1);
}

void	*print_error_permission(char *file_path)
{
	char	*file_name;
	int		i;

	i = ft_strlen(file_path);
	i = i - 1;
	while (file_path[i] && file_path[i] != '/')
		i--;
	if (ft_search(file_path, '/') == 0)
		file_name = ft_strdup(file_path);
	else
		file_name = ft_strsub(file_path, i + 1, ft_strlen(file_path) - 1);
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	ft_memdel((void **)&file_name);
	return (NULL);
}

int		print_no_file(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (1);
}

char	**print_invalid(char **invalid, int i)
{
	int cpt;

	cpt = 0;
	if (i > 1)
		invalid = ft_sort_tab(invalid);
	while (invalid[cpt])
	{
		print_no_file(invalid[cpt]);
		cpt++;
	}
	return (invalid);
}
