#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)
#include "PlantsBook.h"
#include "PlantType.h"
#include "Plant.h"


void PlantType::free()
{
	if (name == nullptr)
		return;

	delete[] name;
	name = nullptr;
}

void PlantType::copy(const PlantType& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	if (other.place > 2 || other.place < 0)
	{
		throw std::runtime_error("You have entered invalid place. Please enter 0 for sun, 1 for neutral or 2 for shade!");
	}

	place = other.place;
	wateringFrequency = other.wateringFrequency;
}

PlantType::PlantType()
{
	name = nullptr;
	place = 1;
	wateringFrequency = 3;
}

PlantType::PlantType(const char* inputName, int inputPlace, int inputWateringFrequency)
{
	if (inputPlace > 2 || inputPlace < 0)
	{
		throw std::runtime_error("You have entered invalid place. Please enter 0 for sun, 1 for neutral or 2 for shade!");
	}

	name = new char[strlen(inputName) + 1];
	strcpy(name, inputName);

	place = inputPlace;
	wateringFrequency = inputWateringFrequency;
}

PlantType::PlantType(const PlantType& other)
{
	copy(other);
}

const PlantType& PlantType::operator= (const PlantType& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

PlantType::PlantType(PlantType&& other) noexcept
{
	name = other.name;
	other.name = nullptr;

	place = other.place;
	wateringFrequency = other.wateringFrequency;
}

PlantType::~PlantType()
{
	free();
}

char* PlantType::getName() const
{
	return name;
}
void PlantType::setName(const char* inputName)
{
	delete[] name;
	name = new char[strlen(inputName) + 1];

	strcpy(name, inputName);
}

int PlantType::getPlace() const
{
	return place;
}
void PlantType::setPlace(int inputPlace)
{
	if (inputPlace > 2 || inputPlace < 0)
	{
		throw std::runtime_error("You have entered invalid place. Please enter 0 for sun, 1 for neutral or 2 for shade!");
	}

	place = inputPlace;
}

int PlantType::getWateringFrequency() const
{
	return wateringFrequency;
}
void PlantType::setWateringFrequency(int inputWateringFrequency)
{
	wateringFrequency = inputWateringFrequency;
}

