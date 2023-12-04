#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <cassert>
#include "Position.h"
#include "Board.h"

enum Color {
    WHITE,
    BLACK
};

class Figure {
protected:
    Color color;

protected:
    virtual std::ostream& print(std::ostream& out) const;

public:
    Figure(const Color& color);

    Color getColor() const;

    Position getPosition() const;

    virtual bool canMove(const Board& board, const Position& from, const Position& to) = 0;

    friend std::ostream& operator<<(std::ostream& out, const Figure& figure);
};

std::ostream& operator<<(std::ostream& out, const Figure& figure);
