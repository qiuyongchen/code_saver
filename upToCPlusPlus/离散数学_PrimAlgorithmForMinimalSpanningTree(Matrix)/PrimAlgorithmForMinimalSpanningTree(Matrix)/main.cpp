/*
  main.cpp

  PRIM'S ALGORITHM

  Implemented by SomebodyWho

  For 我可爱的小红叶.

  (邱永臣的第一个超过400行的程序）

*/
#include "graphMatrix.h"
#include <iostream>
using namespace std;

int main() {
    graphMatrix matrixForPrim;
    cin >> matrixForPrim;
    cout << matrixForPrim;
    matrixForPrim.repeat();
    matrixForPrim.showEdge();
    return 0;
}