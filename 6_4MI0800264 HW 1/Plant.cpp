#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)
#include "PlantsBook.h"
#include "PlantType.h"
#include "Plant.h"

void Plant::free()
{
	if (name == nullptr)
		return;

	delete[] name;
	name = nullptr;
}

void Plant::copy(const Plant& other)
{
	name = new char[strlen(other.getName()) + 1];

	strcpy(name, other.name);

	place = other.place;
	wateringFrequency = other.wateringFrequency;
}

Plant::Plant(const PlantType& type)
{
	name = new char[strlen(type.getName()) + 1];

	strcpy(name, type.getName());
	place = -1;
	wateringFrequency = -1;
}

const Plant& Plant::operator= (const Plant& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Plant::Plant(Plant&& other) noexcept
{
	name = other.name;
	other.name = nullptr;

	place = other.place;
	wateringFrequency = other.wateringFrequency;
}

Plant::~Plant()
{
	free();
}

char* Plant::getName() const
{
	return name;
}
void Plant::setName(const char* inputName)
{
	delete[] name;
	name = new char[strlen(inputName) + 1];

	strcpy(name, inputName);
}

int Plant::getPlace() const
{
	return place;
}
void Plant::setPlace(int inputPlace)
{
	if (inputPlace > 2 || inputPlace < 0)
	{
		throw std::runtime_error("You have entered invalid place. Please enter 0 for sun, 1 for neutral or 2 for shade!");
	}

	place = inputPlace;
}

int Plant::getWateringFrequency() const
{
	return wateringFrequency;
}
void Plant::setWateringFrequency(int inputWateringFrequency)
{
	wateringFrequency = inputWateringFrequency;
}
