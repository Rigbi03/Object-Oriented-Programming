#pragma once

class PlantType
{
	char* name;
	int place; // 0 - in the sun , 1 - neutral, 2 - in the shade
	int wateringFrequency;

	void free();

	void copy(const PlantType& other);

public:
	PlantType();

	PlantType(const char* inputName, int inputPlace, int inputWateringFrequency);

	PlantType(const PlantType& other);

	const PlantType& operator= (const PlantType& other);

	PlantType(PlantType&& other) noexcept;

	~PlantType();

	char* getName() const;
	void setName(const char* inputName);

	int getPlace() const;
	void setPlace(int inputPlace);

	int getWateringFrequency() const;
	void setWateringFrequency(int inputWateringFrequency);
};
