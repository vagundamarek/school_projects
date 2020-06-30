package cz.muni.fi.pb162.hw01.impl;

import cz.muni.fi.pb162.hw01.Cell;
import cz.muni.fi.pb162.hw01.Sudoku;
import cz.muni.fi.pb162.hw01.helper.SudokuChecker;

/**
 * @author Marek Vagunda
 *
 * wrapper for sudoku checker for better ingeritance use
 */
public class SudokuCheckerWrapper {
    private SudokuChecker checker;
    private Sudoku sudoku;

    SudokuCheckerWrapper(Sudoku sudoku){
        checker = new SudokuChecker(sudoku);
        this.sudoku = sudoku;
    }
    Sudoku getSudoku(){
        return sudoku;
    }
    SudokuChecker getChecker(){
        return checker;
    }

    /**
     * call to canInsert method from sudokuChecker class
     * @param column position
     * @param row position
     * @param c cell to be checked
     * @return true if insertable, false otherwise
     */
    public boolean canInsert(int column, int row, Cell c){
        return checker.canInsert(column, row, c);
    }
}
