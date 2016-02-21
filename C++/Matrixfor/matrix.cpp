#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(const Matrix& otherMatrix) {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      m[i][j] = otherMatrix.m[i][j];
    }
  }

}

void Matrix::setElement(int x, int y, int value) {
  m[x][y] = value;
}

Matrix Matrix::multiply(const Matrix& otherMatrix) {
  Matrix temp(N);

  for (int i = 0; i < N; i++) {

    for (int j = 0; j < N; j++) {

      int tttt = 0;

      for(int k = 0; k < N; k++) {
	tttt += m[i][k] * otherMatrix.m[k][j];
      }

      temp.setElement(i, j, tttt);

    }

  }

  return temp;

}

Matrix Matrix::transposition() {
  Matrix temp(N);

  for (int i = 0; i < N; i++) {

    for (int j = 0; j < N; j++) {
      temp.setElement(i, j, m[j][i]);
    }

  }

  return temp;
}

void Matrix::print() {
  for (int i = 0; i < N; i++) {

    for (int j = 0; j < N; j++) {
      cout << m[i][j];

      if (j < N -1) {
	cout << " ";
      }

    }

    cout << endl;
  }

}
