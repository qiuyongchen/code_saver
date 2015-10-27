// Created by YongchenQiu.
// For WARSHALL, to show my respect.
// Algorithm WARSHALL, it is, em, good.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *matrix;
  int *matrixColumn;
  int *matrixRow;
  int vertrix;
  int i, j, k;

  printf("欢迎来到WALLSHALL世界，请输入矩阵行（列）数：\n");
  scanf("%d", &vertrix);

  // mallocing memory.
  matrix = (char *)malloc(vertrix * vertrix * sizeof(int));
  if (matrix == NULL) {
    printf("mallocing wrong!\n");
    exit(1);
  }

  // mallocing memory.
  matrixColumn = (char *)malloc(vertrix * sizeof(int));
  if (matrixColumn == NULL) {
    printf("mallocing wrong!\n");
    exit(1);
  }
  // mallocing memory.
  matrixRow = (char *)malloc(vertrix * sizeof(int));
  if (matrixRow == NULL) {
    printf("mallocing wrong!\n");
    exit(1);
  }


  printf("嗯，加油，再输入一些就可以看到伟大的真理了哦，\n（亲，麻烦逐行输入矩阵元素一下下）：\n");

  // get the element of matrix arrey.
  for (i = 0; i < vertrix * vertrix; i++)
    scanf("%d", &matrix[i]);

  // the main algorithm of WARSHALL.
  for (k = 0; k < vertrix; k++) {

    // initialize the matrixTemp to NULL.
    for (i = 0; i < vertrix; i++) {
      matrixColumn[i] = 0;
      matrixRow[i] = 0;
    }

    // get the element of matrixTemp(to the first column).
    for (i = k; i < vertrix * vertrix; i += vertrix) {
      if (matrix[i] == 1)
	matrixColumn[(i - k) / vertrix] = 1;
    }

    // get the element of matrixTemp(to the first row).
    for (i = k * vertrix; i < (k + 1) * vertrix; i++) {
      if (matrix[i] == 1)
	matrixRow[i % vertrix] = 1;
    }

    // take the element in matrixTemp into matrix.
    for (i = 0; i < vertrix; i++) {

      if (matrixColumn[i] == 1) {

        for (j = 0; j < vertrix; j++) {

	  if (matrixRow[j] == 1) {
	    matrix[i * vertrix + j] = 1;
	  }

	}
      }
    }


  }

  printf("你的计算机堪比天河二号！答案是：\n");

  for (i = 0; i < vertrix * vertrix; i++) {
    printf("%d ", matrix[i]);
    if ((i + 1) % vertrix == 0)
      printf("\n");
  }

  free(matrix);
  matrix = NULL;

  return 0;
}
