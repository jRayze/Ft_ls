/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:32:35 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/13 14:28:56 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define VALID_ARG "lRart\0"

# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>

typedef struct		s_stat
{
	unsigned char	type;
	char			*law;
	int				under_files;
	char			*creator;
	char			*groups;
	unsigned int	size;
	unsigned int	minor;
	char			*date;
	char			*file_name;
	char			*file_path;
	int				i;
	int				j;
	long			time;
	int				print_total;
	int				attrib;
	struct s_stat	*next;
}					t_stat;

typedef struct		s_arg
{
	char			**arg;
	char			**file;
	int				arg_l;
	int				arg_rmaj;
	int				arg_a;
	int				arg_rmin;
	int				arg_t;
	int				arg_u;
	int				arg_f;
	int				arg_g;
	int				arg_d;
	int				i;
	long			date;
	int				p_spc;
}					t_arg;

typedef struct		s_max
{
	int				lgt_crea;
	int				lgt_grp;
	int				lgt_uf;
	int				lgt_size;
	int				lgt_minor;
}					t_max;

typedef struct stat	t_sstat;

int					ft_pars_arg(char **argv, t_arg *args);
int					ft_search(char *s, int c);
int					ft_isdir(char *argv);
int					ft_init_stat(t_stat *stats);
void				ft_init_arg(t_arg *args);
int					fill_stats(t_stat *st, char *name, char *path, t_arg *ag);
t_stat				*ft_new_stat(char *d_name, char *file_path, t_arg *args);
int					ft_error(char c);
char				*dofile_path(char *name, char *file_path);
void				ft_get_law(t_stat *stats, t_sstat filestat);
void				print_date(char *str, long date, long time);
void				ft_print_stats(t_stat *stats, t_arg *args, t_max *max);
t_stat				*push_stat(t_stat *sts, char *name, char *path, t_arg *ag);
t_stat				*print_list(t_stat *list, t_arg *args, size_t total);
int					ft_get_nb_arg(char **tab);
t_stat				*sort_list(t_stat *lst);
int					stock_and_print(t_arg *args);
void				ft_print_unsigned_long(unsigned long n);
t_stat				*ft_recur(t_arg *args, t_stat *stats, DIR *dp, char *path);
int					ft_check_list_dir(t_stat *stats);
char				*readlink_malloc(char *name, char *file_path);
char				**ft_sort_tab(char **tab);
int					ft_check_tab(char **tab);
char				**ft_sort_dir(char **tab);
char				**ft_sort_type(char **tab);
char				*del_char(char *file_path, int nb);
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
void				ft_putnbr(int nb);
char				*ft_strdup(char *s1);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
void				ft_putstr(char const *s);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
t_stat				*sort_list_rev(t_stat *list);
t_stat				*sort_list_time(t_stat *list);
t_stat				*free_elem(t_stat *liste);
int					compare_date(long timer, long date);
int					ft_recurs(char *file_path, t_arg *args);
void				*print_error_permission(char *file_path);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_sort_tab_time(char **tab);
int					ft_check_tab_time(char **tab);
char				**reverse_tab(char **tab);
t_arg				*sort_tab(t_arg *list);
int					chck_d(char **argv, int i, t_arg *args);
void				print_tab(char **tab);
int					ft_is_link(char *argv);
int					check_link(char **argv);
int					check(char **argv, int i, t_arg *args);
void				ft_putstr_fd(const char *str, int fd);
void				free_list(t_stat *stats);
void				free_arg(t_arg *args);
void				ft_memdel(void **ap);
char				memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
int					count_elem_list(t_stat *stats);
t_stat				*read_directory(char *file_path, t_arg *args, size_t *tot);
void				free_tab_double(char **tab);
int					print_no_file(char *str);
void				stock_by_type(char *argv, t_arg *args, size_t *nb);
void				ft_put_space_str(char *str, int j);
t_stat				*do_sort_lst(t_arg *ag, t_stat *tmp, t_stat *l, size_t tot);
void				ft_put_space_int(int uf, int j);
t_max				*get_space(t_stat *stats, t_max *max);
int					ft_stock(char **argv, t_arg *args, int i);
char				*ft_itoa(int n);
void				ft_print_unsigned_long(unsigned long n);
int					ft_sizeint(int i);
int					len_tab(char **str);
char				**print_invalid(char **invalid, int i);
int					check_invalid(char **argv, int i);
t_stat				*get_acl(t_stat *stats);
void				ft_get_law(t_stat *stats, t_sstat filestat);

#endif
