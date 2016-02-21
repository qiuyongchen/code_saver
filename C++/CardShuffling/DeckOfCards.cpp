#include "DeckOfCards.h"
#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

DeckOfCards::DeckOfCards() {
  currentCard = 0;

  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 13; j++) {
      Card temp(j, i);
      deck.push_back(temp);
    }

  }

}

Card DeckOfCards::dealCard() {
  currentCard++;
  return deck.at(currentCard - 1);
}

bool DeckOfCards::moreCards() const {

  if (currentCard < deck.size())
    return true;
  else
    return false;

}

