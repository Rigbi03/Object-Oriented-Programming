#pragma once
#include "Figure.h"

class Pawn : public Figure
{
	Position position;

protected:

	std::ostream& print(std::ostream& out) const
	{
		if (this->getColor() == WHITE)
			return out << "WHITE PAWN";

		return out << "BLACK PAWN";
	}

public:

	Pawn(Color color, const Position& inputPosition) : Figure(color)
	{
		position = inputPosition;
	}

	Position getPosition() const
	{
		return position;
	}
};