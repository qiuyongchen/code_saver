#include "LabelAlgorithm.h"

// 重载输出运算符。
ostream& operator<<(ostream& out, LabelAlgorithm& a) {
    out << "[\n";
    for (int i = 0; i < a.size_; i++) {
        for (int j = 0; j < a.size_; j++) {
            out << a.excessCapacity[i][j] << " ";
        }
        out << endl;
    }
    out << "]" << endl;
    return out;
}

// 重载输入运算符。
istream& operator>>(istream& in, LabelAlgorithm& a) {
    cout << "输入网络的矩阵的大小:";
    in >> a.size_;
    cout << "输入网络的矩阵:" << endl;
    for (int i = 0; i < a.size_; i++) {
        for (int j = 0; j < a.size_; j++) {
            in >> a.excessCapacity[i][j];
        }
    }
    return in;
}

// 判断某节点是否已经被标记。
bool LabelAlgorithm::itIsLabeled(int verticeI) {
    return verticeLabeled[verticeI];
}

// Step1: Let N1 be the set of all nodes connected to the source
//        by an edge with positive excess capacity. Label each j
//        in N1 with [Ej, 1], where Ej is the excess capacity e1j
//        of edge(1, j). The 1 in the label indicates that j is
//        connected to the source, node 1.
//        在这里，我们用矩阵V的第一行来存储N1。
void LabelAlgorithm::dealWithN1() {

    for (int i = 0; i < size_; i++) {
        // 把那些和"源“有奸情的家伙全部标记，送派出所。
        if (excessCapacity[0][i] > 0 && !verticeLabeled[i]) {
            verticeLabeled[i] = true;
            V[0][i].E = excessCapacity[0][i];
            V[0][i].reverseConnect = 0;
            V[0][i].haveBeenCollectedIn = true;
        }
    }
}

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
void LabelAlgorithm::dealWithNi(int Ni) {
    // 遍历Ni-1,把那些已经被丢入Ni-1中的节点的下一代子”合格“节点全部标记。
    for (int i = 0; i < size_; i++) {
        // 找出被丢入Ni-1中的节点。
        if (V[Ni - 1][i].haveBeenCollectedIn) {
            // 逐个遍历这些被丢入Ni-1的节点的子节点，试图标记它们。
            for (int j = 0; j < size_; j++) {
                // 如果该节点与下一代有”正能量“相连且其下一代子节点没被标记，
                // 则我们为了人类的和平，将其标记........
                if (excessCapacity[i][j] > 0 && !itIsLabeled(j)) {
                    verticeLabeled[j] = true;
                    V[Ni][j].E = (excessCapacity[i][j] < V[Ni - 1][i].E) ?
                        excessCapacity[i][j] : V[Ni - 1][i].E;
                    V[Ni][j].reverseConnect = i;
                    V[Ni][j].haveBeenCollectedIn = true;
                }
            }
        }
    }
}

// 让俺瞧瞧“汇”是否已经被标记，若它被标记，俺就得刷新矩阵了。
bool LabelAlgorithm::sinkHaveBeenLabeled() {
    return verticeLabeled[size_ - 1];
}

// 判断还有木有新的节点可以被标记并丢入Ni中。
bool LabelAlgorithm::noFurtherLabeling(int Ni) {
    for (int i = 0; i < size_; i++) {
        if (V[Ni - 1][i].haveBeenCollectedIn) {
            for (int j = 0; j < size_; j++) {
                if (excessCapacity[i][j] > 0 && !itIsLabeled(j))
                    return false;
            }
        }
    }
    return true;
}

