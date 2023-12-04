#pragma once
#include "Vehicle.h"

class Car : virtual public Vehicle
{
private:

	size_t seats;
	char** passengers;

	bool noPassengers();

protected:

	size_t getNumberOfPassengers();

public:

	Car(const char* inputModel, size_t inputRange, size_t inputSeats);

	~Car();
	
	void addPassenger(const char* name);

	void removePassenger(const char* name);

	size_t getMaxRange();
};