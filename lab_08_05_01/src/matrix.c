#include "../inc/func.h"
#include "../inc/struct.h"

void identy_matrix(matrix *m)
{
	for (int y = 0; y < m->rows; y++)
	{
		for (int x = 0; x < m->cols; x++)
		{
			if (y == x) 
				m->values[y * m->cols + x] = 1;
			else 
				m->values[y * m->cols + x] = 0;
		}
	}
}

void multiply_matrix(const matrix *l, const matrix *r, matrix *m)
{
	for (int y = 0; y < m->rows; y++)
	{
		for (int x = 0; x < m->cols; x++)
		{
			int i = y * m->cols + x;
			m->values[i] = 0;

			for (int k = 0; k < l->cols; k++)
			{
				m->values[i] += l->values[y * l->cols + k] * r->values[k * r->cols + x];
			}
		}
	}
}

void power_matrix(matrix *m, int p)
{
	matrix res;
	matrix tmp;

	res.cols = tmp.cols = m->cols;
	res.rows = tmp.rows = m->rows;

	init_matrix(&res);
	if (!res.values)
	{
		free_matrix(m);
	}
	else
	{
		init_matrix(&tmp);
		if (!tmp.values)
		{
			free_matrix(&res);
			free_matrix(m);
		}
		else
		{
			identy_matrix(&res);

			for (int i = 0; i < p; i++)
			{
				multiply_matrix(&res, m, &tmp);
				for (int j = 0; j < m->cols * m->rows; j++)
					res.values[j] = tmp.values[j];
			}
			for (int j = 0; j < m->cols * m->rows; j++)
				m->values[j] = res.values[j];

			free_matrix(&res);
			free_matrix(&tmp);
		}
	}
}

int min_matrix(const matrix *m)
{
	int imin = 0;
	for (int i = 1; i < m->cols * m->rows; i++)
		if (m->values[i] < m->values[imin])
			imin = i;
	return imin;
}

void matrix_to_square(matrix *m)
{
	while (m->cols > m->rows)
	{
		int ind = min_matrix(m);
		rem_col(m, ind % m->cols);
	}
	while (m->cols < m->rows)
	{
		int ind = min_matrix(m);
		rem_row(m, ind / m->cols);
	}
}

void matrix_inflate(matrix *m, int s)
{
	while (m->rows < s && m->values) 
		add_row(m);
	while (m->cols < s && m->values) 
		add_col(m);
}