#pragma once

class Plant
{
	char* name;
	int place; // -1 - undefined, 0 - in the sun, 1 - neutral, 2 - in the shade
	int wateringFrequency; // -1 - undefined

	void free();

	void copy(const Plant& other);
public:

	Plant(const PlantType& type);

	const Plant& operator= (const Plant& other);

	Plant(Plant&& other) noexcept;

	~Plant();

	char* getName() const;
	void setName(const char* inputName);

	int getPlace() const;
	void setPlace(int inputPlace);

	int getWateringFrequency() const;
	void setWateringFrequency(int inputWateringFrequency);
};