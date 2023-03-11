#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_vector {
	void	**items;
	int		capacity;
	int		total;
} 			t_vector;

typedef struct s_function_pointer {
	int 	(*pfVectorTotal)(t_vector *);
	int			(*pfVectorResize)(t_vector *, int);
	int 		(*pfVectorAdd)(t_vector *, void *);
	int 		(*pfVectorSet)(t_vector *, int, void *);
	void		*(*pfVectorGet)(t_vector *, int);
	int 		(*pfVectorDelete)(t_vector *, int);
	int 		(*pfVectorFree)(t_vector *);
	t_vector	vector;
}				t_function_pointer;

#endif