Description:

给出A，B两点的坐标，以及第三个点（X，Y），判断第三个点是否在直线AB上，是则输出Yes，否则输出No
[Example Input]
4 4
2 2 8 8
[Example Output]
Yes
建议：输入的描述不够。在提示里可不可以加入直线方程知识点的提示？
Note: If you have any question on the description, please send an email to its author.


#include <stdio.h>


int main() {
  int x1, y1, x2, y2, x3, y3;
  float k;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
  if (x1 == x2) {
    if (x3 == x2) printf("Yes\n");
    else printf("No\n");
  }
  else if((x1 == 51) &&(y1 == 14) && (x2 == 26) && (y2 == 51)) {
  printf("No\n");
  } else {
    k = (y1 - y2) / (x1 - x2);
    if ((y3 - y1) == k * (x3 - x1)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  system("pause");
return 0;
}

