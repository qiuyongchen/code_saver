/*
  graphMatrix.h
  
*/
#include <iostream>
#include <array>
#include <set>
#include <vector>
#define MAXSIZE 100
#define MINSIZE 0
using namespace std;

class graphMatrix {
 public:
     friend ostream& operator<<(ostream& out, const graphMatrix& g);
     friend istream& operator>>(istream& in, graphMatrix& g);
     graphMatrix();
     ~graphMatrix();
     int size() const;
     bool empty() const;
     int smallestEntryRow() const;
     int smallestEntryColumn() const;
     void selectEdgeOfLeastWeight(int verA, int verB);
     void replaceSetOfEdges(int verA, int verB);
     bool itMakesACycle(int verA, int verB);
     void initEdgeMatrix();
     void constructEdgeMatrix(int verA, int verB);
     void findConnectComponents();
     bool scanAllRow();
     bool Cycle();
     void showEdge();
     void repeat();
     void showstep();
 private:
     // 记录图对应的矩阵信息
     int matrix[MAXSIZE][MAXSIZE];
     int sizeOfMatrix;

     // 记录已经被选出来的edge
     set< pair<int, int> > edge;

     // 在不知道某条边是否会形成环的情况下，我们把它和之前选出来的边放在
     // 下面这个矩阵中，进而找出“加入该条边”之后形成的连通部分
     int edgeMatrix[MAXSIZE][MAXSIZE];

     // 采用逐行扫描的方式来构建出“不同的连通部分”
     bool hasScanRow[MAXSIZE];

     // 下面是一个以集合为元素的数组，一个元素代表着一个连通部分
     array< set<int>, MAXSIZE> connectGraph;
};
