package org.elsys.cardgame.api;

public enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES;

    public static Suit getSuit(char suitChar) {
        switch (suitChar) {
            case 'S': return Suit.SPADES;
            case 'H': return Suit.HEARTS;
            case 'D': return Suit.DIAMONDS;
            case 'C': return Suit.CLUBS;
            default: return null;
        }
    }
}
