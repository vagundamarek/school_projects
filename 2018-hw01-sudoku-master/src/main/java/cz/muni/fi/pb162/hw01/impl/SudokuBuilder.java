package cz.muni.fi.pb162.hw01.impl;

import cz.muni.fi.pb162.hw01.Cell;
import cz.muni.fi.pb162.hw01.InfiniteCellSequence;
import cz.muni.fi.pb162.hw01.Sudoku;

/**
 * builder for BasicSudoku class and DiagonalSudoku class
 *
 * @author Marek Vagunda
 */
public class SudokuBuilder {

    private int size;
    private InfiniteCellSequence cellType;
    private Cell[][] cells;
    private Boolean isDiagonal;

    /**
     * constructor
     * @param size size of sudoku
     * @param cellType type of cells
     */
    public SudokuBuilder(int size, InfiniteCellSequence cellType){
        this.size = size;
        this.cellType = cellType;
        cells = new Cell[size][size];
        isDiagonal = false;
    }

    /**
     * adds cell to sudoku
     * @param column position
     * @param row position
     * @param c cell
     * @return builder
     */
    public SudokuBuilder cell(int column, int row, Cell c){
        cells[column][row] = c;
        return this;
    }

    /**
     * adds/removes diagonal property
     * @param isDiagonal diagonal
     * @return builder
     */
    public SudokuBuilder diagonal(boolean isDiagonal){
        this.isDiagonal = isDiagonal;
        return this;

    }

    /**
     * builds sudoku
     * @return sudoku structure
     */
    public Sudoku build(){
        BasicSudoku sudoku;
        SudokuCheckerWrapper check;
        if (isDiagonal){
            sudoku = new DiagonalSudoku();
            check = new DiagonalSudokuChecker(sudoku);
        } else {
            sudoku = new BasicSudoku();
            check = new SudokuCheckerWrapper(sudoku);
        }

        sudoku.setter(cellType, cells, cellType.firstNValues(size), size, check);

        return sudoku;
    }
}

