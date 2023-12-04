#pragma once
#include "Text.h"

template<typename T>
class ArgumentText :  virtual public Text
{
	size_t sizeOfPart[4];
	T hiddenArgument;


	void copy(const ArgumentText& other)
	{
		setText(other.getText());

		for (size_t i = 0; i < 4; i++)
		{
			sizeOfPart[i] = other.sizeOfPart[i];
		}

		hiddenArgument = other.hiddenArgument;
	}

	void free()
	{
		idGenerator--;
		delete[] text;
	}

public:

	void updateIDGEN()
	{
		idGenerator++;
	}

	ArgumentText(const char* inputText,
		size_t sizeOfPart1, size_t sizeOfPart2, size_t sizeOfPart3, size_t sizeOfPart4,
		T inputHiddenArgument)
	{
		setText(inputText);
		id = idGenerator;
		updateIDGEN();

		sizeOfPart[0] = sizeOfPart1;
		sizeOfPart[1] = sizeOfPart2;
		sizeOfPart[2] = sizeOfPart3;
		sizeOfPart[3] = sizeOfPart4;

		hiddenArgument = inputHiddenArgument;
	}

	ArgumentText(const ArgumentText& other)
	{
		copy(other);
		id = idGenerator;
		updateIDGEN();
	}

	ArgumentText& operator= (const ArgumentText& other)
	{
		if (this != &other)
		{
			free();
			copy(other);
		}

		return *this;
	}

	ArgumentText(ArgumentText&& other)
	{
		text = other.text;
		other.text = nullptr;

		id = other.id;

		for (size_t i = 0; i < 4; i++)
		{
			sizeOfPart[i] = other.sizeOfPart[i];
		}

		hiddenArgument = other.hiddenArgument;
	}

	~ArgumentText()
	{
		free();
	}


	/*print()
	{
		out << "Argument Text: id: " << id << " , text: " << text << " , sizeOfParts: " << sizeOfPart[0]<< " " << sizeOfPart[1] << " " << sizeOfPart[2] << " " << sizeOfPart[3] << "\n";
		return out;
	}*/
};