#pragma once
#include "Figure.h"

const size_t BOARD_SIZE = 8;

class Board {
private:
    Color turn;
    Figure* board[BOARD_SIZE][BOARD_SIZE];

public:
    Board();

    Figure* get(const Position& position);

    void move(const Position& from, const Position& to); // Should throw exception if move is not valid !

    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};

std::ostream& operator<<(std::ostream& out, const Board& board);