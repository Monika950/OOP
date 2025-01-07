package org.elsys.cardgame.api;

import java.util.List;

public class GameFactory {
    public static Game createGame(Deck deck, List<Operation> operations) {
        return new GameImpl(deck, operations);
    }
}
