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
     void mergeAB(int a, int b);
     void swap(int *a, int *b);
     void replaceRow(int rowI, int rowJ);
     void replaceColumn(int columnI, int columnJ);
     void replaceTheDiaGonal();
     void updateSuperVertext();
     void selectEdge();
     void showEdge();
     void repeat();
 private:
     // 记录矩阵信息，当两个顶点合并后，这个矩阵的sizoOfMatrix的大小会减小1.
     int matrix[MAXSIZE][MAXSIZE];

     // matrixForConstructTree,同样记录矩阵信息，但是它永远不变，因为我们
     // 要用它来查找原始‘顶点’之间的权重，
     // 以便重建spanning tree.
     int matrixFCT[MAXSIZE][MAXSIZE];

     // matrix的size.
     int sizeOfMatrix;

     // matirxFCT的size.
     int sizeOfMatrixFCT;
     
     /********************************************************************
     /* 我们知道，当两个节点合并后，它们就会形成一个新的节点，这个新的节点代表了
     /* 一个set，在这里，我们将之称为宇宙无敌超级大节点，即所谓的superVertext.
     /* 警惕！！！！下面三项均用来记录“变化后的矩阵“！！！！！！！！！！！！！
     /*******************************************************************/

     // if setOrEntry[i] == 1, then vertext represented by column i or column i
     // is a set, which is named 'superVertext'.
     // 下面这个数组被用来表示 “变化后的矩阵”的各列是否为set.
     int setOrEntry[MAXSIZE];

     // 节点合并后形成set，下面这个set数组被用来表示 “变化后的矩阵”的各列所代表的set.
     array<set<int>, MAXSIZE> superVertext;

     // 两个节点合并之后，矩阵中的元素位置发生变化，比如第一列和第二列合并，原先的
     // 第3列（代表着节点C)，现在被迫成为第二列（代表着节点B), 即节点错位了。

     // 为了防止节点错位，我们用下面这个数组来纠正：
     // 一开始时storeVertext[i] == i,比如storeVertext[3] == 3, 这表示矩阵的第四列
     // 代表D, 后来节点间合并，storeVertext[3]的值被前移到storeVertext[2]中，
     // storeVertext[2] == 3，这表示矩阵的第三列代表D。

     // 这样一来，就算节点合并了，我们依旧可以知道"变化后的矩阵"各列代表哪个节点。
     int storeVertext[MAXSIZE];

     // 记录edge，值得注意的是，当顶点被合并之后，原始graph的edge信息
     // 就丢失了。所以我们构建上面的matrixFCT来封印原graph，避免它发生改变。
     set< pair<int, int> > edge;
};
