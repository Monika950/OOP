package org.elsys.cardgame.api;

import java.util.*;

public class DeckImpl implements Deck {
    private final List<Card> cards;
    private final int handSize;

    public DeckImpl(List<Card> cards, int handSize) {
        this.cards = new ArrayList<>(cards);
        this.handSize = handSize;
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
    public int handSize() {
        return handSize;
    }

    @Override
    public List<Card> deal() {
        if (cards.size() < handSize) {
            throw new IllegalStateException("Not enough cards to deal.");
        }
        List<Card> hand = new ArrayList<>(cards.subList(0, handSize));
        cards.subList(0, handSize).clear();
        return hand;
    }

    @Override
    public Card drawTopCard() {
        if (cards.isEmpty()) {
            throw new NoSuchElementException("No cards left in the deck.");
        }
        return cards.removeFirst();
    }

    @Override
    public void sort() {
        cards.sort(Comparator.comparing(Card::getSuit).thenComparing(Card::getRank));
    }

    @Override
    public void shuffle() {
        Collections.shuffle(cards);
    }
}

