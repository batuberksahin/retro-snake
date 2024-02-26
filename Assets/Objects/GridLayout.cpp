#include "GridLayout.h"

CellContent GridLayout::getCellContent(int row, int col) const {
    return _grid[row][col];
}

void GridLayout::setCellContent(int row, int col, CellContent content) {
    _grid[row][col] = content;
}