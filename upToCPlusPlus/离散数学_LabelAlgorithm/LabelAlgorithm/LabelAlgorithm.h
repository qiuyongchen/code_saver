#ifndef LABELALGORITHM
#define LABELALGORITHM

#define MAXSIZE 100
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct vertice {
    int E;  // Ek is the minimum of Ej and the excess capacity ejk of
            // edge(j, k)............................................
            // Ej is the excess capacity e1j of edge(1, j)...........
            // E代表着能流过该节点的最大流。
    int reverseConnect;  // reverseConnect记录着该flow的上一个节点。
    bool haveBeenCollectedIn;  // true则表示该节点已经被丢入集合Ni之中。

    // default constructor.
    vertice(int e = 0, int r = 0, bool l = false) {
        E = e;
        reverseConnect = r;
        haveBeenCollectedIn = l;
    }
};

class LabelAlgorithm {
public:

    // 重载输出运算符。
    friend ostream& operator<<(ostream& out, LabelAlgorithm& a);

    // 重载输入运算符。
    friend istream& operator>>(istream& in, LabelAlgorithm& a);

    // constructor.
    LabelAlgorithm() {
        for (int i = 0; i < MAXSIZE; i++) {
            for (int j = 0; j < MAXSIZE; j++) {
                excessCapacity[i][j] = 0;
            }
            size_ = 0;
            verticeLabeled[i] = false;
        }
        NN = 1;


        /////////////////////////////////////////////
        size_ = 6;
        excessCapacity[0][1] = 5;
        excessCapacity[0][3] = 4;
        excessCapacity[1][2] = 3;
        excessCapacity[1][3] = excessCapacity[1][4] = 2;
        excessCapacity[2][5] = 3;
        excessCapacity[3][4] = 3;
        excessCapacity[4][5] = 4;
        ////////////////////////////////////////////
    }

    // 判断某节点是否已经被标记。
    bool itIsLabeled(int verticeI);

    // Step1: Let N1 be the set of all nodes connected to the source
    //        by an edge with positive excess capacity. Label each j
    //        in N1 with [Ej, 1], where Ej is the excess capacity e1j
    //        of edge(1, j). The 1 in the label indicates that j is
    //        connected to the source, node 1.
    //        在这里，我们用矩阵V的第一行来存储N1。
    void dealWithN1();

    // Step2: Let node j in N1 be the node with smallest node number
    //        and let N2(j) be the set of all unlabeled nodes, other
    //        than the source, that are joined to node j and have
    //        positive excess capacity. Suppose that node k is in N2(j)
    //        and (j, k) is the edge with positive excess capacity.
    //        Label node k with [Ek, j], where Ek is the minimum of Ej
    //        and the excess capacity ejk of edge (j, k). When all the
    //        nodes in N2(j) are labeled in this way, repeat this process
    //        for the other nodes in N1. Let N2 = new N2(j) U old N2(j).
    //        标记N1中的所有元素的下属，命令下属干苦活！
    // Step3: Repeat Step2, labeling all previously unlabeled nodes N3
    //        that can be reached from a node in N2 by an edge having
    //        positive excess capacity. Continue this process forming
    //        sets N4, N5,...until after a finite number of steps either
    //    (i) the sink has not been labeled and no other nodes can be
    //        labeled. It can happen that no nodes have been labeled;
    //        remember that the source is not labeled.
    //        or
    //    (ii)the sink has been labeled.
    void dealWithNi(int Ni);

    // 让俺瞧瞧“汇”是否已经被标记，若它被标记，俺就得刷新矩阵了。
    bool sinkHaveBeenLabeled();

    // 判断还有木有新的节点可以被标记。
    bool noFurtherLabeling(int Ni);

    // 刷新图对应的矩阵（额，实际上只是回溯那条该死的路径而已了，呵呵）
    // 不，我们还得要把那些标记的信息全部抹去（让它们离开这个痛苦的世界
    // 吧，死亡莲华！）
    void updateGraph();

    //  呃逆拖佛，你们不下地狱，谁下地狱，去吧。
    // 抹除所有的标记信息。
    void removeLabeling();

    // 总repeat, repeat到第一步，放下屠刀，重头再来。
    void repeat();

    // 终止总repeat, 在苦活中轮回，终得正果。
    bool ifTerminate();

    // 显示容量路径和总容量。
    void showCapacityAndPath();
private:

    // 记录每条边的剩余容量：excessCapacity[i][j]记录从节点i到节点j的
    // 剩余容量，excessCapacity[j][i]则记录从节点i到节点j的虚拟容量。
    int excessCapacity[MAXSIZE][MAXSIZE];

    // 记录矩阵的大小，也即是节点的个数。
    int size_;

    // 矩阵的第一行记录N1的标记信息，第二行记录N2的标记信息,以此类推。
    vertice V[MAXSIZE][MAXSIZE];

    // 记录某节点是否已被标记，若是已经被标记则不能再动它。
    bool verticeLabeled[MAXSIZE];

    // 在本算法中，思想是标记。
    // 我们从N1标记到N2到N3到Ni，于是用这个NN表示“我们即将要标记的Ni”。
    int NN;

    // 这个multimap被用来存储路径及路径对应的容量（容量为key，路径为vector<int>）
    unordered_multimap< int, vector<int> > capAndPath;
};

#endif
