
Good:
use "lf" to present "double" which is so easy to be wrong
Description

 
Conversion between the metric and English measurement systems is relatively simple. Often, it involves either multiplying or dividing by a constant. You must write a program that converts between the following units:
 
Type	Metric	English equivalent
Weight	1.000 kilograms	2.2046 pounds
 	0.4536 kilograms	1.0000 pound
Volume	1.0000 liter	0.2642 gallons
 	3.7854 liters	1.0000 gallon
 中文大意：公制单位和英制单位之间的转换是相对比较简单的。通常来说，它只是乘以或者乘以一个常数就可以办到。现在要求你写一个程序去转换以下这些单位。
 
Input

 
The first line of input contains a single integer N , (1≤N≤1000) which is the number of datasets that follow.
Each dataset consists of a single line of input containing a floating point (double precision) number, a space and the unit specification for the measurement to be converted. The unit specification is one of kg, lb, l, or g referring to kilograms, pounds, liters and gallons respectively.
 
输入数据第一行是一个整数n，表示接下来你需要转换的单位个数。
对于每一个单位，输入仅有一行，一个浮点数，和这个单位的名称，中间用一个空格隔开。单位名称是，kg, lb, l 或者 g中的一个，分别表示公斤，磅，升，加仑。
 
Output

 
For each dataset, you should generate one line of output with the following values: The dataset number as a decimal integer (start counting at one), a space, and the appropriately converted value rounded to 4 decimal places, a space and the unit specification for the converted value.
对于每一个单位，你要输出一行数据，包括数据的序号（从1开始），一个空格隔开，保留四位小数的转换值，一个空格隔开，转换成的单位名称。
 
Sample Input

5 
1 kg 
2 l 
7 lb 
3.5 g 
0 l
Sample Output

1 2.2046 lb 
2 0.5284 g 
3 3.1752 kg 
4 13.2489 l 
5 0.0000 g
Note: If you have any question on the description, please send an email to its author.

Hint:

Learn to use the function "strcmp(char*,char*)" in <string.h> to compare are two character equal or not.
PS:
Use double instead of float!
学会用<string.h>中的"strcmp(char*, char*)函数，来判断两个字符串是否相等。
警告：
不要使用float类型，尽量都使用double类型代替。




#include <stdio.h>
#include <string.h>

int main() {
    int i = 1, Num;
    double BeforeTNum;
    char BeforeTStr[10] = " ";
    scanf("%d", &Num);
    while (i <= Num) {
        scanf("%lf", &BeforeTNum);
        scanf("%s", BeforeTStr);
        printf("%d ", i);
        if (strcmp(BeforeTStr, "kg") == 0) {
            printf("%.4lf lb\n", BeforeTNum * 2.2046);
        }
        else if (strcmp(BeforeTStr, "lb") == 0) {
            printf("%.4lf kg\n", BeforeTNum * 0.4536);
        }
        else if (strcmp(BeforeTStr, "l") == 0) {
            printf("%.4lf g\n", BeforeTNum * 0.2642);
        }
        else if (strcmp(BeforeTStr, "g") == 0) {
            printf("%.4lf l\n", BeforeTNum * 3.7854);
        }
        i++;
        BeforeTStr[0] = ' ';
        BeforeTStr[1] = ' ';
    }
    return 0;
}
