/*Created by wlxead
  Time:11:05
  All right reserve.
  Yes, the recurisive needs a base, and the base is placed at the beginning of
  the recuisive function.
*/
#include <stdio.h>


long factorial( long n );


int main() {
    int i = 10;


    for ( i = 1; i < 11; i++ ) {
        printf( "The factorial of %-2d is %-10ld\n", i, factorial( i ) );
    }


    return 0;
}


long factorial( long n ) {
    if ( n <= 1 ) {
        return 1;
    } else {
        return n * factorial( n - 1 );
    }
}
