/*Created by wlxead.
  Time;2013/12/15 16:59
   Usage:to use linear searching with recursion.
*/
#include <stdio.h>
#define SIZE 10


int linearSearch( const int a[], int start, int size, int key );


int main() {
    int subscript, a[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };


    subscript =linearSearch( a, 0, SIZE, 6 );


    if ( subscript != -1 ) {
        printf( "a[%d] is the key\n" , subscript );
    } else {
        printf( "the key is not in\n" );
    }


    return 0;
}


//the function that search the element by linear searching begins.
int linearSearch( const int a[], int start, int size, int key ) {
    int i, j;


    if ( a[start] == key ) {
        return start;
    }


    if ( start + 1 < size )
        return linearSearch( a, start + 1, size, key );


     return -1;
}