// 刷新图对应的矩阵（额，实际上只是回溯那条该死的路径而已了，呵呵）
// 不，我们还得要把那些标记的信息全部抹去（让它们离开这个痛苦的世界
// 吧，死亡莲华！）
void LabelAlgorithm::updateGraph() {
    int account = 0;
    int rever;
    int current = size_ - 1;  // 当前节点。
    int Ni;  // 记录sink被丢入Ni
    // 既然sink已经被标记，我们现在的任务是得到流入sink的容量和上一个节点。
    for (int i = 0; i < size_; i++) {
        if (V[i][size_ - 1].haveBeenCollectedIn) {
            account = V[i][size_ - 1].E;  // 得到容量。
            rever = V[i][size_ - 1].reverseConnect;  // 得到上一个节点。
            Ni = i;  // 得到Ni的具体值。
            break;
        }
    }

    vector<int> temp;
    temp.push_back(current + 1);  // 把路径上的节点全堆进vector中
    temp.push_back(rever + 1);  // 把路径上的节点全堆进vector中
    cout << "容量为" << account << "的路径（逆序）：";
    cout<< current + 1 << "<-" << rever + 1;

    // 更改上一个节点和当前节点之间的路径容量。
    excessCapacity[rever][current] -= account;
    excessCapacity[current][rever] += account;

    // 一直要回溯到”源“
    while (rever != 0) {
        // 返回到上一个节点。
        for (int i = 0; i < size_; i++) {
            if (V[i][rever].haveBeenCollectedIn) {
                current = rever;
                rever = V[i][rever].reverseConnect;
                cout << "<-" << rever + 1;
                temp.push_back(rever + 1);  // 把路径上的节点全堆进vector中

                excessCapacity[rever][current] -= account;
                excessCapacity[current][rever] += account;
                break;
            }
        }
    }
    capAndPath.insert(make_pair(account, temp));
    cout << endl;
    // 接下来便可以放心地抹除标记信息了。
    removeLabeling();
    cout << "剔除该路径后的矩阵图：\n";
    cout << *this << endl ;
}

//  呃逆拖佛，你们不下地狱，谁下地狱，去吧。
// 抹除所有的标记信息。
void LabelAlgorithm::removeLabeling() {
    for (int i = 0; i < size_; i++) {

        for (int j = 0; j < size_; j++) {
            V[i][j].E = 0;
            V[i][j].reverseConnect = 0;
            V[i][j].haveBeenCollectedIn = false;
        }

        verticeLabeled[i] = false;
    }
}

// 总repeat, repeat到第一步，放下屠刀，重头再来。
void LabelAlgorithm::repeat() {
    // 先标记第一代。
    dealWithN1();

    while (!ifTerminate()) {
        NN = 1;

        // 一直在那里标记不停（NN代表第n个容纳被标记者的集合)，直到sink被标记或
        // 算法必须停止。
        while (!sinkHaveBeenLabeled() && !ifTerminate()) {
            dealWithNi(NN);
            NN++;
        }
        // 当标记过程被迫停止时，如果是sink被标记了，那就刷新矩阵，抹除标记，回到
        // 第一步。
        if (sinkHaveBeenLabeled()) {
            updateGraph();
            // 先标记第一代。
            dealWithN1();
            NN = 1;
            continue;
            // 如果是算法停止，则跳出循环即可。
        } else {
            break;
        }
    }
}

// 终止总repeat, 在苦活中轮回，终得正果。
bool LabelAlgorithm::ifTerminate() {
    return (!sinkHaveBeenLabeled() && noFurtherLabeling(NN));
}

// 显示容量路径和总容量。
void LabelAlgorithm::showCapacityAndPath() {
    int sumOfcapacity = 0;
    int sum = 1;
    for (unordered_multimap< int, vector<int> >::iterator it = capAndPath.begin();
        it != capAndPath.end(); ++it) {
            sumOfcapacity += it->first;
            cout << sum++ <<". 容量为" << it->first << "的路径: ";
            for (vector<int>::reverse_iterator itt = it->second.rbegin();
                itt != it->second.rend(); ++itt) {
                    cout << " -> " << *itt;
            }
            cout << endl;
    }
    cout << "最大流量为：" << sumOfcapacity << endl << endl;
}
