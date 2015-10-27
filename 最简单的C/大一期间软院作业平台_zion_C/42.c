/*Created by 邱永臣
  Time：23:35
  从这个例子可以知道，对于double型的scanf是要使用%lf的。
*/
#include <stdio.h>


int main() {
    double d;
    scanf("%lf", &d);
    printf("%f", d);
    return 0;
}
