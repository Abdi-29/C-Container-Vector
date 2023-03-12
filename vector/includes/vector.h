#ifndef VECTOR_H
#define VECTOR_H

#include "bool.h"
#include "status.h"
#include <stdlib.h>

typedef size_t size_type;
//TODO move this function to lib
#define ft_max(a,b) (((a)>(b))?(a):(b))

typedef struct s_vector {
	void		**items;
	size_type	capacity;
	size_type	size;
} 			t_vector;

e_status 	vector_init(t_vector **v);
size_type	size(t_vector *v);
e_status	resize(t_vector *v, size_type count);
e_status 	push_back(t_vector *v, void *val);
int 		VectorSet(t_vector *v, int index, void *val);
void		*get(t_vector *v, size_type index);
int 		vector_delete(t_vector *v, int index);
int 		deallocate(t_vector *v);
e_status	reserve(t_vector *v, size_type count);
e_bool 		empty(void);

e_status	reduce_elements(t_vector *v, size_type count);
#endif
