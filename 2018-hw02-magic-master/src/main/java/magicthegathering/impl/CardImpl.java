package magicthegathering.impl;

import magicthegathering.game.Card;

/**
 * implements basic card operations
 *
 * @author Marek Vagunda
 */
public abstract class CardImpl implements Card {

    private boolean isTapped;
    private boolean onTable;

    /**
     * constructor
     */
    public CardImpl() {
        isTapped = false;
        onTable = false;
    }

    @Override
    public boolean isTapped() {
        return isTapped;
    }

    @Override
    public boolean isOnTable() {
        return onTable;
    }

    @Override
    public void tap() {
        isTapped = true;
    }

    @Override
    public void untap() {
        isTapped = false;
    }


    @Override
    public void putOnTable() {
        onTable = true;
    }

}
