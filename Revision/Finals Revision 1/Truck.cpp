#include "Truck.h"


Truck::Truck(const char* inputModel, size_t inputRange,
	size_t inputLoadCapacity, size_t inputCurrentLoad) : Vehicle(inputModel, inputRange)
{
	loadCapacity = inputLoadCapacity;
	currentLoad = inputCurrentLoad;

	if (currentLoad > loadCapacity)
		throw std::runtime_error("Truck is overloaded!!!!");
}

void Truck::load(size_t weight)
{
	if (currentLoad + weight > loadCapacity)
		throw std::runtime_error("Truck is can not load more weight!!!!");

	currentLoad += weight;
}

void Truck::unload(size_t weight)
{
	if ((int)currentLoad - (int)weight < 0)
		throw std::runtime_error("Can not remove more than current Load!!!!");

	currentLoad -= weight;
}

size_t Truck::getMaxRange()
{
	int maxRange = (int)getRange() - (int)currentLoad;

	if (maxRange < 0)
		throw std::runtime_error("Max Range is a negative number. Please unload some weight!");

	return (size_t)maxRange;
}

size_t Truck::getCurrentLoad()
{
	return currentLoad;
}