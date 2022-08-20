#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_data
{
	int		nb_value_a;
	int		nb_value_b;
	int		fix_len_a;
	int		ac;
	char	**av;
}			t_data;
// {file} [main.c]
int	is_already_sort(int *buff_a, t_data *data);
// {file} [sort_a.c]
void	swap_a(int *buff_a);
void	push_a(int *buff_a, int *buff_b, t_data *data);
void	rotate_a(int *buff_a, t_data *data);
void	reverse_rotate_a(int *buff_a, t_data *data);
// {file} [sort_b.c]
void	swap_b(int *buff_b);
void	push_b(int *buff_a, int *buff_b, t_data *data);
void	rotate_b(int *buff_b, t_data *data);
void	reverse_rotate_b(int *buff_b, t_data *data);
// {file} [error.c]
int		error(void);
int		error_argument(char *str);
int		error_without_space(char *str);
// char	*error_zero(char *str);
int		error_same_nb(int *buff, t_data *data);
// {file} [sort_algo.c]
void	algo_two_number(int *buff_a);
void	algo_three_number(int *buff_a, t_data *data);
void	algo_four_number(int *buff_a, int *buff_b, t_data *data);
void	algo_five_number(int *buff_a, int *buff_b, t_data *data);
// {file} [radix.c]
void	radix(int *buff_a, int *buff_b, t_data *data);
int		*index_tab(int *buff_a, t_data *data);
int		loop_radix(int *index, int *buff_b, int byte_shift, t_data *data);
// {file} [split_number.c]
int		*split_number(char *str, t_data *data);
// {file} [verif_int.c]
char	*many_space_to_one(char *str);
int		verif_len_max_min(char *str);
int		ft_atol(char *nptr);
#endif