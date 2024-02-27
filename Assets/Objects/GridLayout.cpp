#include "GridLayout.h"

CellContent GridLayout::getCellContent(int row, int col) const {
    return _grid[row][col];
}

void GridLayout::setCellContent(int row, int col, CellContent content) {
    _grid[row][col] = content;
}

std::pair<int, int> GridLayout::getCellCenterPosition(int row, int col) {
    int centerX = (col) * CELL_SIZE;
    int centerY = (row) * CELL_SIZE;
    return std::make_pair(centerX + (CELL_SIZE / 2), centerY + (CELL_SIZE / 2));
}

int GridLayout::getWidth() {
    return _grid.size();
}

int GridLayout::getHeight() {
    return _grid[0].size();
}
