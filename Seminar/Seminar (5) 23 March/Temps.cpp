#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

bool isLeapYear(const char* year)
{
	return atoi(year) % 4 != 0;
}


bool yearHasNotChanged(const char* string1, const char* string2)
{
	while (*string1)
	{
		if (*string1 != *string2)
			return false;
		string1++, string2++;
	}

	return true;
}

void dateCopy(char* dest, const char* source)
{
	for (size_t i = 0; i < 5; i++, dest++, source++)
	{
		*dest = *source;
	}
	++dest;
	*dest = '\0';
}

void yearCopy(char* dest, const char* source)
{
	source += 5;
	strncpy(dest, source,5);
}


int main()
{
	ifstream originalFile("temperatures.txt", ios::in);
	ofstream newFile("newTemperatures.txt", ios::out);
	char temp[1024];
	originalFile.getline(temp, 1024);
	cout << temp << endl;
	char minDay[6], maxDay[6], currentDate[11], currentYear[5], previousYear[5];
	double currentTemp, minTemp = 0.0, maxTemp = 0.0, tempsum = 0.0;
	
	if(!originalFile.is_open())
	{ 
		cerr << "Error not opening original File!\n";
		return 1;
	}

	if (!newFile.is_open())
	{
		cerr << "Error not opening new File!\n";
		return 1;
	}

	while(true)
	{
		
		originalFile.getline(currentDate, 11, ',');
		originalFile >> currentTemp;
		originalFile.ignore();

		strcpy(previousYear, currentYear);
		yearCopy(currentYear, currentDate);

		if (!yearHasNotChanged(currentYear, previousYear))
		{
			double avgTemp = (isLeapYear(previousYear)) ? tempsum / 366 : tempsum / 365;
			newFile << previousYear << " , " << avgTemp << " , " << minTemp << " " << minDay << " , " << maxTemp << " " << maxDay << endl;
			tempsum = 0;
		}
			

		if (minTemp > currentTemp)
		{
			minTemp = currentTemp;
			dateCopy(minDay, currentDate);
		}

		if (maxTemp < currentTemp)
		{
			maxTemp = currentTemp;
			dateCopy(maxDay, currentDate);
		}
	}
	return 0;
}