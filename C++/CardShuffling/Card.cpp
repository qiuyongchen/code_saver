#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

const char* Card::faceNames[ totalFaces ] =
  { "Ace", "Deuce", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

const char* Card::suitNames[ totalSuits ] =
  { "Hearts", "Diamonds", "Clubs", "Spades" };

Card::Card(int cardFace, int cardSuit) {
  face = cardFace;
  suit = cardSuit;
}

string Card::toString() const {
  string t = " of ";
  string FACE = faceNames[face];
  string SUIT = suitNames[suit];

  string ret = FACE + t + SUIT;
  return ret;
}

int Card::getFace() const {

  return face;

}

int Card::getSuit() const {

  return suit;

}
