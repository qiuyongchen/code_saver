/*Created by wlxead.
  Time:2013/12/14 19:21
  All right reserve.
  Usage: To check the use of a interesting function---srand.
    if there is no srand(), then the program will get the same sequence each time
  it executed because the seed of rand is the same.
    if there is a srand(), then the sequence will change because the seed which 
  relys on the time of the system is different.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ALL_SIZE 6000000


int main() {
    int i, r, a[7] = { 0 };


    srand( time( NULL ) );


    for ( i = 0; i < ALL_SIZE; i++ ) {
        r = 1 + rand() % 6;
        a[r] += 1;
    }
    for ( i = 1; i < 7; i++ ) {
        printf( "The '%d' occurs %d times\n" , i + 1, a[i] );
    }
    return 0;
}
