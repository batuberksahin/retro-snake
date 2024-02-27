// This is not a game object

#ifndef RETROSNAKE_GRIDLAYOUT_H
#define RETROSNAKE_GRIDLAYOUT_H

#include <vector>
#include "../../Engine/Engine.h"
#include "../../Engine/Config.h"

const int GRID_ROWS = FIXED_WINDOW_WIDTH / CELL_SIZE;
const int GRID_COLS = FIXED_WINDOW_HEIGHT / CELL_SIZE;

enum class CellContent {
    Empty,
    Body,
    Food,
    Booster
};

class GridLayout {
public:
    GridLayout() {
        _grid.resize(GRID_ROWS, std::vector<CellContent>(GRID_COLS, CellContent::Empty));
    }

    CellContent getCellContent(int row, int col) const;
    void setCellContent(int row, int col, CellContent content);

    static std::pair<int, int> getCellCenterPosition(int row, int col) ;

    int getWidth();

    int getHeight();

private:
    std::vector<std::vector<CellContent>> _grid;

};


#endif //RETROSNAKE_GRIDLAYOUT_H
