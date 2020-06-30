package cz.muni.fi.pb162.hw01.impl;

import cz.muni.fi.pb162.hw01.InfiniteCellSequence;

/**
 * defines NumberCell
 *
 * @author Marek Vagunda
 */
public class NumberCell extends InfiniteCellSequence{
    private int currentValue;

    public static final int INIT_VALUE = 1;
    public static final NumberCell INIT_CELL = new NumberCell();

    /**
     * constructor
     * @param x number
     */
    public NumberCell(int x){
        currentValue = x;
    }

    /**
     * default constructor
     */
    public NumberCell(){
        this(INIT_VALUE);
    }

    /**
     * getter
     * @return value
     */
    @Override
    public String getValue(){
        return String.valueOf(currentValue);
    }

    /**
     * gets startingValue of sequence
     * @return starting cell
     */
    @Override
    public InfiniteCellSequence startingValue(){
        return INIT_CELL;
    }

    /**
     * gets next cell
     * @return next cell
     */
    @Override
    public InfiniteCellSequence nextValue(){
        return new NumberCell(this.currentValue + 1);
    }


}
