#include "PickupTruck.h"

PickupTruck::PickupTruck(const char* inputModel, size_t inputRange,
	size_t inputSeats,
	size_t inputLoadCapacity, size_t inputCurrentLoad) :
	Vehicle(inputModel, inputRange),
	Car(inputModel, inputRange, inputSeats),
	Truck(inputModel, inputRange, inputLoadCapacity, inputCurrentLoad)
{
	tempTask = nullptr;
}

PickupTruck::~PickupTruck()
{
	if (tempTask != nullptr)
		delete[] tempTask;
}

void PickupTruck::setSchedule(char* task)
{
	schedule.push_back(task);
}

char* PickupTruck::getNextTask()
{

	if (tempTask != nullptr)
		delete[] tempTask;

	tempTask = new char[strlen(schedule[schedule.size() - 1]) + 1];
	strcpy(tempTask, schedule[schedule.size() - 1]);
	
	schedule.pop_back();

	return tempTask;

}

size_t PickupTruck::getMaxRange()
{
	int maxRange = getRange() - ((getNumberOfPassengers() * 50) + getCurrentLoad() * 3);

	if (maxRange < 0)
		throw std::runtime_error("Max Range is a negative number. Please unload some weight!");

	return (size_t)maxRange;
}