package cz.muni.fi.pb162.hw01.impl;

import cz.muni.fi.pb162.hw01.InfiniteCellSequence;

/**
 * defines LetterCell
 *
 * @author Marek Vagunda
 */
public class LetterCell extends InfiniteCellSequence {
    private char currentValue;

    public static final char INIT_VALUE = 'A';
    public static final LetterCell INIT_CELL = new LetterCell();

    /**
     * constructor
     * @param c char
     */
    public LetterCell(char c){
        currentValue = c;
    }
    /**
     * default constructor
     */
    public LetterCell(){
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
        return new LetterCell((char) (this.currentValue +1));
    }

}
