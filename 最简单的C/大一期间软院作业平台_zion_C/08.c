妙处在于：先求摩再除以十

Description:

Given an integer and adds all digits in the integer.
[Example Input]
111
[Example Output]
3
Note: If you have any question on the description, please send an email to its author.





#include <stdio.h>
 
int main() {
  int Inp;
  int Sum = 0;
  int Min;
  scanf("%d", &Inp);
  while (Inp > 0) {
    Min = Inp % 10;
    Sum = Sum + Min;
    Inp = Inp / 10;
  }
  printf("%d\n", Sum);
  return 0;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
