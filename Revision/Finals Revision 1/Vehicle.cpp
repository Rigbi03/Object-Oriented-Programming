#include "Vehicle.h"

void Vehicle::setRange(size_t inputRange)
{
	range = inputRange;
}

size_t Vehicle::idGenerator = 0;

Vehicle::Vehicle(const char* inputModel, size_t inputRange)
{
	id = idGenerator;
	idGenerator++;
	strcpy(model, inputModel);
	range = inputRange;
}

char* Vehicle::getModel()
{
	return model;
}

size_t Vehicle::getRange()
{
	return range;
}