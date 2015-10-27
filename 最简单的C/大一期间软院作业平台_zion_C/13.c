妙处在于：判断闰年的算法 

Description:

We all know Jan 1, 2001 are Monday. Now, given year Y, do you know waht day it is on Jan 1st?
Note that 0 is Sunday.
Note: If you have any question on the description, please send an email to its author.



#include <stdio.h>


int main() {
  int Year, FirstDay = 6, AllDay, DayInYear, i = 0;
  scanf("%d", &Year);
  while (i < Year) {
    DayInYear = 365;
    if ((i % 4 == 0)&& (i % 100 != 0)|| (i % 400 == 0)) {
      DayInYear = 366;
    }
    AllDay = DayInYear + FirstDay;
    FirstDay = AllDay % 7;
    i++;
  }
  printf("%d\n", FirstDay);
  return 0;
}

