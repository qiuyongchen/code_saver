Description:

给出平面上三角形的三个顶点的坐标(x1,y1),(x2,y2),(x3,y3)，（任意两点不能重合）求出三角形的面积，结果保留两位小数。
输入输出样例：
输入：
0 0 0 1 1 0
输出：
0.50

Hint:

平面上两点间的距离，海伦公式。注意要用double类型。

Answer:

#include <math.h>
#include <stdio.h>

int main() {
double  x1, y1, x2, y2, x3, y3;
double a, b, c, p;
double s;
scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
p = (a+b+c)/2;
s = sqrt(p*(p-a)*(p-b)*(p-c));
printf("%.2f\n", s);
return 0;
}
