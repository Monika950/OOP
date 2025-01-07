package org.elsys.cardgame.api;

public abstract class OperationImpl implements Operation {
    private final String name;

    protected OperationImpl(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }

    //nqma implementaciq na execute
}
