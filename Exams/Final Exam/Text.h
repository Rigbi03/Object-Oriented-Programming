#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

class Text
{
protected:
	

	char* text;
	size_t id;

	void setText(const char* inputText);

	size_t getId() const;

public:

	
	static size_t idGenerator;

	size_t getNextId();

	virtual void updateIDGEN() = 0;

	char* getText() const;
	
	virtual void print() const
	{

	}


	friend std::ofstream& operator<< (std::ofstream out, const Text* text);
};

std::ofstream& operator<< (std::ofstream out, const Text* text);