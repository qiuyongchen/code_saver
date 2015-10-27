/*
  graphMatrix.cpp
  
*/
#include "graphMatrix.h"
#define SOBIG 99999999

// overloading the '<<' operator to print the matrix.
ostream& operator<<(ostream& out, const graphMatrix& g) {
    if (g.empty()) {
        cout << "The matrix is empty.";
    } else {
        cout << "the matrix is: \n";
        for (int i = 0; i < g.size(); i++) {
            // output '[' at the beginning.
            if (i != 0)
                out << " ";
            else
                out << "[";
            // output main 
            for (int j = 0; j < g.size(); j++) {
                out << " " << g.matrix[i][j];
            }
            // output ']' at the end.
            if (i != g.sizeOfMatrix - 1)
                out << endl;
            else
                out << " ]";
        }
    }
    out << endl;
    return out;
}

// overloading the '>>' operator to input the matrix.
istream& operator>>(istream& in, graphMatrix& g) {
    int temp;
    cout << "Please input the size of the matrix: \n";
    cin >> temp;
    // check of valid size.
    while (temp < MINSIZE || temp > MAXSIZE) {
        cout << "Please input the size that is valid of the matrix: \n";
        cin >> temp;
    }
    g.sizeOfMatrix = temp;
    g.sizeOfMatrixFCT = temp;
    for (int i = 0; i < g.size(); i++) {
        g.setOrEntry[i] = 0;
        g.storeVertext[i] = i;
    }
    if (g.empty()) {
        cout << "Warning! the matrix is empty.\n";
    } else {
        cout << "Please input the entries of the matrix:\n";
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g.size(); j++) {
                in >> temp;
                g.matrix[i][j] = temp;
                g.matrixFCT[i][j] = temp;
            }
        }
    }
    return in;
}

// constructor.
graphMatrix::graphMatrix() {
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++) {
            matrix[i][j] = 0;
            matrixFCT[i][j] = 0;
        }
        sizeOfMatrix = 0;
        sizeOfMatrixFCT = 0;
}

// ~deconstructor.
graphMatrix::~graphMatrix() {
}

// get the size of the matrix.
int graphMatrix::size() const  {
    return sizeOfMatrix;
}

// determinte if the matrix is empty.
bool graphMatrix::empty() const {
    return size() == 0;
}

// find the row of the smallest weight in the matrix,
// we notice that 0 represent the biggest weight.
int graphMatrix::smallestEntryRow() const {
    int smallest = SOBIG;
    int rowIndex = -1, columnIndex = -1;

    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            if (matrix[i][j] != 0)
                if (matrix[i][j] < smallest) {
                    rowIndex = i;
                    columnIndex = j;
                    smallest = matrix[i][j];
                }
        }
    }

    return rowIndex;
}

// find the column of the smallest weight in the matrix,
// we notice that 0 represent the biggest weight.
int graphMatrix::smallestEntryColumn() const {
    int smallest = SOBIG;
    int rowIndex = -1, columnIndex = -1;
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            if (matrix[i][j] != 0)
                if (matrix[i][j] < smallest) {
                    rowIndex = i;
                    columnIndex = j;
                    smallest = matrix[i][j];
                }
        }
    }
    return columnIndex;
}

// replace the main diagonal with the original entries of M, which is always 0.
void graphMatrix::replaceTheDiaGonal() {
    for (int i = 0; i < size(); i++)
        matrix[i][i] = 0;
}

void graphMatrix::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = *a;
}

// replace the two rows that represent two vertext.
void graphMatrix::replaceRow(int rowI, int rowJ) {
    if (rowJ < rowI)
        swap(&rowI, &rowJ);
    // replace row i with the join of row i and row j.
    for (int j = 0; j < size(); j++) {
        if (matrix[rowI][j] == matrix[rowJ][j] && matrix[rowI][j] == 0)
            matrix[rowI][j] = 0;
        else if (matrix[rowI][j] == 0 && matrix[rowJ][j] != 0)
            matrix[rowI][j] = matrix[rowJ][j];
        else if (matrix[rowJ][j] == 0 && matrix[rowI][j] != 0)
            matrix[rowI][j] = matrix[rowI][j];
        else
            matrix[rowI][j] = min(matrix[rowI][j], matrix[rowJ][j]);
    }
    // delete row j(warning! the 'sizeOfMatrix' doesn't change yet).
    for (int i = rowJ; i < size() - 1; i++)
        for (int j = 0; j < size(); j++) {
            matrix[i][j] = matrix[i + 1][j];
        }
}

