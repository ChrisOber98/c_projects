#include <stdio.h>

void print_matrix(const int matrix[3][3]);
void calc_addition(const int matrix_1[3][3], const int matrix_2[3][3]);

int main(int argc, char ** argv)
{
	int matrix_1[3][3] = 
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int matrix_2[3][3] = 
	{
		{9, 8, 7},
		{6, 5, 4},
		{3, 2, 1}
	};

	calc_addition(matrix_1, matrix_2);
	return 0;
}

void print_matrix(const int matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%d ", matrix[i][j]); 
		}
		printf("\n");
	}
}

void calc_addition(const int matrix_1[3][3], const int matrix_2[3][3])
{
	printf("Calcing Addition for: \n");
	print_matrix(matrix_1);
	printf("\n");
	print_matrix(matrix_2);
	printf("\n");
	printf("Result: \n");

	int new_matrix[3][3] = {};

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			new_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}

	print_matrix(new_matrix);
}
