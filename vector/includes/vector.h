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

/**
 * Set data at a given index:
 *This function sets the data at the given index
 * if the index is valid. If you will pass the invalid
 * index then it throw an error.
 * @param v
 * @param index
 * @param val
 * @return SUCCESS
 * @return ERROR
 */
e_status 	set(t_vector *v, size_type index, void *val);
void		*get(t_vector *v, size_type index);
e_status 	delete(t_vector *v, size_type index);
e_status 	deallocate(t_vector *v);
e_status	reserve(t_vector *v, size_type count);
e_bool 		empty(t_vector *v);

e_status	reduce_elements(t_vector *v, size_type count);
#endif
