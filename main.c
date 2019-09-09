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
	while (i < 4096)
	{
		free(graph->matrix[i]);
		free(graph->table[i].str);
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

	i = 0;
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

char	*first_node(char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup(str);
	while (s[i] && s[i] != '-')
	{
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*second_node(char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (*str != '-' && *str)
		str++;
	str++;
	s = ft_strdup(str);
	return(s);
}

int		find_i_by_str(t_graph *graph, char *str)
{
	int		i;

	i = 0;
	while (i < graph->size)
	{
		if (!ft_strcmp(graph->table[i].str, str))
			return (i);
		i++;
	}
	return (-1);
}

void	make_edge(t_graph *graph, char *str)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = first_node(str);
	s2 = second_node(str);
	graph->matrix[find_i_by_str(graph, s1)][find_i_by_str(graph, s2)] = 1;
	graph->matrix[find_i_by_str(graph, s2)][find_i_by_str(graph, s1)] = 1;
	free(s1);
	free(s2);
}

int		is_str_is_edge(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '#')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

void	parse_start(t_graph *graph, char *str, int *ii)
{
	ft_printf("%s\n", str);
	ft_strdel(&str);
	get_next_line(3, &str);
	graph->start = *ii;
	put_str_to_table(graph, str, *ii);
	ft_printf("%s\n", str);
	ft_strdel(&str);
	(*ii)++;
}

void	parse_end(t_graph *graph, char *str, int *ii)
{
	ft_printf("%s\n", str);
	ft_strdel(&str);
	get_next_line(3, &str);
	graph->end = *ii;
	put_str_to_table(graph, str, *ii);
	ft_printf("%s\n", str);
	ft_strdel(&str);
	(*ii)++;
}

void	parse_str(t_graph *graph, char *str)
{
	static int	i = 0;
	int			ii;

	ii = i;
	if (is_str_is_edge(str))
	{
		make_edge(graph, str);
		graph->size = i;
	}
	if (str[0] != '#' && i < graph->size)
	{
		put_str_to_table(graph, str, i);
		i++;
		ii++;
	}
	if (!ft_strcmp(str, "##start"))
		parse_start(graph, str, &(ii));
	else if (!ft_strcmp(str, "##end"))
		parse_end(graph, str, &(ii));
	else
	{
		ft_printf("%s\n", str);
		ft_strdel(&str);
	}
	i = ii;
}

int		main(void)
{
	t_graph	*graph;
	char	*str;
	int		o;

	graph = (t_graph *)x_malloc(sizeof(t_graph));
	o = open("map", O_RDONLY);
	get_next_line(3, &str);
	graph->n = ft_atoi(str);
	graph->size = 4096;
	free(str);
	allocate_graph(graph);
	while (get_next_line(3, &str))
	{
		parse_str(graph, str);
	}
	close(o);
	print_matr_graph(graph);
	free_graph(graph);
	return (0);
}
