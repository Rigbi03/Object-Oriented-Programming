#pragma once

#include "Figure.h"
#include "Board.h"

class Position {
private:
    int file; // A - H
    int rank; // 1 - 8

    static int sign(int x) {
        return (x > 0) - (x < 0);
    }

public:
    bool isOnSameDiagonal(const Position& other) const {
        return abs(this->file - other.file) == abs(this->rank - other.rank);
    }

    bool isOnSameRank(const Position& other) const {
        return this->rank == other.rank;
    }

    bool isOnSameFile(const Position& other) const {
        return this->file == other.file;
    }

    std::vector<Position> inBetween(const Position& other) const {
        assert(isOnSameFile(other) || isOnSameRank(other) || isOnSameDiagonal(other));

        const int r0 = this->getRank();
        const int r1 = other.getRank();
        const int dr = sign(r1 - r0);

        const int c0 = this->getFile();
        const int c1 = other.getFile();
        const int dc = sign(c1 - c0);

        std::vector<Position> result;
        for (int r = r0 + dr, c = c0 + dc; r != r1 || c != c1; r += dr, c += dc) {
            result.push_back(Position(r, c));
        }
        return result;
    }

    Position(int file, int rank) {
        assert(file > -1 && file < BOARD_SIZE);
        this->file = file;

        assert(rank > -1 && rank < BOARD_SIZE);
        this->rank = rank;
    }

    Position(char inputFile, int inputRank) : Position((int)(file - 'A'), rank);

    

    char getFile() const;

    int getRank() const;

    friend std::ostream& operator<<(std::ostream& out, const Position& position);
};

std::ostream& operator<<(std::ostream& out, const Position& position);