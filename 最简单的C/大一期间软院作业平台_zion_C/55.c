/*Created by wlxead.
  Time:2013/12/14 22:04
  Usage:To use binary rearching and make something interesting.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10


void printArray( int a[SIZE] );
void bubbleSort( int a[SIZE] );
void printHeader( void );
void printRow( int a[SIZE], int middle, int low, int high );
int binarySearch( int a[SIZE], int key, int low, int high );


int main() {
    int a[SIZE] = { 0 }, i, j, k, result, key = 3;
    srand( time( NULL ) );


    //initialize the array with the function rand().
    for ( i = 0; i < SIZE; i++ ) {
        a[i] = 1 + rand() % 100;
    }


    printf( "Array:\n   the array before sorted:\n" );
    printArray( a );


    //sort the array with bubble sorting using function bubbleSort().
    bubbleSort( a );


    printf( "   the array after sorted:\n" );
    printArray( a );


    printf( "\nwhich number do you search?\n" );
    scanf( "%d" , &key );
    printf( "\n" );


    //printf the header of the array using function printHeader().
    printHeader();


    //search the key in the array using binary searching with function
    //binarySearch().
    result = binarySearch( a, key, 0, SIZE - 1);


    if ( result != -1 ) {
        printf( "The %d is in the %dth element of the array\n" , key, result + 1 );
    } else {
        printf( "The key not found!\n" );
    }


    return 0;
}


//for output the whole array.
void printArray( int a[SIZE] ) {
    int i;


    for ( i = 0; i < SIZE; i++ ) {
        printf( "%4d" , a[i] );
    }


    printf( "\n" );
}


//the bubble sorting function begins.
void bubbleSort( int a[SIZE] ) {
    int pass, hold, i, j;


    for ( pass = 0; pass < SIZE; pass++ )
        for ( i = 0; i < SIZE - 1; i++ )
            if ( a[i] > a[i + 1] ) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }
 
}


//the printHeader function begins.
void printHeader( void ) {
    int i;
    printf( "Subscripts:\n" );


    //output the subscripts of the element of the array.
    for ( i = 0; i < SIZE; i++ ) {
        printf( "%4d", i );
    }


    printf( "\n" );


    for ( i = 0; i < 4 * SIZE; i++ ) {
        printf( "-" );
    }


    printf( "\n" );
}


//the function printRow was used to print the details of each time searching.
void printRow( int a[SIZE], int middle, int low, int high ) {
    int i;


    for ( i = 0; i < SIZE; i++) {


        if ( i < low || i > high ) {
            printf( "    " );
        } else if ( i == middle ) {
            printf( "%3d*", a[i] );
        } else {
            printf( "%4d", a[i] );
        }


    }


    printf( "\n" );
    printf( "\n" );
}




int binarySearch( int a[SIZE], int key, int low, int high ) {
    int middle, i;


    
    middle = ( low + high ) / 2;
    printRow(a, middle, low, high);


    if ( a[middle] == key ) {
        return middle;
    } else if ( key <= a[middle] ) {
        return binarySearch( a, key, low, middle - 1 );
    } else if ( key >= a[middle] ) {
        return binarySearch( a, key, middle + 1, high );
    }


    return -1;
}
