/*Created by wlxead.
  Time: 2013/12/14 20:02
  Usage: to check static array.
  It looks like the same as the static of those variables.
*/
#include <stdio.h>
void staticarray( void );
void autoarray( void );


int main() {
    printf( "The first time:\n" );


    staticarray();
    autoarray();


    printf( "The second time:\n" );


    staticarray();
    autoarray();


    return 0;
}


void staticarray( void ) {
    static int a[5];
    int i;


    printf( "The first time of staticarray():\n" );


    for ( i = 0; i < 5; i++ ) {
        printf( "a[%d] = %d " , i, a[i] );
    }
    printf( "\n" );


    printf( "The second time of staticarray():\n" );


    for ( i = 0; i < 5; i++ ) {
        printf( "a[%d] = %d " , i, a[i] += 5);
    }
    printf( "\n" );


}


void autoarray( void ) {
    int a[5] = { 0 };
    int i;


    printf( "The first time of autoarray():\n" );


    for ( i = 0; i < 5; i++ ) {
        printf( "a[%d] = %d " , i, a[i] );
    }


    printf( "\n" );
    printf( "The second time of autoarray():\n" );


    for ( i = 0; i < 5; i++ ) {
        printf( "a[%d] = %d " , i, a[i] += 5);
    }
    printf( "\n" );


}
