package cz.muni.fi.pb162.hw01.impl;

import cz.muni.fi.pb162.hw01.Cell;
import cz.muni.fi.pb162.hw01.Sudoku;

/**
 * class implementing diagonal sudoku
 *
 * @author Marek Vagunda
 */
public class DiagonalSudoku extends BasicSudoku implements Sudoku {


    /**
     * constructor
     * @param cells board
     * @param values possible values
     */

    /**
     * default constructor
     */
    DiagonalSudoku(){
    }

    /**
     * constuctor
      * @param cells board
     * @param values range of values
     */
    public DiagonalSudoku(Cell[][] cells, Cell[] values){
        super(cells, values);
        setChecker(new DiagonalSudokuChecker(this));

    }

}
