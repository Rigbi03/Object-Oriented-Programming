#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)
#include "PlantsBook.h"
#include "PlantType.h"
#include "Plant.h"
#include "GreenHouse.h"


void Greenhouse::free()
{
	for (size_t i = 0; i < row0Size; i++)
	{
		if (potRow[0][i] != nullptr)
			potRow[0][i]->~Plant();
	}

	for (size_t i = 0; i < row1Size; i++)
	{
		if (potRow[1][i] != nullptr)
			potRow[1][i]->~Plant();
	}

	for (size_t i = 0; i < row2Size; i++)
	{
		if (potRow[2][i] != nullptr)
			potRow[2][i]->~Plant();
	}

	for (size_t i = 0; i < 3; i++)
	{
		if (potRow[i] != nullptr)
			delete[] potRow[i];
	}

	if (potRow != nullptr)
		delete[] potRow;
}

void Greenhouse::copy(const Greenhouse& other)
{
	availablePlants = other.availablePlants;
	row0Size = other.row0Size, row0count = other.row0count;
	row1Size = other.row1Size, row1count = other.row1count;
	row2Size = other.row2Size, row2count = other.row2count;
	potRow = new Plant * *[3];
	potRow[0] = new Plant * [row0Size] {nullptr};
	potRow[1] = new Plant * [row1Size] {nullptr};
	potRow[2] = new Plant * [row2Size] {nullptr};

	PlantType temp("temp", 0, 1);

	for (size_t i = 0; i < row0Size; i++)
	{
		potRow[0][i] = new Plant(temp);
		*potRow[0][i] = *other.potRow[0][i];
	}

	for (size_t i = 0; i < row1Size; i++)
	{
		potRow[1][i] = new Plant(temp);
		*potRow[1][i] = *other.potRow[1][i];
	}

	for (size_t i = 0; i < row2Size; i++)
	{
		potRow[2][i] = new Plant(temp);
		*potRow[2][i] = *other.potRow[2][i];
	}
}

void Greenhouse::addPlantToRow(const Plant& plant, int row, int rowSize, int& rowCount)
{
	PlantType temp("temp",0,2);

	int newPlantSpotNumber = -2;

	for (size_t i = 0; i < rowSize; i++)
	{
		if (potRow[row][i] == nullptr)
		{
			potRow[row][i] = new Plant(temp);
			*potRow[row][i] = plant;
			newPlantSpotNumber = i;
			break;
		}
	}

	if (newPlantSpotNumber != -2 && potRow[row][newPlantSpotNumber]->getPlace() != row )
		potRow[row][newPlantSpotNumber]->setWateringFrequency(potRow[row][newPlantSpotNumber]->getWateringFrequency() - (row - potRow[row][newPlantSpotNumber]->getPlace()));

	if (newPlantSpotNumber != -2 && potRow[row][newPlantSpotNumber]->getWateringFrequency() < 1)
		potRow[row][newPlantSpotNumber]->setWateringFrequency(1);

	rowCount++;
}

Greenhouse::Greenhouse(const PlantsBook& plantsBook, int potsrow0Size, int potsrow1Size, int potsrow2Size)
{
	availablePlants = plantsBook;
	potRow = new Plant * *[3];
	potRow[0] = new Plant * [potsrow0Size] {nullptr};
	potRow[1] = new Plant * [potsrow1Size] {nullptr};
	potRow[2] = new Plant * [potsrow2Size] {nullptr};

	row0Size = potsrow0Size, row0count = 0;
	row1Size = potsrow1Size, row1count = 0;
	row2Size = potsrow2Size, row2count = 0;
}

Greenhouse::Greenhouse(const Greenhouse& other)
{
	copy(other);
}

const Greenhouse& Greenhouse::operator= (const Greenhouse& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Greenhouse::Greenhouse(Greenhouse&& other) noexcept
{
	availablePlants = other.availablePlants;
	row0Size = other.row0Size, row0count = other.row0count;
	row1Size = other.row1Size, row1count = other.row1count;
	row2Size = other.row2Size, row2count = other.row2count;
	potRow = other.potRow;

	for (size_t i = 0; i < row0Size; i++)
	{
		potRow[0][i] = other.potRow[0][i];
		other.potRow[0][i] = nullptr;
	}

	for (size_t i = 0; i < row1Size; i++)
	{
		potRow[1][i] = other.potRow[1][i];
		other.potRow[1][i] = nullptr;
	}

	for (size_t i = 0; i < row2Size; i++)
	{
		potRow[2][i] = other.potRow[2][i];
		other.potRow[2][i] = nullptr;
	}
	for (size_t i = 0; i < 3; i++)
	{
		potRow[i] = other.potRow[i];
		other.potRow[i] = nullptr;
	}
	other.potRow = nullptr;
}

Greenhouse::~Greenhouse()
{
	free();
}

void Greenhouse::addPlant(const Plant& plant)
{
	if (availablePlants.plantIsNotInBook(plant))
		throw std::runtime_error("You cannot add this plant! There is no such Type! \n");

	if (row0count >= row0Size && row1count >= row1Size && row2count >= row2Size)
		throw std::runtime_error("There is no place for anymore plants in this Greenhouse! \n");

	switch (plant.getPlace())
	{
	case 0:
		if (row0count >= row0Size)
		{
			if (row1count < row1Size)
				addPlantToRow(plant, 1,row1Size, row1count);
			else
				addPlantToRow(plant, 2,row2Size, row2count);
		}
		else
			addPlantToRow(plant, 0,row0Size, row0count);

		break;

	case 1:
		if (row1count >= row1Size)
		{
			if (row2count < row2Size)
				addPlantToRow(plant, 2,row2Size, row2count);
			else
				addPlantToRow(plant, 0,row0Size, row0count);
		}
		else
			addPlantToRow(plant, 1,row1Size, row1count);

		break;

	case 2:
		if (row2count >= row2Size)
		{
			if (row0count < row0Size)
				addPlantToRow(plant, 0,row0Size, row0count);
			else
				addPlantToRow(plant, 1,row1Size, row1count);
		}
		else
			addPlantToRow(plant, 2,row2Size, row2count);

		break;

	}

}

const Plant* Greenhouse::getPlant(int row, int place)
{
	if (row < 0 || row > 2 || place < 0)
		throw std::runtime_error("You have entered invalid row or a negative place!");
	else if ((row == 0 && place > row0Size) || (row == 1 && place > row1Size) || (row == 2 && place > row2Size))
		throw std::runtime_error("You have entered place higher than the row's size!");

	Plant* newPlant = potRow[row][place];
	potRow[row][place] = nullptr;

	return newPlant;
}

int Greenhouse::getCurrentPlantsCount()
{
	int count = 0;

	for (size_t number = 0; number < row0Size; number++)
	{
		count += (potRow[0][number] == nullptr) ? 0 : 1;
	}

	for (size_t number = 0; number < row1Size; number++)
	{
		count += (potRow[1][number] == nullptr) ? 0 : 1;
	}

	for (size_t number = 0; number < row2Size; number++)
	{
		count += (potRow[2][number] == nullptr) ? 0 : 1;
	}

	return count;
}
