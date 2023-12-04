#include "TextBook.h"

void TextBook::copy(const TextBook& other)
{
	size = other.size;
	count = other.count;
	texts = new Text * [size];

	for (size_t i = 0; i < size; i++)
	{
		texts[i] = other.texts[i];
	}
}

void TextBook::free()
{
	if (texts != nullptr)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (texts[i] != nullptr)
				delete[] texts[i];
		}
		delete[] texts;
	}
}

TextBook::TextBook(size_t inputSize)
{
	size = inputSize;
	count = 0;
	texts = new Text * [inputSize];
}

TextBook::TextBook(const TextBook& other)
{
	copy(other);
}

TextBook& TextBook::operator= (const TextBook& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

TextBook::TextBook(TextBook&& other) noexcept
{
	size = other.size;
	count = other.count;
	texts = other.texts;

	for (size_t i = 0; i < size; i++)
	{
		texts[i] = other.texts[i];
		other.texts[i] = nullptr;
	}

	other.texts = nullptr;
}

TextBook::~TextBook()
{
	free();
}

void TextBook::addText(const Text& text)
{
	//texts[count] = new Text(text);
	
	//*texts[count] = text;
}