#pragma once
#include "Vehicle.h"

class Truck : virtual public Vehicle
{
	size_t loadCapacity;
	size_t currentLoad;

public:

	Truck(const char* inputModel, size_t inputRange, size_t inputLoadCapacity, size_t inputCurrentLoad);

	void load(size_t weight);

	void unload(size_t weight);

	size_t getMaxRange();

	size_t getCurrentLoad();
};