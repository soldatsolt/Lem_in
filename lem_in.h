#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/libft.h"
# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)

typedef	struct	s_table
{
	int			k;
	char		*str;
}				t_table;

typedef	struct	s_graph
{
	int			size;
	int			**matrix;
	t_table		*table;
}				t_graph;

#endif