// replace the two columns that represent two vertext.
void graphMatrix::replaceColumn(int colI, int colJ) {
    if (colJ < colI)
        swap(&colI, &colJ);
    // replace col i with the join of col i and col j.
    for (int i = 0; i < size(); i++) {
        if (matrix[i][colI] == matrix[i][colJ] && matrix[i][colI] == 0)
            matrix[i][colI] = 0;
        else if (matrix[i][colI] == 0 && matrix[i][colJ] != 0)
            matrix[i][colI] = matrix[i][colJ];
        else if (matrix[i][colJ] == 0 && matrix[i][colI] != 0)
            matrix[i][colI] = matrix[i][colI];
        else
            matrix[i][colI] = min(matrix[i][colI], matrix[i][colJ]);
    }
    // delete column j(warning! the 'sizeOfMatrix' doesn't change yet).
    for (int i = 0; i < size(); i++)
        for (int j = colJ; j < size() - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
}

// merge A and B.
void graphMatrix::mergeAB(int a, int b) {
    replaceRow(a, b);
    replaceColumn(a, b);
    replaceTheDiaGonal();
    sizeOfMatrix--;
}

// update the sets of original vertices that  is represented by each merged vertext.
void graphMatrix::updateSuperVertext() {

    // if the first vertext is not a set.
    if (!setOrEntry[smallestEntryRow()]) {
        superVertext[smallestEntryRow()].insert(storeVertext[smallestEntryRow()]);
    }

    // if the second vertext is not a set.
    if (!setOrEntry[smallestEntryColumn()]) {
        superVertext[smallestEntryRow()].insert(storeVertext[smallestEntryColumn()]);
    } else {
        set<int>::iterator it;
        // copy all the entry in the second set into the first one.
        for (it = superVertext[smallestEntryColumn()].begin();
            it != superVertext[smallestEntryColumn()].end(); ++it) {
                superVertext[smallestEntryRow()].insert(storeVertext[*it]);
        }
    }
    // to label the merged vertext set and delete the other one.
    setOrEntry[smallestEntryRow()] = 1;
    for (int j = smallestEntryColumn(); j < size() - 1; j++) {
        setOrEntry[j] = setOrEntry[j + 1];
        superVertext[j] = superVertext[j + 1];
        storeVertext[j] = storeVertext[j + 1];
    }
    
}

// select the edge represented by the minmal weight from one of the
// original vertices represented by A to one of the original vertices
// represented by B.
void graphMatrix::selectEdge() {
    int smallest = SOBIG;
    int row = -1, column = -1;

    // neither of the two is superVertext.
    if (!setOrEntry[smallestEntryRow()] && !setOrEntry[smallestEntryColumn()]) {
        // then we insert them into the edge set directly.
        edge.insert(pair<int, int> (storeVertext[smallestEntryRow()],
            storeVertext[smallestEntryColumn()]));
        
    // the first one is a superVertext now.
    } else if (setOrEntry[smallestEntryRow()] && !setOrEntry[smallestEntryColumn()]) {
        // the second one representes a vertext not a supervertext.
        column = smallestEntryColumn();
        set<int>::iterator it;
        for (it = superVertext[smallestEntryRow()].begin();
            it != superVertext[smallestEntryRow()].end(); ++it) {
                if (matrixFCT[*it][column] < smallest && matrixFCT[*it][column] != 0) {
                    smallest = matrixFCT[*it][column];
                    row = *it;
                }
        }
        edge.insert(pair<int, int>(storeVertext[row], storeVertext[column]));
        
    // the second one is a superVertext.
    } else if (!setOrEntry[smallestEntryRow()] && setOrEntry[smallestEntryColumn()]) {
        row = smallestEntryRow();
        set<int>::iterator it;
        for (it = superVertext[smallestEntryColumn()].begin();
            it != superVertext[smallestEntryColumn()].end(); ++it) {
                if (matrixFCT[row][*it] < smallest && matrixFCT[row][*it] != 0) {
                    smallest = matrixFCT[row][*it];
                    column = *it;
                }
        }
        edge.insert(pair<int, int>(storeVertext[row], storeVertext[column]));
        
    // unforturnately, all of the two are both supervertext.
    } else if (setOrEntry[smallestEntryRow()] && setOrEntry[smallestEntryColumn()]) {
        set<int>::iterator rowIt, columnIt;
        for (rowIt = superVertext[smallestEntryRow()].begin();
            rowIt != superVertext[smallestEntryRow()].end(); ++rowIt) {
                for (columnIt = superVertext[smallestEntryColumn()].begin();
                    columnIt != superVertext[smallestEntryColumn()].end(); ++columnIt) {
                        if (matrixFCT[*rowIt][*columnIt] < smallest &&
                            matrixFCT[*rowIt][*columnIt] != 0) {
                                smallest = matrixFCT[*rowIt][*columnIt];
                                row = *rowIt;
                                column = *columnIt;
                                
                        }
                }
        }
        //
        edge.insert(pair<int, int> (storeVertext[row], storeVertext[column]));

    }

}

// finally, we have to show all the edges of the minimal spanning
// tree that we construct.
void graphMatrix::showEdge() {
    cout << "the edge(s):\n";
    for (set< pair<int, int> >::iterator it = edge.begin();
        it != edge.end(); ++it) {
            char first = it->first + 'A';
            char second = it->second + 'A';
            cout << "( " << first << " , " << second << " )  ";
    }
    cout << endl;
}

// We have to repeat two things until a single vertex is obtained.
// First, we choose the smalleset entry in M, say Mij, Let A be the vertext
// that is represented by row i (smallestEntryRow()), Let B be the vertext
// that is represented by column j (smallestEntryColumn()).
// Second, we should merge A with B (mergeAB(int rowI, int rowJ).
//
// Before merging A and B, we should select the edge, or we will
// lost this infomation!
void graphMatrix::repeat() {
    while (size() > 1) {
        selectEdge();
        updateSuperVertext();
        mergeAB(smallestEntryRow(), smallestEntryColumn());
    }
}
