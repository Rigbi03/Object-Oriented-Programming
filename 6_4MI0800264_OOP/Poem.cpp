#include "Poem.h"

void Poem::free()
{
	idGenerator--;

	for (size_t i = 0; i < size; i++)
	{
		delete[] key[i];
	}

	delete[] key;
	delete[] text;
}

void Poem::copy(const Poem& other)
{

	size = other.size;

	key = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		key[i] = new char[15];
		strcpy(key[i], other.key[i]);
	}

	text = new char[strlen(other.text) + 1];
	strcpy(text, other.text);
}

void Poem::updateIDGEN()
{
	idGenerator++;
}

Poem::Poem(const char* inputText, size_t numberOfWords, const char** words)
{
	id = idGenerator;
	updateIDGEN();

	text = new char[strlen(inputText) + 1];
	strcpy(text, inputText);

	size = numberOfWords;

	key = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		key[i] = new char[15];
		strcpy(key[i], words[i]);
	}

}

Poem::Poem(const Poem& other)
{
	copy(other);
	id = idGenerator;
	updateIDGEN();
}

Poem& Poem::operator= (const Poem& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Poem::Poem(Poem&& other) noexcept
{
	id = other.id;

	size = other.size;

	key = other.key;

	for (size_t i = 0; i < size; i++)
	{
		key[i] = other.key[i];
		other.key[i] = nullptr;
	}

	other.key = nullptr;

	text = other.text;
	other.text = nullptr;
}

Poem::~Poem()
{
	free();
}