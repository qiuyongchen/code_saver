Description:


子圭大神由于妹子太多，为了不把给某个妹子的信息发到另外一个妹子手里，就买了许多个土豪金(编号1，2……)；
某天子圭大神心血来潮，想要知道自己的哪个妹子最爱他，于是想要知道那个妹子和他发信息最多；
由于子圭大神不会数数，所以需要你帮忙；
请写一个程序，帮助出子圭大神计算出短信量最多的手机编号(有数量相同则取编号最小的那个)；
输入： 第一行为一个整数N(N <= 32767)表示土豪金个数;
第二至N+1行每行都有两个整数an，bn(an <= N, bn <= 2,147,483,647)分别表示手机编号以及手机信息数;
输出： 输出只有一行，即存储信息最多的手机的编号；
输入输出样例：
输入：
3
1 7
2 99
3 100
输出：
3

Hint:

#include <stdio.h>

int main() {
  int t;  // how many numbers do you want,guy
  int PhoneNum[10000];
  int PhoneMsgNum[10000];
  int temp = 1;  // run one by one
  int MsgMostNum = 0;
  int PhoneMsgMostNum;
  scanf("%d", &t);
  while (temp <= t) {
    scanf("%d%d", &PhoneNum[temp], &PhoneMsgNum[temp]);
    temp++;
  }

  // run every number one by one
  temp = t;
  while (temp >= 1) {
    if (PhoneMsgNum[temp] >= MsgMostNum) {
      MsgMostNum = PhoneMsgNum[temp];
      PhoneMsgMostNum = PhoneNum[temp];
    }
    temp--;
  }
  printf("%d\n", PhoneMsgMostNum);
  return 0;
}

