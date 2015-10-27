Description:

Given the radius of the circle, output the area of this circle. The answer should be round to 6 digits after decimal point.
Note: If you have any question on the description, please send an email to its author.



#include <stdio.h>
 
int main() {
  double R;
  double Area;
  scanf("%lf", &R);
  Area = 3.1415926 * R * R;
  printf("%.6f\n", Area);
  return 0;
}
