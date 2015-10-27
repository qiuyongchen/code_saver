/*Created by 邱永臣
  Time：16:31
  A Game Of Chance, all right researved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*定义enum类型时，后面要带;的哦*/
enum Status {CONTINUE, WON, LOST};


int roll(void);


int main() {
    int sum;
    int myPoint;


    enum Status gameStatus;


    srand( time( NULL ) );


    sum  = roll();


    switch ( sum ) {


        case 7:
        case 11:
            gameStatus = WON;
            break;


        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;


        default:
            gameStatus = CONTINUE;
            myPoint = sum;
        //    printf( "Point is %s\n" , myPoint );这句会在某次运行时导致错误（gameStatus == CONTINUE)
        //    可能是把一个int型当作字符串来输出了
            printf( "Point is %d\n" , myPoint );
            break;
    }


    while ( gameStatus == CONTINUE ) {
        sum = roll();
        
        if ( sum == myPoint ) {
            gameStatus = WON;
        } else {
            if ( sum == 7 )
                gameStatus = LOST;
        }
    }
    /*display won or lost*/
    if ( gameStatus == WON ) {
        printf( "You win!\n" );
    } else {
        printf( "You lost!\n" );
    }


    return 0;
}
/*随机摇色子函数*/
int roll(void) {
    int d1, d2, sum;
    d1 = 1 + rand() %  6;
    d2 = 1 + rand() %  6;
    sum = d1 + d2;
    printf( "You roll %d + %d = %d\n", d1, d2, sum);
    return sum;
}
