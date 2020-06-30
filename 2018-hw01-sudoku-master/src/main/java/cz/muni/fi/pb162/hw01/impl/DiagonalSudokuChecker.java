package cz.muni.fi.pb162.hw01.impl;

import cz.muni.fi.pb162.hw01.Cell;
import cz.muni.fi.pb162.hw01.Sudoku;


/**
 * diagonal sudoku checker class
 *
 * @author Marek Vagunda
 */
public class DiagonalSudokuChecker extends SudokuCheckerWrapper {


    /**
     * Creates instance of sudoku checker.
     *
     * @param sudoku the sudoku which is played on
     */
    public DiagonalSudokuChecker(Sudoku sudoku) {
    super(sudoku);
    }

    /**
     * Checks whether cell c can be inserted without violating rules.
     *
     * @param column column index
     * @param row    row index
     * @param c      cell to be inserted
     * @return true, if no rules are violated, false otherwise
     */
    public boolean canInsert(int column, int row, Cell c){
        //System.out.println("HAIL SATAN");
        return getChecker().canInsert(column, row, c) && isDiagonalValid(column, row, c);
    }

    /**
     * checks if cell is on diagonal1
     * @param column position
     * @param row position
     * @return true if cell is on diagonal, false otherwise
     */
    private boolean isDiagonal1(int column, int row) {
        return column == row;
    }
    /**
     * checks if cell is on diagonal2
     * @param column position
     * @param row position
     * @return true if cell is on diagonal, false otherwise
     */
    private boolean isDiagonal2(int column, int row){
        return column +row == getSudoku().getSize() - 1;
    }

    /**
     * checks if cell is diagonal valid
     * @param column position
     * @param row position
     * @param c position
     * @return true if valid, false otherwise
     */
    private boolean isDiagonalValid(int column, int row, Cell c) {
        int size = getSudoku().getSize();
        if (isDiagonal1(column, row)){
            for (int i = 0; i < size;i++){
                if(getSudoku().getCell(i, i) != null && getSudoku().getCell(i, i).equals(c)){
                    return false;
                }
            }
        }

        if (isDiagonal2(column, row)){
            for (int i = 0; i < size;i++){
                int rowPosition = size - i - 1;
                if(getSudoku().getCell(i, rowPosition) != null && getSudoku().getCell(i, rowPosition).equals(c)){
                    return false;
                }
            }
        }
        return true;
    }
}
