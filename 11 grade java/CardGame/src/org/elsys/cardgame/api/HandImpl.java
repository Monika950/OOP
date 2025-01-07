package org.elsys.cardgame.api;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class HandImpl implements Hand {
    private final List<Card> cards;

    public HandImpl(List<Card> cards) {
        this.cards = new ArrayList<>(cards);
    }

    @Override
    public List<Card> getCards() {
        return Collections.unmodifiableList(cards);
    }

    @Override
    public int size() {
        return cards.size();
    }

    @Override
    public String toString() {//?
        return "Hand: " + cards;
    }
}