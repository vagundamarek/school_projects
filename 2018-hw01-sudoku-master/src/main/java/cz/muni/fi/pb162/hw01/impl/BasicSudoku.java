package cz.muni.fi.pb162.hw01.impl;

import cz.muni.fi.pb162.hw01.Cell;
import cz.muni.fi.pb162.hw01.InfiniteCellSequence;
import cz.muni.fi.pb162.hw01.Sudoku;
import cz.muni.fi.pb162.hw01.helper.ArrayUtils;



/**
 * implements basic Sudoku
 *
 *  @author Marek Vagunda
 */
public class BasicSudoku implements Sudoku {

    private InfiniteCellSequence cellType;
    private Cell[][] cells;
    private Cell[] values;
    private int size;

    private SudokuCheckerWrapper checker;


    /**
     * setter checker
     * @param checker new checker
     */
    void setChecker(SudokuCheckerWrapper checker){
        this.checker = checker;
    }

    /**
     * setter for builder class
     * @param cellType *
     * @param cells *
     * @param values *
     * @param size *
     * @param checker *
     */
    void setter(InfiniteCellSequence cellType, Cell[][] cells,Cell[] values, int size, SudokuCheckerWrapper checker){
        this.cells = cells;
        this.cellType = cellType;
        this.values = values;
        this.checker = checker;
        this.size = size;
    }



    /**
     * default constructor
     */
    BasicSudoku(){
    }

    /**
     * constructor
     * @param cells board
     * @param values possible values
     */
    public BasicSudoku(Cell[][] cells, Cell[] values) {
        this.cells = cells;
        this.values = values;
        this.size = cells.length;
        checker = new SudokuCheckerWrapper(this);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cells[i][j] != null) {
                    cellType = (InfiniteCellSequence) cells[0][0];
                    break;
                }
            }
        }
    }
    /**
     * gets size of grid
     * @return size
     */
    @Override
    public int getSize(){
        return size;
    }

    /**
     * gets size of block
     * @return size
     */
    @Override
    public int getBlockSize(){
        return (int) Math.sqrt(size);
    }

    /**
     * retuns array of availible values
     * @return array
     */

    @Override
    public Cell[] availableValues(){
        return values;
    }

    /**
     * getter
     * @param column position
     * @param row position
     * @return cell
     */
    @Override
    public Cell getCell(int column, int row){
        return cells[column][row];
    }

    /**
     * gets row of cells
     * @param row position
     * @return row of cells
     */
    @Override
    public Cell[] getRow(int row){
        Cell[] out = new Cell[size];
        for (int i = 0; i < size ; i++){
        out[i] = cells[i][row];
        }
        return out;
    }

    /**
     * gets column of cells
     * @param column position
     * @return row of cells
     */
    @Override
    public Cell[] getColumn(int column){
        Cell[] out = new Cell[size];
        for (int i = 0; i < size ; i++){
            out[i] = cells[column][i];
        }
        return out;
    }

    /**
     * Returns cells in the specific block
     * @param globalColumn block column position
     * @param globalRow block row position
     * @return cells in the block from left to right, from top to bottom
     */
    @Override
    public Cell[] getBlock(int globalColumn, int globalRow){
        Cell[] out = new Cell[size];
        int blockSize = getBlockSize();
        for (int i = 0; i < blockSize; i++){
            for (int j = 0; j < blockSize;j++){
                out[i*getBlockSize() + j] = cells[globalColumn*blockSize+j][globalRow*blockSize+i];
            }
        }
        return out;
    }

    /**
     * possible values for cell
     * @param column position
     * @param row position
     * @return array of possible values
     */
    @Override
    public Cell[] getOptions(int column, int row){
        boolean isEmpty = true;
        Cell[] out = new Cell[size];
        for (int i = 0; i < size ; i ++){
            if(checker.canInsert(column, row, values[i])){
                out[i] = values[i];
                isEmpty = false;
            }
        }
        if (isEmpty){
            return new Cell[0];
        }
        return out;
    }
    /**
     * hint for cell value
     * @param column position
     * @param row position
     * @return cell value
     */
    @Override
    public Cell getHint(int column, int row){
        return ArrayUtils.singleElement(getOptions(column,row));
    }

    /**
     * hints for all cells
     * @return array of hints
     */
    @Override
    public Cell[][] getAllHints(){
        Cell[][] hints = new Cell[size][size];
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size;j++){
                hints[i][j] = getCell(i,j);
            }
        }
        return hints;
    }

    /**
     * insert element into sudoku
     * @param column position
     * @param row position
     * @param c cell
     * @return true if inserted, false otherwise
     */
    @Override
    public boolean putElement(int column, int row, Cell c) {
        if (checker.canInsert(column, row, c)) {
            cells[column][row] = c;
            return true;
        }
        return false;
    }
}

