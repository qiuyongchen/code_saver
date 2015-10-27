#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
using namespace std;

ostream& operator<<(ostream& out, const Matrix& matrix) {
  out << "-----------------------------" << endl;

  for (int i = 0; i < 4; i++) {
    out << "|";

    for (int j = 0; j < 4; j++) {
      char temp = ' ';

      if (matrix.num[i][j] > 0)
        out << setw(6) << right << matrix.num[i][j] << "|";
      else
        out << setw(6) << right << temp << "|";

    }

    out << endl;
  }

  out << "-----------------------------" << endl;
}

Matrix::Matrix(int p1, int p2) {
  // initialize the array.
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      num[i][j] = 0;
    }
  }
  // assign to the two positions special values.
  num[p1 / 4][p1 % 4] = 2;
  num[p2 / 4][p2 % 4] = 2;
}

bool Matrix::moveLeft() {
  int check[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      check[i][j] = num[i][j];
    }
  }

  // deal with the four rows.
  for (int i = 0; i < 4; i++) {
    deque<int> temp;
    deque<int> save;
    // to get the deque which refer to the changed array.
    for (int j = 0; j < 4; j++) {

      // if 'num[i][j] == 0', we ignore it.
      if (num[i][j] > 0) {

        // for doubling the value.
        if ((temp.size() > 0) && (temp.back() == num[i][j])
            && (save.back() != 1)) {
          temp.pop_back();
          temp.push_back(2 * num[i][j]);
	  save.push_back(1);
        } else {
          temp.push_back(num[i][j]);  // or just copy that.
          save.push_back(0);
        }
        num[i][j] = 0;  // remove the original value.
      }

    }  // uptill now we have got the deque.

    // reassign the row array.
    int j = 0;
    while (temp.size() > 0) {
      num[i][j] = temp.front();
      temp.pop_front();
      j++;
    }

  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (check[i][j] != num[i][j])
        return true;
    }
  }
  return false;

}

bool Matrix::moveRight() {
  int check[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      check[i][j] = num[i][j];
    }
  }

  // deal with the four rows.
  for (int i = 0; i < 4; i++) {
    deque<int> temp;
    deque<int> save;
    // to get the deque which refer to the changed array.
    for (int j = 3; j >=0; j--) {

      // if 'num[i][j] == 0', we ignore it.
      if (num[i][j] > 0) {

        // for doubling the value.
        if ((temp.size() > 0) && (temp.back() == num[i][j])
            && (save.back() != 1)) {
          temp.pop_back();
          temp.push_back(2 * num[i][j]);
          save.push_back(1);
        } else {
          temp.push_back(num[i][j]);  // or just copy that.
          save.push_back(0);
        }
        num[i][j] = 0;  // remove the original value.
      }

    }  // uptill now we have got the deque.

    // reassign the row array.
    int j = 3;
    while (temp.size() > 0) {
      num[i][j] = temp.front();
      temp.pop_front();
      j--;
    }

  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (check[i][j] != num[i][j])
        return true;
    }
  }
  return false;

}

bool Matrix::moveUp() {
  int check[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      check[i][j] = num[i][j];
    }
  }

  // deal with the four column.
  for (int j = 0; j < 4; j++) {
    deque<int> temp;
    deque<int> save;

    // to get the deque which refer to the changed array.
    for (int i = 0; i < 4; i++) {

      // if 'num[i][j] == 0', we ignore it.
      if (num[i][j] > 0) {

        // for doubling the value.
        if ((temp.size() > 0) && (temp.back() == num[i][j])
            && (save.back() != 1)) {
          temp.pop_back();
          temp.push_back(2 * num[i][j]);
          save.push_back(1);
        } else {
          temp.push_back(num[i][j]);  // or just copy that.
          save.push_back(0);
        }
        num[i][j] = 0;  // remove the original value.
      }

    }  // uptill now we have got the deque.

    // reassign the row array.
    int i = 0;
    while (temp.size() > 0) {
      num[i][j] = temp.front();
      temp.pop_front();
      i++;
    }

  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (check[i][j] != num[i][j])
        return true;
    }
  }
  return false;

}

bool Matrix::moveDown() {
  int check[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      check[i][j] = num[i][j];
    }
  }

  // deal with the four column.
  for (int j = 0; j < 4; j++) {
    deque<int> temp;
    deque<int> save;
    // to get the deque which refer to the changed array.
    for (int i = 3; i >= 0; i--) {

      // if 'num[i][j] == 0', we ignore it.
      if (num[i][j] > 0) {

        // for doubling the value.
        if ((temp.size() > 0) && (temp.back() == num[i][j])
            && (save.back() != 1)) {
          temp.pop_back();
          temp.push_back(2 * num[i][j]);
          save.push_back(1);
        } else {
          temp.push_back(num[i][j]);  // or just copy that.
          save.push_back(0);
        }
        num[i][j] = 0;  // remove the original value.
      }

    }  // uptill now we have got the deque.

    // reassign the row array.
    int i = 3;
    while (temp.size() > 0) {
      num[i][j] = temp.front();
      temp.pop_front();
      i--;
    }

  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (check[i][j] != num[i][j])
        return true;
    }
  }
  return false;

}

bool Matrix::add(int p) {
  if (num[p / 4][p % 4] > 0) {
    return false;
  } else {
    num[p / 4][p % 4] = 2;
    return true;
  }
}
