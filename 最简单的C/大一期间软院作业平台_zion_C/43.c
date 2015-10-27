/*Created by wlxead
  all right reserved.
  额，好像函数原型可以放在任意地方耶。。
*/
#include <stdio.h>


int main() {
    int R(int n);
    int S(int s);
    printf("%d", R(7));
    return 0;
}


int R(int n) {
    return S(n);
}


int S(int s) {
    return s + 10;
}
