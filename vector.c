#include "lem_in.h"

void		vector_init(t_vector *v)
{
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
	v->items = x_malloc(sizeof(void *) * v->capacity);
}

int			vector_total(t_vector *v)
{
	return (v->total);
}

static void	vector_resize(t_vector *v, int capacity)
{
	void **items;

	items = ft_realloc(v->items, sizeof(void *) * capacity);
	if (items)
	{
		v->items = items;
		v->capacity = capacity;
	}
}

void		vector_add(t_vector *v, void *item)
{
	if (v->capacity == v->total)
		vector_resize(v, v->capacity * 2);
	v->items[v->total++] = item;
}

void		vector_set(t_vector *v, int index, void *item)
{
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}

void		*vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->total)
		return (v->items[index]);
	return (NULL);
}

void		vector_delete(t_vector *v, int index)
{
	int	i;

	i = index;
	if (index < 0 || index >= v->total)
		return ;
	v->items[index] = NULL;
	while (i < v->total - 1)
	{
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
		i++;
	}
	v->total--;
	if (v->total > 0 && v->total == v->capacity / 4)
		vector_resize(v, v->capacity / 2);
}

void		vector_free(t_vector *v)
{
	free(v->items);
}
