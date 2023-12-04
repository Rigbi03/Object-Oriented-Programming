#pragma once

#include "Position.h"


Position::Position(char file, int rank) : Position((int)(file - 'A'), rank) {}



char Position::getFile() const
{
	return file;
}

int Position::getRank() const
{
	return rank;
}

std::ostream& operator<<(std::ostream& out, const Position& position);
