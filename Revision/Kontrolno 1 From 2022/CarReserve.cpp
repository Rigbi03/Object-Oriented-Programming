#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable : 4996)

struct Reservation
{
	char* startDate = new char[11];
	char* endDate = new char[11];
	
	

	Reservation(const char* startDate = nullptr, const char* endDate = nullptr)
	{
		strcpy(this->startDate, startDate);
		strcpy(this->endDate, endDate);
	}

	~Reservation()
	{
		delete[] startDate;
		delete[] endDate;
		startDate = endDate = nullptr;
	}

	char* getStartAndEndDate()
	{
		char* startAndEndDate = new char[22];
		strcpy(startAndEndDate, startDate);
		*startAndEndDate = ' ';

		while (!*endDate)
		{
			*startAndEndDate = *endDate;
			startAndEndDate++, endDate++;
		}

		*startAndEndDate = '\0';
		
		return startAndEndDate;
	}
};

struct Reservations
{
private:
	int count ;
	Reservation* reservations = new Reservation[count];
	
	void free()
	{
		delete[] reservations;
		reservations = nullptr;
		count = 0;
	}

	void copyFrom(const Reservations& other)
	{
		count = other.count;

		for (size_t i = 0; i < count; i++)
		{
			strcpy(reservations[i].startDate, other.reservations[i].startDate);
			strcpy(reservations[i].endDate, other.reservations[i].endDate);
		}
	}

public:
	Reservations()
	{
		reservations = nullptr;
		count = 0;
	}

	Reservations(const Reservations& other)
	{
		copyFrom(other);
	}

	Reservations& operator= (const Reservations& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}

	Reservation& operator[](int index) 
	{
		return reservations[index];
	}

	Reservations(Reservations&& other) noexcept
	{
		count = other.count;

		reservations = other.reservations;
		other.reservations = nullptr;
	}

	~Reservations()
	{
		free();
	}

	int getCount()
	{
		return count;
	}

	void AddReservation(const Reservation& reservation)
	{
		strcpy(reservations[count].startDate, reservation.startDate);
		strcpy(reservations[count].endDate, reservation.endDate);
		count++;
	}
};

class Car
{
private:
	int Id;
	char Type[50];
	int Year;
	Reservations reservations;
	
	

	void free()
	{
		reservations.~Reservations();
		Id = INT_MIN;
		Year = 0;	
	}

	void copyFrom(const Car& other)
	{
		Id = other.Id;
		strcpy(Type, other.Type);

		Year = other.Year;
	}

public:
	Car()
	{
		Id = INT_MIN;
		Type[0] = '\0';
		reservations.~Reservations();
		Year = 0;
	}

	Car(int inputId, char* inputType, int inputYear, Reservations inputReservations)
	{
		Id = inputId;
		strcpy(Type, inputType);
		Year = inputYear;
		reservations = inputReservations;
	}

	Car(const Car& other)
	{
		copyFrom(other);
	}

	Car(Car&& other) noexcept
	{
		Id = other.Id;
		Year = other.Year;

		Type = other.Type;
		other.Type = nullptr;
	}

	Car& operator= (const Car& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}

	~Car()
	{
		free();
	}

	int getId() const
	{
		return Id;
	}
	void setId(int inputId)
	{
		Id = inputId;
	}
	int getYear() const
	{
		return Year;
	}
	void setYear(int inputYear)
	{
		Year = inputYear;
	}
	char* getType() const
	{
		return Type;
	}
	void setType(const char* inputType)
	{
		strcpy(Type, inputType);
	}
	Reservations getReservations() const
	{
		return reservations;
	}
};


class Company
{
	char* dataBasePath = new char[1024];

	void free()
	{
		delete[] dataBasePath;
		dataBasePath = nullptr;
	}

	void copyFrom(const Company& other)
	{
		strcpy(dataBasePath, other.dataBasePath);
	}

public:

	Company()
	{
		dataBasePath = nullptr;
	}

	Company(const Company& other)
	{
		copyFrom(other);
	}

	Company(Company&& other)
	{
		dataBasePath = other.dataBasePath;
		other.dataBasePath = nullptr;
	}

	Company(const char* other)
	{
		strcpy(dataBasePath, other);
	}

	Company& operator= (const Company& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}

	~Company()
	{
		free();
	}

	void Add(const Car& car)
	{
		std::ofstream dataBase(dataBasePath, std::ios::app | std::ios::out);

		if (!dataBase.is_open())
		{
			throw std::runtime_error("Error with Opening File For Adding! ");
		}

		dataBase << "ID: " << car.getId() << "\n Type: " << car.getType() << "\n Year: " << car.getYear() << "\n Reservations: ";

		for (int i = 0; i < car.getReservations().getCount(); i++)
		{
			dataBase << car.getReservations()[i].startDate << " " << car.getReservations()[i].endDate << " , ";
		}
		dataBase << "\n";
	}

	bool Search(int inputId)
	{
		std::ifstream dataBase(dataBasePath, std::ios::beg | std::ios::in);

		char skipLineBuffer[1024];
		char buffer[4];
		int currentId = 0;

		if (!dataBase.is_open())
		{
			throw std::runtime_error("Error with Opening File For SEARCHING! ");
		}

		while (dataBase)
		{
			dataBase >> buffer >> currentId;
			dataBase.ignore();

			if (currentId = inputId)
				return true;

			dataBase >> skipLineBuffer >> skipLineBuffer >> skipLineBuffer;
			
		}

		std::cerr << "No car with such Id was Found";
	}
};


int main()
{
	Reservation newReservation("01/02/1998","02/02/1998");
	Reservations reservations;
	reservations.AddReservation(newReservation);
	Car newCar;
	newCar.setId(1);
	newCar.setType("BMW");
	newCar.setYear(2003);
	Company newCompany("Company");
	newCompany.Add(newCar);
	return 0;
}