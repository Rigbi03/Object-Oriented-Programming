#include "Car.h"

bool Car::noPassengers()
{
	for (size_t i = 0; i < seats; i++)
	{
		if (passengers[i] != nullptr)
			return false;
	}

	return true;
}

size_t Car::getNumberOfPassengers()
{
	size_t count = 0;

	for (size_t i = 0; i < seats; i++)
	{
		if (passengers[i] != nullptr)
			count++;
	}

	return count;
}

Car::Car(const char* inputModel, size_t inputRange, size_t inputSeats) : Vehicle(inputModel, inputRange)
{
	seats = inputSeats;
	passengers = new char* [seats];
	for (size_t i = 0; i < seats; i++)
	{
		passengers[i] = nullptr;
	}
}

Car::~Car()
{
	this->idGenerator--;

	for (size_t i = 0; i < seats; i++)
	{
		if (passengers[i] != nullptr)
			delete[] passengers[i];
	}
	if (passengers != nullptr)
		delete[] passengers;
}

void Car::addPassenger(const char* name)
{

	for (size_t i = 0; i < seats; i++)
	{
		if (passengers[i] == nullptr)
		{
			passengers[i] = new char[strlen(name) + 1];
			strcpy(passengers[i], name);
			return;
		}
	}

	throw std::runtime_error("There are no seats left!");
}


void Car::removePassenger(const char* name)
{
	if (noPassengers())
		throw std::runtime_error("There are no passengers in the car!");

	for (size_t i = 0; i < seats; i++)
	{
		if (!strcmp(passengers[i], name))
		{
			delete[] passengers[i];
			passengers[i] = nullptr;
			return;
		}
	}

	throw std::runtime_error("There is no passenger with such name in the car!");
}

size_t Car::getMaxRange()
{
	int maxRange = (int)(getRange() - (size_t)(getNumberOfPassengers() * 100));

	if (maxRange < 0)
		throw std::runtime_error("Max Range is a negative number. Please unload some weight!");

	return (size_t)maxRange;
}