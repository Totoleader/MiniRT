

#include "../../include/minirt_bonus.h"

/*
IDENTITY MATRIX
Ihe identity matrix has ones on the main diagonal and zeros elsewhere.
When the identity matrix represents a geometric transformation,
the object remains unchanged by the transformation.
In other contexts, it is analogous to multiplying by the number 1.
*/
t_mat4	identity_matrix(void)
{
	t_mat4	id_mat;

	ft_bzero(&id_mat, sizeof(t_mat4));
	id_mat.p[0][0] = 1;
	id_mat.p[1][1] = 1;
	id_mat.p[2][2] = 1;
	id_mat.p[3][3] = 1;
	return (id_mat);
}

/*
MULTIPLY MATRIX * MATRIX
The product of two matrices, A and B, is the sum of the products
across some row of A with the corresponding entries down some column of B.
In simple words, The dot product of the first row of the first matrix
and the first column of the second matrix will result
in the first element of the product matrix.
*/
t_mat4	matrix_mult(t_mat4 mat1, t_mat4 mat2)
{
	int		row;
	t_mat4	res;

	res = identity_matrix();
	row = -1;
	while (++row < 4)
	{
		res.p[row][0] = (mat1.p[row][0] * mat2.p[0][0]) \
			+ (mat1.p[row][1] * mat2.p[1][0]) \
			+ (mat1.p[row][2] * mat2.p[2][0]) \
			+ (mat1.p[row][3] * mat2.p[3][0]);
		res.p[row][1] = (mat1.p[row][0] * mat2.p[0][1]) \
			+ (mat1.p[row][1] * mat2.p[1][1]) \
			+ (mat1.p[row][2] * mat2.p[2][1]) \
			+ (mat1.p[row][3] * mat2.p[3][1]);
		res.p[row][2] = (mat1.p[row][0] * mat2.p[0][2]) \
			+ (mat1.p[row][1] * mat2.p[1][2]) \
			+ (mat1.p[row][2] * mat2.p[2][2]) \
			+ (mat1.p[row][3] * mat2.p[3][2]);
		res.p[row][3] = (mat1.p[row][0] * mat2.p[0][3]) \
			+ (mat1.p[row][1] * mat2.p[1][3]) \
			+ (mat1.p[row][2] * mat2.p[2][3]) \
			+ (mat1.p[row][3] * mat2.p[3][3]);
	}
	return (res);
}

/* 
MULTIPLY MATRIX * VECTOR
This function multiplies a 4x4 matrix by a 3D vector.
It performs the matrix-vector multiplication and
returns the resulting 3D vector.
*/
t_vec3	matrix_vec_mult(t_mat4 mat, t_vec3 v)
{
	t_vec3	res;

	res.x = (mat.p[0][0] * v.x) + (mat.p[0][1] * v.y) + \
		(mat.p[0][2] * v.z) + mat.p[0][3];
	res.y = (mat.p[1][0] * v.x) + (mat.p[1][1] * v.y) + \
		(mat.p[1][2] * v.z) + mat.p[1][3];
	res.z = (mat.p[2][0] * v.x) + (mat.p[2][1] * v.y) + \
		(mat.p[2][2] * v.z) + mat.p[2][3];
	return (res);
}
