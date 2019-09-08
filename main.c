#include "lem_in.h"

void	allocate_graph(t_graph *graph)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	graph->matrix = (int **)x_malloc(sizeof(int *) * graph->size);
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
	free(graph);
}

void	print_matr_graph(t_graph *graph)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < graph->size)
	{
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

int		main(void)
{
	t_graph	*graph;
	char	*str;

	graph = (t_graph *)x_malloc(sizeof(t_graph));
	open("map", O_RDONLY);
	get_next_line(3, &str);
	graph->size = ft_atoi(str);
	free(str);
	allocate_graph(graph);
	while (get_next_line(3, &str))
	{
		ft_printf("%s\n", str);
		ft_strdel(&str);
	}
	close(3);
	print_matr_graph(graph);
	free_graph(graph);
	return (0);
}
