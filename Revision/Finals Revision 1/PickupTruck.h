#pragma once
#include "Car.h"
#include "Truck.h"

class PickupTruck : public Car, public Truck
{
	std::vector<char*> schedule;
	char* tempTask;

public:

	PickupTruck(const char* inputModel, size_t inputRange, size_t inputSeats, size_t inputLoadCapacity, size_t inputCurrentLoad);

	~PickupTruck();

	void setSchedule(char* task);

	char* getNextTask();



	size_t getMaxRange();
};