/****************************************************
 邱永臣叫西门追雪写个曾坤老师的一个程序。

 我早已和光明系的魔法少女失去了联系，这就是全部。
*****************************************************/

#include "LabelAlgorithm.h"
#include <iostream>
#include <time.h>
using namespace std;

int main() {
    LabelAlgorithm traver;
    //cin >> traver;
    cout << "你输入的矩阵如下：\n" << traver;
    traver.repeat();
    traver.showCapacityAndPath();
    return 0;
}
