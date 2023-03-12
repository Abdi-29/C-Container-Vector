#ifndef VECTOR_H
#define VECTOR_H

#include "bool.h"

typedef struct s_vector {
	void	**items;
	int		capacity;
	int		size;
} 			t_vector;

typedef struct s_function_pointer {
	int 		(*pfVectorTotal)(t_vector *);
	int			(*pfVectorResize)(t_vector *, int);
	int 		(*pfVectorAdd)(t_vector *, void *);
	int 		(*pfVectorSet)(t_vector *, int, void *);
	void		*(*pfVectorGet)(t_vector *, int);
	int 		(*pfVectorDelete)(t_vector *, int);
	int 		(*pfVectorFree)(t_vector *);
	e_bool 		(*pfVectorEmpty)();
	t_vector	vector;
}				t_function_pointer;

void	vector_init(t_vector *v);
int		size(t_vector v*);
int		resize(t_vector *v, int size);
int 	push_back(t_vector *v, void *val);
int 	VectorSet(t_vector *v, int index, void *val);
void	*get(t_vector *, int index);
int 	vector_delete(t_vector *v, int index);
int 	deallocate(t_vector *v);
e_bool 	empty(void);
#endif