/*Created by wlxead
  Time：00:11
  To check some usage of the scope of values.
  All right reserved.
*/


#include <stdio.h>


void useAutoLocal( void );
void useStaticLocal( void );
void useStaticGlobal( void );


int x = 88888;


int main() {
    int x = 1;
    //这个会输出1，因为在子块中又定义了一个x，于是系统把外面那个给隐藏
    //了。
    printf( "The value of x in main(the first lay) is %d\n" , x );


    {
        int x = 2;
        //这个会输出2，因为在子块中又定义了一个x，于是系统把外面那两个
        //给隐藏了。    
        printf( "The value of x in main(the second lay) is %d\n" , x );
    }
    //输出1
    printf( "The value of x in main(the first lay) is %d\n\n" , x );


    useAutoLocal();
    useStaticLocal();
    useStaticGlobal();
    useAutoLocal();
    useStaticLocal();
    useStaticGlobal();


    printf( "The value of x in main(the first lay) is %d\n\n" , x );


    return 0;
}


void useAutoLocal( void ) {
    int x = 3;
    printf( "The value of x in useAutoLocal is %d\n" , x );
    x++;
    printf( "The value of x in useAutoLocal is %d\n\n" , x );
}


//定义了静态的x，第二次再运行时还是使用第一次运行结束的结果
//（静态者只会在首次赋值语句里真正赋值。
void useStaticLocal( void ) {
    static int x = 33;
    printf( "The value of x in useStaticLocal is %d\n" , x );
    x += 33;
    printf( "The value of x in useStaticLocal is %d\n\n" , x );
}


//没有定义新x，所以使用了全局变量x.
void useStaticGlobal( void ) {
    printf( "The value of x in useStaticGlobal is %d\n" , x );
    x += 88888;
    printf( "The value of x in useStaticGlobal is %d\n\n" , x );
}
