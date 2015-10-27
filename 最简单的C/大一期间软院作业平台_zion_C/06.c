关于魔兽逃命的问题：初始蓝为m，路程为s，时间为t，闪一次逃60米消耗10点蓝，休息一秒回复4点蓝，正常跑速度为17米每秒，活动以整秒计算，依据mst判定是否能逃命，是则输出最少时间，否则输出最长距离。


我的想法：肯定先把蓝消耗完，若
1.剩余0点蓝。这时若闪一次需花4秒，但4秒里可以跑68米，不值；
若闪两次花7秒跑120米，正常跑只能跑119米，这时最好用狂闪；

2、剩余1点蓝。这时若闪一次需花4秒，但4秒里可以跑68米，不值；
若闪两次花7秒跑120米，正常跑只能跑119米，这时最好用狂闪；剩1点与剩2点其实一样的……

3、剩2点蓝。这时若闪一次需花3秒，3秒里可以跑51米，狂闪；只要距离大于51米就可以了，把能优化的部分先给优化了就行……

4、剩3点蓝。这时若闪一次需花3秒，但3秒里可以跑51米，狂闪；能闪就闪……

5、剩4点蓝。这时若闪一次需花3秒，但3秒里可以跑51米，狂闪；能闪就闪……

6、剩5点蓝。这时若闪一次需花3秒，但3秒里可以跑51米，狂闪；能闪就闪……

7、剩6点蓝。这时若闪一次需2秒，2正常跑只能跑34米，狂闪……

8、剩7点蓝。这时若闪一次需2秒，2正常跑只能跑34米，狂闪……

9、剩8点蓝。这时若闪一次需2秒，2正常跑只能跑34米，狂闪……

10、剩9点蓝。闪一次要2秒，明显又狂闪……

于是可得如下结论：

当（蓝有0或1点+时间足够闪2次+超过119米）时狂闪2次，若时间不够2次就不用休息了，毕竟休息为了闪，但只能闪一次，这时还不如正常跑，当然，如果连路程都不够远那就更不用闪了，

当（蓝有3到5点+时间够一次+超过51米）时狂闪1次，同理
当（蓝有6到9点时+时间够一次+超过34米）时狂闪一次，
其它则先走正常跑一秒吧，

while(Timeleft>0 && Space-SpaceElse>0){ //决策判断
if((Mana==0 || Mana==1) && Timeleft>=7 && Space-SpaceElse>102) //见表格 {Timeleft-=7;SpaceElse+=120;}
else if(Mana>=2 && Mana<=5 && Timeleft>=3 && Space-SpaceElse>34)//见表格
{Mana-=2;Timeleft-=3;SpaceElse+=60;}
else if(Mana>=6 && Timeleft>=2 && Space-SpaceElse>17) //见表格
{Mana-=6;Timeleft-=2;SpaceElse+=60;}
else {SpaceElse+=17;Timeleft--;}
}
if(Space<=SpaceElse)cout<<"Yes"<<endl<<TimeleftElse-Timeleft;
else cout<<"No"<<endl<<SpaceElse;
return;
}


96分代码如下：
#include <stdio.h>

int main() {
  int Time, M, RouteAll, Routed;
  int m;
  int Num;
  int Tt[10000][3];
  int Temp = 1;
  scanf("%d", &Num);
  while (Temp <= Num) {
    scanf("%d%d%d", &Tt[Temp][1], &Tt[Temp][2], &Tt[Temp][3]);
    Temp++;
  }

  Temp = 1;
  while (Temp <= Num) {
    M = Tt[Temp][1];
    Time = Tt[Temp][3];
    RouteAll = Tt[Temp][2];
    Routed = 0;
    m = M/10;
    Routed = m * 60;
    Time = Time - m;
    M = M - m * 10;
    while (Time >0 && RouteAll - Routed > 0) {
      if ((M == 0 || M == 1) && Time >= 7 && RouteAll - Routed >= 102) {
        Time = Time - 7;
        Routed = Routed + 120;
      }
      else if ((M > 1 && M < 6) && Time >= 3 && RouteAll - Routed >= 34) {
        Time = Time - 3;
        M = M - 2;
        Routed = Routed + 60;
      }
      else if ((M > 5 && M < 10) && Time >= 2 && RouteAll - Routed >= 17) {
        Time = Time - 2;
        M = M - 6;
        Routed = Routed + 60;
      }
      else Time = Time - 1, Routed = Routed + 17;
    }
    if (Routed > RouteAll) {
      printf("Yes\n");
      printf("%d\n", Tt[Temp][3] - Time);
    }
    else printf("No\n%d\n", Routed);
    Temp++;
  }

  return 0;
}




 
