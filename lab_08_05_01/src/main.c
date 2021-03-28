#include "../inc/matrix.h"
#include "../inc/func.h"
#include "../inc/struct.h"

matrix read_matrix()
{
	matrix m;
	m.values = NULL;
	if (scanf("%d%d", &m.rows, &m.cols) == 2 && m.rows > 0 && m.cols > 0)
	{
		init_matrix(&m);
		if (m.values)
		{
			for (int i = 0; i < m.cols * m.rows; i++)
			{
				if (scanf("%d", m.values + i) != 1)
				{
					free_matrix(&m);
					break;
				}
			}
		}
	}
	return m;
}

void write_matrix(matrix m)
{
	for (int y = 0; y < m.rows; y++)
	{
		for (int x = 0; x < m.cols; x++)
		{
			printf("%-3d ", m.values[y * m.cols + x]);
		}
		printf("\n");
	}
}

int main()
{
	int exit_code = 0;

	matrix a = read_matrix();
	if (a.values)
	{
		matrix b = read_matrix();
		if (b.values)
		{
			int r, g;
			if (scanf("%d%d", &r, &g) == 2 && r >= 0 && g >= 0)
			{
				matrix_to_square(&a);
				matrix_to_square(&b);
				if (a.rows < b.rows) 
					matrix_inflate(&a, b.rows);
				if (a.values)
				{
					if (b.rows < a.rows) 
						matrix_inflate(&b, a.rows);
					if (b.values)
					{
						power_matrix(&a, r);
						if (a.values)
						{
							power_matrix(&b, g);
							if (b.values)
							{
								matrix c;
								c.cols = a.cols;
								c.rows = a.rows;
								init_matrix(&c);
								multiply_matrix(&a, &b, &c);
								if (c.values)
								{
									write_matrix(c);
									free_matrix(&c);
								}
								else 
									exit_code = 1;
							}
							else 
								exit_code = 1;
						}
						else 
							exit_code = 1;
					}
					else 
						exit_code = 1;
				}
				else 
					exit_code = 1;
			}
			else 
				exit_code = 1;

			free_matrix(&b);
		}
		else 
			exit_code = 1;

		free_matrix(&a);
	}
	else 
		exit_code = 1;

	return exit_code;
}