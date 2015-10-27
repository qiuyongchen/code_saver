/*Created by wlxead.
  Time: 2013/12/15 15:09.
  Usage: to use the selection sorting with recurision.
  Warn: though it is ok as look like, there is something fun.
        it would not work it the 'SIZE' is more than 9250, and I
        don't know why( Maybe my computer can not deal with such
        more functions ).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 9250


void initArray( int a[SIZE], int n );
int selectionSort( int a[SIZE], int head, int final);
void printArray( int a[SIZE], int n );


int main() {
    int a[SIZE];


    initArray( a, SIZE );
    printArray( a, SIZE );
    selectionSort( a, 0, SIZE );


    printf( "\n\n\n\n" );
    printArray( a, SIZE );


    return 0;
}


//the initializtion of the array begins.
void initArray( int a[SIZE], int n ) {
    int i;
    srand( time( NULL ) );


    for ( i = 0; i < n; i++ ) {
        a[i] = 1 + rand() % 100;
    }


}


//the selection sorting algorithm begins.
int selectionSort( int a[SIZE], int head, int final ) {
    int i, min, hold;


    //if there is only ont element in the array, then stop.
    if ( head == final - 1 ) {
        return 0;
    }


    //compare the first element of the array with the last elements ,to
    //find the subscript of the smallest element of the array and, swap them.
    for ( i = head + 1, min = head; i < final; i++ ) {
        if ( a[i] < a[min] )
            min = i;
    }
    if ( min != head ) {
        hold = a[min];
        a[min] = a[head];
        a[head] = hold;
    }


    //use the function selectionSort to sort the subarray which do not
    //contain the first element of the original array as "recursion".
    selectionSort( a, head + 1, final);


    return 0;
}


//the array printing function begins.
void printArray( int a[SIZE], int n ) {
    int i;


    for ( i = 0; i < n; i++ ) {
        printf( "%4d", a[i] );
    }


    printf( "\n" );
}
