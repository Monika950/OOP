package org.elsys.cardgame.api;

import org.elsys.cardgame.api.Card;

import java.util.List;

public interface Deck {
    List<Card> getCards();
    int size();
    int handSize();
    List<Card> deal();
    Card drawTopCard();
    void sort();
    void shuffle();
}