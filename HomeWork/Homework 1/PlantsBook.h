#include "PlantType.h"
#include "Plant.h"
#pragma once

class PlantsBook
{
	PlantType** plantsBook;
	int count;
	char bookName[128];

	int getPlantsCountFromFile(const char* filePath);

	void swap(PlantType& lhs, PlantType& rhs);

	void sortBookArray();
	
	void sortBookFile();

	void free();

	void copy(const PlantsBook& other);

public:

	PlantsBook();

	PlantsBook(const char* inputBookName);

	PlantsBook(const PlantsBook& other);

	const PlantsBook& operator= (const PlantsBook& other);

	PlantsBook(PlantsBook&& other) noexcept;

	~PlantsBook();

	void addPlantType(const PlantType& newPlantType);

	bool plantIsNotInBook(const Plant& plant);

	
};