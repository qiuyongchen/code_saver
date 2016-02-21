#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
  public:
    explicit Matrix(int n = 0) { N = n; }
    // constructor，n is number of line and column
    Matrix(const Matrix& otherMatrix);
    // copy constructor
    void setElement(int x, int y, int value);
    // set element m[x][y] to value
    Matrix multiply(const Matrix& otherMatrix);
    // multiply two matrices
    Matrix transposition();
    // return the transposition of current matrix
    void print();
    // print the matrix, each line is terminated by a new line
    // neighbor elements in the same line is seperated by a single blank
  private:
    int m[50][50];
    // max number of line is 50
    int N;
    // the number of line equals to that of column
};
#endif
