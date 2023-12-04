#include <iostream>
#include <fstream>
#include <cstring>

class UnsortedIntegerFile
{
	std::fstream file;
	char* filePath;
	/*bool isSorted(std::fstream file)
	{
		int currentValue, nextValue;
		file >> currentValue;

		while (file)
		{
			file >> nextValue;

			if (currentValue > nextValue) 
				return false;
		}
	}*/
public:

	UnsortedIntegerFile(const char* filePath)
	{
		this->filePath = new char[strlen(filePath) + 1];
		strcpy(this->filePath, filePath);

		file.open(this->filePath, std::ios::in | std::ios::out | std::ios::binary | std::ios::app);

		if (!file.is_open())
		{
			throw std::runtime_error("File did not open!");
		}
	}
	//	TODO: Finish CANNONICAL REPRESENTATION
	//Operator =, Copy
	//Destructor
	~UnsortedIntegerFile()
	{
		file.close();
	}

	int get(int pos)
	{
		int result = 0;

		file.seekg(pos * sizeof(int), std::ios::beg);
		file.read((char*)&result, sizeof(int));

		return result;
	}

	int fileSize()
	{
		file.seekp(0, std::ios::end);
		return file.tellp();
	}

	void set(int pos, int value)
	{
		file.seekp(pos * sizeof(int), std::ios::beg);
		file.write((char*)&value, sizeof(int));
	}

	void swap(int posI, int posJ)
	{
		int valueI = get( posI), valueJ = get( posJ);

		set(posI, valueJ);
		set(posJ, valueI);
	}

	void selectionSortBinaryFile()
	{
		file.seekg(0, std::ios::beg) , file.seekp(0, std::ios::end);
		int minPos = 0, minValue = get(0), currPos = minPos + 1, currValue = get(1);
		bool wasSwapped = false;

		while (file)
		{
			wasSwapped = false;

			while (file)
			{
				if (minValue > currValue) 
				{
					swap(minPos, currPos);
					wasSwapped = true;
				}
				currPos++;
			}

			if (!wasSwapped)
				return;

			minPos++, currPos = minPos + 1;
			file.seekg(minPos, std::ios::beg);
		}
	}

	int binarySearchInBinaryFile(int searchedValue)
	{
		file.seekg(0, std::ios::beg), file.seekp(0, std::ios::end);
		int maxPos = file.tellp(), minPos = file.tellg(), currPos = fileSize() / 2, currValue = get(currPos);

		while (currValue != searchedValue)
		{
			if (currPos >= maxPos || currPos <= minPos)
			{
				throw std::runtime_error("No such Value Exists!");
			}
			
			if (currValue == searchedValue)
				return currPos;

			else if (currValue < searchedValue)
			{
				currPos = (currPos + maxPos) / 2;
			}
			else
			{
				currPos = (currPos + minPos) / 2;
			}

			currValue = get(currPos);
		}
	}
};

int main()
{
	//std::fstream file("Problem1.dat", std::ios::app | std::ios::in | std::ios::out | std::ios::binary);
	return 0;
}