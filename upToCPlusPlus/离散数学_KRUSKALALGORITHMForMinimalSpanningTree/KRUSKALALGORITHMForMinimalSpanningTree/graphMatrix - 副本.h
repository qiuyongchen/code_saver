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
 private:
     // º«¬ºæÿ’Û–≈œ¢
     int matrix[MAXSIZE][MAXSIZE];
     int sizeOfMatrix;
     set< pair<int, int> > edge;
     //

     int edgeMatrix[MAXSIZE][MAXSIZE];
     bool hasScanRow[MAXSIZE];
     array< set<int>, MAXSIZE> connectGraph;
};
