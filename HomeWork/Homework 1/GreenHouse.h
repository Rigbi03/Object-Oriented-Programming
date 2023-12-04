#pragma once

class Greenhouse
{
	PlantsBook availablePlants;
	Plant*** potRow; // 0 - sunny, 1 - neutral, 2 - shady
	int row0Size, row0count;
	int row1Size, row1count;
	int row2Size, row2count;

	void free();

	void copy(const Greenhouse& other);

	void addPlantToRow(const Plant& plant, int row, int rowSize, int& rowCount);

public:
	Greenhouse(const PlantsBook& plantsBook, int potsrow0Size, int potsrow1Size, int potsrow2Size);

	Greenhouse(const Greenhouse& other);

	const Greenhouse& operator= (const Greenhouse& other);

	Greenhouse(Greenhouse&& other) noexcept;

	~Greenhouse();

	void addPlant(const Plant& plant);

	const Plant* getPlant(int row, int place);

	int getCurrentPlantsCount();
};
