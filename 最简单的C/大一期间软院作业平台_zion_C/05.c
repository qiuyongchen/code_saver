Description:

我们这个教室里面有两个班，假设两个班里分别有n名，m名同学。现在给出每个同学的成绩，请问哪个班的平均成绩分别是多少，哪个班的平均成绩更高。
因为软件学院里面有很多的教务班，所以我们会进行多次询问。
【输入格式】
第一行仅一个整数t（t<10），表示询问的次数。
对于每一次询问，第一行有两个整数n,m，(n,m<100)；第二行有n个整数，表示第一个班级n个同学的成绩；第三行有m个整数，表示第二个班级m个同学的成绩。（0<=成绩<=100）
【输出格式】
共2t行。对于每一次询问，输出两行，第一行有两个小数，分别表示两个班的平均成绩（保留两位小数），中间用一个空格隔开。第二行输出一个单词，如果第一个班级的平均成绩高于第二个班级，则输出“More”，如果两个班级平均成绩相等，则输出“Equal”，如果第一个班级的平均成绩小于第二个，则输出“Less”。
注意，比较两个班成绩大小的时候，我们比较的是它的真实值而不是保留两位小数以后的值，比如说1/3和0.33虽然保留两位小数以后都是0.33，但是我们判断1/3>0.33。
【输入样例】
3
3 5
100 100 100
1 2 3 4 5
2 3
100 96
99 98 97 
3 3
1 1 2
1 1 3
【输出样例】
100.00 3.00
More
98.00 98.00
Equal
1.33 1.67
Less

Hint:

#include <stdio.h>
int main() {
  int Num;
  int TOne[100][100], TTwo[100][100];
  int Temp = 1;
  int BigTemp = 1;
  int ClassOne[100], ClassTwo[100];
  float EvClassOne[100], EvClassTwo[100];
  float SumClassOne[100], SumClassTwo[100];
  scanf("%d", &Num);
  while (BigTemp <= Num) {
    Temp = 1;
    scanf("%d%d", &ClassOne[BigTemp], &ClassTwo[BigTemp]);
    while (Temp <= ClassOne[BigTemp]) {
      scanf("%d", &TOne[BigTemp][Temp]);
      Temp++;
    }
    Temp = 1;
    while (Temp <= ClassTwo[BigTemp]) {
      scanf("%d", &TTwo[BigTemp][Temp]);
      Temp++;
    }
    BigTemp++;
  }

  BigTemp = 1;
  while (BigTemp <= Num) {
    Temp = 1;
    SumClassOne[BigTemp] = 0;
    SumClassTwo[BigTemp] = 0;
    EvClassOne[BigTemp] = 0;
    EvClassTwo[BigTemp] = 0;
    while (Temp <= ClassOne[BigTemp]) {
      SumClassOne[BigTemp] = SumClassOne[BigTemp] + TOne[BigTemp][Temp];
      Temp++;
    }
    EvClassOne[BigTemp] = SumClassOne[BigTemp] / ClassOne[BigTemp];
    Temp = 1;
    while (Temp <= ClassTwo[BigTemp]) {
      SumClassTwo[BigTemp] = SumClassTwo[BigTemp] + TTwo[BigTemp][Temp];
      Temp++;
    }
    EvClassTwo[BigTemp] = SumClassTwo[BigTemp] / ClassTwo[BigTemp];
    printf("%.2f %.2f\n", EvClassOne[BigTemp], EvClassTwo[BigTemp]);
    if (EvClassOne[BigTemp] > EvClassTwo[BigTemp]) printf("More\n");
    else if (EvClassOne[BigTemp] == EvClassTwo[BigTemp]) printf("Equal\n");
    else printf("Less\n");
    BigTemp++;
  }

  return 0;
}

