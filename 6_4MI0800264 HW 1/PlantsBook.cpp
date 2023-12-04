#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)
#include "PlantsBook.h"
#include "PlantType.h"
#include "Plant.h"

int PlantsBook::getPlantsCountFromFile(const char* filePath)
{
	int count = 0;
	std::ifstream file(filePath, std::ios::beg);

	char buffer[1024];

	while (file)
	{
		file.getline(buffer, 1024);
		count++;
	}

	file.close();
	return count;
}

void PlantsBook::swap(PlantType& lhs, PlantType& rhs)
{
	PlantType temp(rhs);
	rhs = lhs;
	lhs = temp;
}

void PlantsBook::sortBookArray()
{
	bool wasSwapped = false;
	for (int i = 0; i < count - 1; i++)
	{
		wasSwapped = false;
		for (int j = i; j < count - 1; j++)
		{
			if (strcmp(plantsBook[j]->getName(), plantsBook[j + 1]->getName()) > 0)
			{
				swap(*plantsBook[j], *plantsBook[j + 1]);
				wasSwapped = true;
			}
		}

		if (!wasSwapped)
			break;
	}
}


void PlantsBook::sortBookFile()
{
	std::ofstream book(bookName, std::ios::beg | std::ios::trunc);

	if (!book.is_open())
	{
		throw std::runtime_error("File does not open for output!");
	}

	sortBookArray();

	for (size_t i = 0; i < count; i++)
	{
		book << plantsBook[i]->getName() << " " << plantsBook[i]->getPlace() << " " << plantsBook[i]->getWateringFrequency() << std::endl;
	}

	book.close();
}

void PlantsBook::free()
{
	for (size_t i = 0; i < count; i++)
	{
		plantsBook[i]->~PlantType();
		plantsBook[i] = nullptr;
	}

	if (plantsBook != nullptr)
	{

		delete[] plantsBook;
		plantsBook = nullptr;
	}

	count = 0;
}

void PlantsBook::copy(const PlantsBook& other)
{
	count = other.count;

	plantsBook = new PlantType * [count];

	for (size_t i = 0; i < count; i++)
	{
		plantsBook[i] = new PlantType;

		*plantsBook[i] = *other.plantsBook[i];
	}
}

PlantsBook::PlantsBook()
{
	plantsBook = nullptr;
	count = 0;
	bookName[0] = '\0';
}

PlantsBook::PlantsBook(const char* inputBookName)
{
	count = getPlantsCountFromFile(inputBookName) - 1; //reads last row, which is empty, so we remove 1

	plantsBook = new PlantType * [count];

	strcpy(bookName, inputBookName);

	std::ifstream book(bookName, std::ios::beg);

	if (!book.is_open())
	{
		throw std::runtime_error("File does not open for input!");
	}

	char tempName[1024];
	int tempPlace, tempWateringFrequency;

	for (size_t i = 0; i < count; i++)
	{
		plantsBook[i] = new PlantType;
		book >> tempName >> tempPlace >> tempWateringFrequency;;
		plantsBook[i]->setName(tempName);
		plantsBook[i]->setPlace(tempPlace);
		plantsBook[i]->setWateringFrequency(tempWateringFrequency);
	}

	book.close();
}

PlantsBook::PlantsBook(const PlantsBook& other)
{
	copy(other);
}

const PlantsBook& PlantsBook::operator= (const PlantsBook& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

PlantsBook::PlantsBook(PlantsBook&& other) noexcept
{
	plantsBook = other.plantsBook;
	other.plantsBook = nullptr;

	count = other.count;
	strcpy(bookName, other.bookName);
}

PlantsBook::~PlantsBook()
{
	free();
}

void PlantsBook::addPlantType(const PlantType& newPlantType)
{
	for (size_t i = 0; i < count; i++)
	{
		if (strcmp(plantsBook[i]->getName(), newPlantType.getName()) == 0)
		{
			throw std::runtime_error("Such plant type already exists!");
		}
	}

	plantsBook[count] = new PlantType;
	*plantsBook[count++] = newPlantType;

	sortBookFile();
}

bool PlantsBook::plantIsNotInBook(const Plant& plant)
{
	for (size_t i = 0; i < count; i++)
	{
		if (!strcmp(plantsBook[i]->getName(), plant.getName()))
			return false;
	}
	return true;
}
