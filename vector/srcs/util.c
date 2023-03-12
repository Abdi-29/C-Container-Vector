#include "vector.h"

e_status reduce_elements(t_vector *v, size_type count) {
	void **items = realloc(v->items, count * sizeof(void *));
	if(!items) {
		return MALLOC_ERROR;
	}
	v->items = items;
	v->size = count;
	return SUCCESS;
}

