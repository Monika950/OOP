package org.elsys.cardgame.api;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DeckFactory {

    public static Deck createWarDeck() {
        List<Card> cards = new ArrayList<>();
        for (Suit suit : Suit.values()) {
            for (Rank rank : Arrays.asList(Rank.TWO, Rank.THREE, Rank.FOUR, Rank.FIVE, Rank.SIX, Rank.SEVEN, Rank.EIGHT, Rank.NINE, Rank.TEN, Rank.JACK, Rank.QUEEN, Rank.KING, Rank.ACE)) {
                cards.add(new CardImpl(rank, suit));
            }
        }
        return new DeckImpl(cards, 26);
    }

    public static Deck createBeloteDeck() {
        List<Card> cards = new ArrayList<>();
        for (Suit suit : Suit.values()) {
            for (Rank rank : Arrays.asList(Rank.SEVEN, Rank.EIGHT, Rank.NINE, Rank.JACK, Rank.QUEEN, Rank.KING, Rank.TEN, Rank.ACE)) {
                cards.add(new CardImpl(rank, suit));
            }
        }
        return new DeckImpl(cards, 8);
    }

    public static Deck createSantaseDeck() {
        List<Card> cards = new ArrayList<>();
        for (Suit suit : Suit.values()) {
            for (Rank rank : Arrays.asList(Rank.NINE, Rank.JACK, Rank.QUEEN, Rank.KING, Rank.TEN, Rank.ACE)) {
                cards.add(new CardImpl(rank, suit));
            }
        }
        return new DeckImpl(cards, 6);
    }
}

