#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

e_status vector_init(t_vector **v) {
    //init vector struct
	t_vector *tmp = malloc(sizeof(t_vector));
	if(!tmp) {
		return MALLOC_ERROR;
	}
    tmp->capacity = 0;
    tmp->size = 0;
    tmp->items = NULL;
	*v = tmp;
	return SUCCESS;
}

size_type	size(t_vector *v) {
	return v->size;
}

e_status	resize(t_vector *v, size_type count) {
	e_status status = SUCCESS;
	if (v->size > count) {
		status = reduce_elements(v, count);
	} else if(v->size < count) {
		if(count > v->capacity) {
			status = reserve(v, ft_max(v->capacity * 2, count));
		}
	} else {
		status = reserve(v, ft_max(v->capacity * 2, 1));
	}
	return status;
}

e_status	reserve(t_vector *v, size_type count) {
	void **items = realloc(v->items, sizeof(void *) * count);
	if(!items) {
		return MALLOC_ERROR;
	}
	v->items = items;
	v->capacity = count;
	return SUCCESS;
}

e_status 	push_back(t_vector *v, void *val) {
	e_status status = UNDEFINED;
	if(v->size == v->capacity) {
		status = resize(v, v->capacity * 2);
		if(status != SUCCESS) {
			return status;
		}
	}
	v->items[v->size] = val;
	v->size++;
	return status;
}

void	*get(t_vector *v, size_type index) {
	if(index >= v->size) {
		return NULL;
	}
	return v->items[index];
}

e_status 	set(t_vector *v, size_type index, void *val) {
	if(index >= v->size) {
		return OUT_OF_RANGE;
	}
	v->items[index] = val;
	return SUCCESS;
}

e_bool 		empty(t_vector *v) {
	return v->size == 0;
}

e_status 	delete(t_vector *v, size_type index) {
	if(index >= v->size) {
		return OUT_OF_RANGE;
	}
	for(size_type i = index; i < v->size; ++i) {
		v->items[i] = v->items[i + 1];
	}
	v->size--;
	return SUCCESS;
}

e_status 	deallocate(t_vector *v) {
	return SUCCESS;
}

int main(void) {
	t_vector *v;

	e_status status = vector_init(&v);
	if (status != SUCCESS) {
		printf("check the error code and then exit\n");
		exit(1);
	}
	push_back(v, "hello");
	push_back(v, "ciao");
	push_back(v, "salut");
	for(size_type i = 0; i < v->size; ++i) {
		printf("testing vector: [%s]\n", (char *) get(v, i));
	}
//	resize(v,2);
	printf("--------------------------------------------------------------\n");
	for(size_type i = 0; i < v->size; ++i) {
		printf("testing vector: [%s]\n", (char *) get(v, i));
	}
	printf("--------------------------------------------------------------\n");
	delete(v, 0);
	for(size_type i = 0; i < v->size; ++i) {
		printf("testing vector: [%s]\n", (char *) get(v, i));
	}
}
