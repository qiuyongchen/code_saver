妙处在于：用了一个标志变量来决定最终的输出

Description:

中文题面：
Uncle Da 最近聊了一个女朋友，他打算和妹子度蜜月，蜜月旅游将会依次经过n个城市。但是他只有一辆油箱容积为v的小轿车，不知道这个计划会不会由于半路没油了而失败。幸运的是，每个城市都有一个加油站，可以加一定量的油。这个问题本来挺简单的，可是Uncle Da大神沉浸在爱情的火花中，来不及思考这个问题，所以作为追随他的后辈们，写个程序帮他判断能否完成旅行的重担就交给你们了！
他从某个起始点（第0个城市）出发，依次经过1、2、3 一直到第n个城市结束，最开始出发的时候油箱是装满的，一个单位的汽油可以让小车行驶一单位距离。
输入数据第一行有两个整数n和v。接下来的n行每行有两个整数，其中接下来的第i行有di和pi。di是从第i-1个城市到第i个城市的距离，pi是这第i个城市可以加油的最大数量。
你只用输出Yes或者No，表示Uncle Da是否能完成蜜月旅行。
测试样例1 输入：
3 30
10 20
20 10
20 0
测试样例1 输出：
Yes
测试样例2 输入：
3 40
10 300
45 40
10 0
测试样例2 输出：
No
 
 
英文题面：Uncle Da's Loving Travel
Uncle Da recently have got a girl friend. So he planned a loving travel with n cities on a straight line. But he had only a car with a v-volumn size tank(油箱). and not sure whether they can finish the journey. Fortunately every city has an oil station where he can fill his tank. It's quite a simple question but people alway have no IQ falling in love. That's a problem to him, so you have to design a program help him.
He starts his journey from city 0, then to 1,2,3,..., ended with n. When he starts, the tank is filled. A piece of oil can run the car with a piece of distance.
The first line has two integers n (0<n<=100) and v (10<v<=500)
Next n lines, each line has two integers. The ith line has di (0<di<=800) and pi (0<pi<=500). di is the distance between city i-1 to i; pi is the most oil Uncle Da can get from the oil station here.
You just only have to print Yes or No ('\n' is necessary), means whether Uncle Da can finish the journey.
 
An example input:
3 30
10 20
20 10
20 0
output:
Yes
 
Another example input:
3 40
10 300
45 40
10 0
output:
No
Note: If you have any question on the description, please send an email to its author.


#include <stdio.h>
#include <math.h>

int main() {
  int i = 1, t = 1;
  int WorkPlace, Oil, Route, AddOil, RemainOil;
  scanf("%d%d", &WorkPlace, &Oil);
  RemainOil = Oil;
  while (i <=WorkPlace) {
    scanf("%d%d", &Route, &AddOil);
    if (Route > RemainOil) {
      printf("No\n");
      t = 0;
      break;
    } else {
      RemainOil = RemainOil - Route;
      if (RemainOil + AddOil >=Oil) {
        RemainOil = Oil;
      } else {
        RemainOil = RemainOil + AddOil;
      }
    }
    i++;
  }
  if (t == 1) printf("Yes\n");
  return 0;
}

