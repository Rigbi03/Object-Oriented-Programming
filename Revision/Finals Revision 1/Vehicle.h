#pragma once
#include <cstring>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

class Vehicle
{
	size_t id;
	char model[32];
	size_t range;

protected:

	void setRange(size_t inputRange);

public:

	static size_t idGenerator;

	Vehicle(const char* inputModel, size_t inputRange);
	
	char* getModel();
	size_t getRange();
};