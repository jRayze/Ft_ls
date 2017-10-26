/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:44:07 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/15 14:08:36 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	do_file(t_arg *args, char *file_path)
{
	t_stat	*tmp;
	t_stat	*tmp2;
	t_stat	*tmp3;
	int		j;

	tmp = (t_stat *)malloc(sizeof(t_stat));
	j = (ft_init_stat(tmp)) ? -1 : 0;
	tmp2 = tmp;
	while (args->file && args->file[++j])
	{
		file_path = ft_strdup(args->file[j]);
		if ((push_stat(tmp, args->file[j], file_path, args)) != NULL)
			tmp->print_total = 1;
		args->date = (long)time(NULL);
		if (file_path)
			ft_memdel((void **)&file_path);
	}
	tmp2->next->print_total = 1;
	tmp2->next = print_list(tmp2->next, args, 0);
	tmp3 = tmp2;
	if (args->arg && args->arg[0] && args->i == 1)
		ft_putchar('\n');
	if (tmp3)
		free_list(tmp3->next);
	free(tmp3);
}

void	do_dir(t_arg *args)
{
	char	*file_path;
	int		i;

	i = 0;
	while (args->arg && args->arg[i])
	{
		file_path = ft_strdup(args->arg[i]);
		if (i == 0 && args->file && args->i == 0)
			ft_putchar('\n');
		ft_recurs(file_path, args);
		if (file_path)
			ft_memdel((void **)&file_path);
		if (args->arg[i + 1])
			ft_putchar('\n');
		i++;
	}
}

int		stock_and_print(t_arg *args)
{
	char	*file_path;

	file_path = NULL;
	if ((args->arg != NULL && args->arg[0]) || (args->file && args->file[0]))
	{
		if (args->file && args->file[0])
			do_file(args, file_path);
		if (args->arg && args->arg[0])
			do_dir(args);
	}
	if (args->arg == NULL && args->file == NULL)
	{
		args->arg = (char **)malloc(sizeof(char *) * (2));
		args->arg[0] = ft_strdup(".");
		args->arg[1] = NULL;
		file_path = ft_strdup(".");
		ft_recurs(file_path, args);
		if (file_path)
			ft_memdel((void **)&file_path);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_arg			*args;
	time_t			t;
	int				release;

	release = 0;
	args = (t_arg*)malloc(sizeof(t_arg));
	ft_init_arg(args);
	time(&t);
	if (ac >= 2)
	{
		release = ft_pars_arg(av, args);
		if (release == -1)
			return (1);
		if (release == 1 && args->arg == NULL && args->file == NULL)
			return (0);
		if ((args->arg != NULL && ft_get_nb_arg(args->arg) > 1)
			|| (args->file != NULL && ft_get_nb_arg(args->file) > 1))
		{
			args = sort_tab(args);
			args->date = (long)t;
		}
	}
	stock_and_print(args);
	free_arg(args);
	return (release);
}
