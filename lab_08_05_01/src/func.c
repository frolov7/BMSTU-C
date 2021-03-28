#include "../inc/func.h"
#include "../inc/struct.h"

void init_matrix(matrix *m)
{
	m->values = malloc(m->cols * m->rows * sizeof(int));
}

void free_matrix(matrix *m)
{
	free(m->values);
	m->values = NULL;
}

void rem_row(matrix *m, int r)
{
	int p = 0;
	for (int i = 0; i < m->cols * m->rows; i++)
		if (i / m->cols != r)
			m->values[p++] = m->values[i];
	m->rows--;
}

void rem_col(matrix *m, int c)
{
	int p = 0;
	for (int i = 0; i < m->cols * m->rows; i++)
		if (i % m->cols != c)
			m->values[p++] = m->values[i];
	m->cols--;
}

void add_row(matrix *m)
{
	int *tmp = realloc(m->values, (m->rows + 1) * m->cols * sizeof(int));
	if (!tmp)
		free_matrix(m);
	else
	{
		m->values = tmp;
		for (int x = 0; x < m->cols; x++)
		{
			double res = 1;
			for (int y = 0; y < m->rows; y++)
				res *= m->values[y * m->cols + x];
			m->values[m->rows * m->cols + x] = (int)floor(pow(res, 1.0 / m->rows));
		}
		m->rows++;
	}
}

void add_col(matrix *m)
{
	int *tmp = realloc(m->values, m->rows * (m->cols + 1) * sizeof(int));
	if (!tmp)
		free_matrix(m);
	else
	{
		m->values = tmp;

		for (int y = m->rows - 1; y >= 0; y--)
		{
			for (int x = m->cols - 1; x >= 0; x--)
			{
				m->values[y * (m->cols + 1) + x] = m->values[y * m->cols + x];
			}
		}
		m->cols++;

		for (int y = 0; y < m->rows; y++)
		{
			int max = m->values[y * m->cols];
			for (int x = 1; x < m->cols - 1; x++)
				if (m->values[y * m->cols + x] > max)
					max = m->values[y * m->cols + x];
			m->values[y * m->cols + m->cols - 1] = max;
		}
	}
}
