#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/libft.h"
# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)
#define VECTOR_INIT_CAPACITY 4
#define VECTOR_INIT(vec) vector vec; vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (void *) item)
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *) item)
#define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct	s_vector
{
	void		**items;
	int			capacity;
	int			total;
}				t_vector;

typedef	struct	s_table
{
	int			k;
	char		*str;
}				t_table;

typedef	struct	s_graph
{
	int			size;
	int			n;
	int			start;
	int			end;
	int			**matrix;
	t_table		*table;
}				t_graph;

void			vector_init(t_vector *);
int				vector_total(t_vector *);
static void		vector_resize(t_vector *, int);
void			vector_add(t_vector *, void *);
void			vector_set(t_vector *, int, void *);
void			*vector_get(t_vector *, int);
void			vector_delete(t_vector *, int);
void			vector_free(t_vector *);

#endif
