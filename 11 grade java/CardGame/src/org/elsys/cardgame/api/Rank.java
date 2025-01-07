package org.elsys.cardgame.api;

public enum Rank {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING;

    public static Rank getRank(String rankString) {
        switch (rankString) {
            case "A": return Rank.ACE;
            case "2": return Rank.TWO;
            case "3": return Rank.THREE;
            case "4": return Rank.FOUR;
            case "5": return Rank.FIVE;
            case "6": return Rank.SIX;
            case "7": return Rank.SEVEN;
            case "8": return Rank.EIGHT;
            case "9": return Rank.NINE;
            case "10": return Rank.TEN;
            case "J": return Rank.JACK;
            case "Q": return Rank.QUEEN;
            case "K": return Rank.KING;
            default: return null;
        }
    }
}