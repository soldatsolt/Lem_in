#include "lem_in.h"

void	allocate_graph(t_graph *graph)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	graph->matrix = (int **)x_malloc(sizeof(int *) * graph->size);
	graph->table = (t_table *)x_malloc(sizeof(t_table) * graph->size);
	while (i < graph->size)
	{
		graph->matrix[i] = (int *)x_malloc(sizeof(int) * graph->size);
		while (j < graph->size)
		{
			graph->matrix[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	free_graph(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->size)
	{
		free(graph->matrix[i]);
		i++;
	}
	free(graph->matrix);
	free(graph->table);
	free(graph);
}

void	print_matr_graph(t_graph *graph)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ft_putstr("       |");
	while (i < graph->size)
	{
		ft_printf("%7s|", graph->table[i].str);
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (i < graph->size)
	{
		ft_printf("%7s|", graph->table[i].str);
		while (j < graph->size)
		{
			ft_printf("___%d___|", graph->matrix[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

char	*first_word_of_str(char *str)
{
	char	*s;
	int		i;

	s = ft_strdup(str);
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	s[i] = '\0';
	return (s);
}

void	put_str_to_table(t_graph *graph, char *str, int i)
{
	char	*s;

	s = first_word_of_str(str);
	graph->table[i].str = ft_strdup(s);
	graph->table[i].k = i;
	free(s);
}

int		main(void)
{
	t_graph	*graph;
	char	*str;
	int		i;
	int		o;

	i = 0;
	graph = (t_graph *)x_malloc(sizeof(t_graph));
	o = open("map", O_RDONLY);
	get_next_line(3, &str);
	graph->size = ft_atoi(str);
	free(str);
	allocate_graph(graph);
	while (get_next_line(3, &str))
	{
		if (str[0] != '#' && i < graph->size)
		{
			put_str_to_table(graph, str, i);
			i++;
		}
		ft_printf("%s\n", str);
		ft_strdel(&str);
	}
	close(o);
	print_matr_graph(graph);
	free_graph(graph);

	return (0);
}
