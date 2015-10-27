/*Created by wlxead.
  Time: 2013/12/15 23:04.
  Usage: to check the different between the array and pointer.
*/
#include <stdio.h>
int main () {
    int i, a[5] = { 1, 2, 3, 4, 5 };
    int *aPtr = a;


    printf( "Use the array notation:\n" );
    for ( i = 0; i < 5; i++ ) {
        printf( "a[%d] is %d\n" , i, a[i] );
    }


    printf( "Use the Pointer/Offset notation:\n" );
    for ( i = 0; i < 5; i++ ) {
        printf( "* ( aPtr + %d ) is %d\n" , i, * ( aPtr + i ) );
    }


    printf( "The location of the element of the array:\n" );
    for ( i = 0; i < 5; i++ ) {
        printf( "&a[%d] : %p\n" , i, &a[i] );
    }


    printf( "The value of the pointer:\n" );
    for ( i = 0; i < 5; i++ ) {
        printf( "aPtr + %d : %p\n" , i, aPtr + i );
    }


    *( aPtr + 2 ) = 99;
    printf( "\nafter \"*( aPtr + 2 ) = 99;\"\n" );
    printf( "Use the array notation:\n" );
    for ( i = 0; i < 5; i++ ) {
        printf( "a[%d] is %d\n" , i, a[i] );
    }
    printf( "\n" );


    printf( "Use the Pointer subscript notation:\n" );
    for ( i = 0; i < 5; i++ ) {
        printf( "aPtr[%d] is %d\n" , i, aPtr[i] );
    }


    printf( "Use the Pointer/Offset notation\nwhere the pointer is array:\n" );
    for ( i = 0; i < 5; i++ ) {
        printf( "* ( a + %d ) is %d\n" , i, * ( a + i ) );
    }


}
