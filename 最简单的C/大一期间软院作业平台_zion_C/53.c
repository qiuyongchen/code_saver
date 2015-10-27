/*Created by wlxead.
  Time: 2013/12/15 14:45.
  Usage: to test Palindrome with recursion
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000


int testPalindrome( char a[SIZE], int head, int final );
void elimiArray( char a[SIZE] );


int main() {
    char a[SIZE];
    gets( a );


    puts(a);
    elimiArray( a );
    puts(a);


    printf("%d", strlen(a) );


    if ( testPalindrome( a, 0, strlen(a) - 1 ) == 1 )
        printf( "YES\n" );


    return 0;
}


//the function that test if the string is a Palindrome begins.
int testPalindrome( char a[SIZE], int head, int final ) {


    //if the most middle two (or one) is equl, then this substring is
    //Palindrome.
    if ( head == final )
        return 1;


    //if the substring of the string is Palindrome && the bound of the
    //string is equal, then it is Palindrome.
    if ( a[head] == a[final] ) {
        if ( testPalindrome( a, head + 1, final - 1 ) || (final - 1 == head) )
            return 1;
    } else {
        return 0;
    }
}


//the function that elimilize the string begins.
void elimiArray( char a[SIZE] ) {
    int i, j;


    for ( i = 0, j = 0; a[i] != '\0'; i++ ) {


        if ( a[i] != ' ' ) {
            a[j] = a[i];
            j++;
        }


    }


    a[j] = '\0';
}
 
