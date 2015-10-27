/*Created by wlxead.
  Time:2013/12/14 20:49
  All right reserve.
  Usage:To sort an array with bubble sort and to check the efficiency of the
  algorithm.
  Warn:It is "a[i] > a[i + 1]", not "a[i] > a[i - 1]".
*/
#include <stdio.h>
#include <stdlib.h>


#define SIZE 100


int main() {
    int a[SIZE] = { 0 }, pass, hold, i;


    srand( time( NULL ) );


    for ( i = 0; i < SIZE; i++ ) {
        a[i] = 1 + rand() % 100;
    }


    for ( i = 0; i < SIZE; i++ ) {
        printf( "%d ", a[i] );
    }
    printf( "\n" );
    /*The bubble begins, just pass (SIZE - 1) times*/
    for ( pass = 1; pass < SIZE; pass++ ) {


        for ( i = 0; i < SIZE - 1; i++ ) {


            if ( a[i] > a[i + 1] ) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }


        }


    }


    for ( i = 0; i < SIZE; i++ ) {
        printf( "%d ", a[i] );
    }
    printf( "\n" );


    return 0;
}
