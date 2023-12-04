#include "Figure.h"
#include "Board.h"
#include "Position.h"


int main()
{
    Board board;

    board.move(Position('A', 2), Position('A', 4));
    board.move(Position('A', 7), Position('A', 6));

    std::cout << board << std::endl;

    // Expected Output:
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | - |      A       |      B       |      C       |      D       |      E       |      F       |      G       |      H       | - |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 8 |  Black Rook  | Black Knight | Black Bishop | Black Queen  |  Black King  | Black Bishop | Black Knight |  Black Rook  | 8 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 7 |              |  Black Pawn  |  Black Pawn  |  Black Pawn  |  Black Pawn  |  Black Pawn  |  Black Pawn  |  Black Pawn  | 7 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 6 |  Black Pawn  |              |              |              |              |              |              |              | 6 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 5 |              |              |              |              |              |              |              |              | 5 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 4 |  White Pawn  |              |              |              |              |              |              |              | 4 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 3 |              |              |              |              |              |              |              |              | 3 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 2 |              |  White Pawn  |  White Pawn  |  White Pawn  |  White Pawn  |  White Pawn  |  White Pawn  |  White Pawn  | 2 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | 1 |  White Rook  | White Knight | White Bishop | White Queen  |  White King  | White Bishop | White Knight |  White Rook  | 1 |
    // ---------------------------------------------------------------------------------------------------------------------------------
    // | - |      A       |      B       |      C       |      D       |      E       |      F       |      G       |      H       | - |
    // ---------------------------------------------------------------------------------------------------------------------------------

    return 0;
}


