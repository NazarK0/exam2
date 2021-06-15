#include <stdio.h>

int main()
{
  char *filename = "new_matrix.dat";
  int *matrix;
  int matrix_size;

do
{
  printf("Розмір матриці:");
  scanf("%d", &matrix_size);
} while (matrix_size != NULL && matrix_size % 2 != 0);

matrix = malloc(matrix_size * sizeof(int) * 2);

// вводимo числа в массив
    for(int i=0;i<matrix_size; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        printf("елемент[%d][%d]=", i, j);
        scanf("%d", &matrix[i * 2 + j]);
      }
    }

  // міняємо рядки місцями
  int tmp_matrix[matrix_size * 2];

  for(int i=0;i<matrix_size; i++)
    {
      tmp_matrix[i * 2 + 0] = matrix[i * 2 + 1];
      tmp_matrix[i * 2 + 1] = matrix[i * 2 + 0];
    }

  // записуємо в файл
  write(filename, tmp_matrix, sizeof(int));

  free(matrix);
  return 0;
}