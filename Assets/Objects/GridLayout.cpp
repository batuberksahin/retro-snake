#include "GridLayout.h"

CellContent GridLayout::getCellContent(int row, int col) const {
    return _grid[row][col];
}
