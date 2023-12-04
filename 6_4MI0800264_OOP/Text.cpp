#include "Text.h"

size_t Text::idGenerator = 0;

void Text::setText(const char* inputText)
{
	text = new char[strlen(inputText) + 1];
	strcpy(text, inputText);
}

char* Text::getText() const
{
	return text;
}

size_t Text::getId() const
{
	return id;
}

size_t Text::getNextId()
{
	return idGenerator;
}


std::ofstream& operator<< (std::ofstream out, Text& text) 
{
	text.print();

	return out;
}
