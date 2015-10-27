Description:

Ziyao and Uncle Da like to play games. There is a pile of stones. So they design a game. 
The rules are:
1, Two people pick up stones in turns
2, One can pick up one or two stones at a time
3. The one who picks up the last stone will win the game. 
Ziyao and Uncle Da are so clever that they won't make any mistakes. The game starts with Ziyao. Given the number of stones, you are going to find out who will win the game.
Note: If you have any question on the description, please send an email to its author.




#include <stdio.h>


int main() {
  int Stone;
  scanf("%d", &Stone);
  if (Stone % 3 == 0) {
    printf("Uncle Da\n");
  } else {
    printf("Ziyao\n");
  }
  return 0;
}

