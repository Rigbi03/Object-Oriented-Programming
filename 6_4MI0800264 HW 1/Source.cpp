#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)
#include "PlantsBook.h"
#include "PlantType.h"
#include "Plant.h"
#include "GreenHouse.h"

int main()
{
	PlantType lily("LILY", 1, 3);
	PlantsBook newBook("Test.txt");
	newBook.addPlantType(lily);

	Plant lily1(lily);
	lily1.setPlace(1);

	Greenhouse greenhouse(newBook, 2, 2, 1);

	greenhouse.addPlant(lily1);
	greenhouse.getCurrentPlantsCount();

	return 0;
}