#pragma once
#include "Text.h"

class Poem : virtual public Text
{
	char** key;
	size_t size;

	void free();

	void copy(const Poem& other);

public:

	void updateIDGEN();

	Poem(const char* inputText, size_t numberOfWords, const char** words);

	Poem(const Poem& other);

	Poem& operator= (const Poem& other);

	Poem(Poem&& other) noexcept;

	~Poem();

	//void print()
	//{
	//	out; //<< "Argument Text: id: " << id << " , text: " << text << " , sizeOfParts: " << sizeOfPart[0] << " " << sizeOfPart[1] << " " << sizeOfPart[2] << " " << sizeOfPart[3] << "\n";
	//	return out;
	//}
};