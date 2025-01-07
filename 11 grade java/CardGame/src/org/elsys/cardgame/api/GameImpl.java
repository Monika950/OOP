package org.elsys.cardgame.api;

import java.util.*;

public class GameImpl implements Game {
    private final Deck deck;
    private final List<Operation> operations;
    private Hand lastHand;

    public GameImpl(Deck deck, List<Operation> operations) {
        this.deck = deck;
        this.operations = new ArrayList<>(operations);
    }

    @Override
    public Deck getDeck() {
        return deck;
    }

    @Override
    public Hand getLastHand() {
        return lastHand;
    }

    @Override
    public List<Operation> getOperations() {
        return Collections.unmodifiableList(operations);
    }

    @Override
    public void process(String operationName) {
        Operation operation = operations.stream()
                .filter(op -> op.getName().equals(operationName))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("Invalid operation: " + operationName));
        operation.execute();
    }
}