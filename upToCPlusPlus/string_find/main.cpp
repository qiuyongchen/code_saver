// main.cpp
// created by qiuyongchen.
#include <iostream>
#include <string>
using namespace std;

int main() {
  char sentenceChar[1000];
  string A, B;
  string sentence = "";
  int found;

  cin.getline(sentenceChar, 1000);

  for (int i = 0; sentenceChar[i] != '\0'; i++)
    sentence += sentenceChar[i];

  cin >> A >> B;

  found = sentence.find(A);

  while (found < sentence.length()) {
    sentence.replace(sentence.find(A), A.length(), B);
    found = sentence.find(A, found);
  }

  cout << sentence << endl;

  return 0;
}
