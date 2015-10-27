#include <tvmet/Matrix.h>
#include <tvmet/Vector.h>
#include "tvmet/VectorFunctions.h"
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace tvmet;

int main() {
  Vector<int, 3> vecOne;
  Vector<int, 3> vecTwo;
  Vector<int, 3> vecTemp;
  Matrix<int, 4, 3> matOne;
  Matrix<int, 4, 3> matTwo;
  Matrix<int, 4, 3> matTemp;
  srand(time(NULL));

  // to the items of 'vecOne'.
  for (int i = 0; i < 3; i++) {
    vecOne[i] = rand() % 100;
  }

  cout << "The items of 'vecOne' are:" << endl;
  cout << vecOne << endl;

  // to the items of 'vecTwo.
  for (int i = 0; i < 3; i++) {
    vecTwo[i] = rand() % 100;
  }

  cout << "The items of 'vecTwo' are:" << endl;
  cout << vecTwo << endl;

  // those operation.
  cout << "The items of the addition of 'vecOne' and 'vecTwo are:" << endl;
  vecTemp = vecOne + vecTwo;
  cout << vecTemp << endl;

  cout << "The items of the subtraction of 'vecOne' and 'vecTwo are:" << endl;
  vecTemp = vecOne - vecTwo;
  cout << vecTemp << endl;

  cout << "The items of the inner product of 'vecOne' and 'vecTwo are:" << endl;
  vecTemp = vecOne * vecTwo;
  cout << vecTemp << endl;

  cout << "The items of the inner product of 'vecOne' and 'vecTwo are:" << endl;
  cout << cross(vecOne, vecTwo) << endl;

  cout << "The items of the inner product of 'vecTwo' and 'vecOne are:" << endl;
  cout << cross(vecTwo, vecOne) << endl;

  // MATRIX.
  cout << "The items of 'matOne' are:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      matOne(i, j) = rand() % 100;
    }
  }
  cout << matOne << endl;

  // MATRIX.
  cout << "The items of 'matTwo' are:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      matTwo(i, j) = rand() % 100;
    }
  }
  cout << matTwo << endl;

  // matrix addition.
  cout << "The items of addition of 'matOne' and 'matTwo' are:" << endl;
  matTemp = matOne + matTwo;
  cout << matTemp << endl;

  // matrix subtraction.
  cout << "The items of subtraction of 'matOne' and 'matTwo' are:" << endl;
  matTemp = matOne - matTwo;
  cout << matTemp << endl;

  // element-wise multiplication.
  cout << "The items of 'matOne' are:" << endl;
  cout << matOne << endl;

  cout << "The items of '3 * vecOne' are:" << endl;
  matTemp = matOne * 3;
  cout << matTemp << endl;

  // element-wise division.
  cout << "The items of 'matTwo' are:" << endl;
  cout << matTwo << endl;

  cout << "The items of 'vecTwo / 3' are:" << endl;
  matTemp = matTwo / 3.0;
  cout << matTemp << endl;

  // matrix-vector multiplication.
  cout << "The items of 'matOne * vecOne' are:" << endl;
  Vector<int, 4> vtt(0);
  vtt = prod(matOne, vecOne);
  cout << vtt << endl;

  return 0;
}
