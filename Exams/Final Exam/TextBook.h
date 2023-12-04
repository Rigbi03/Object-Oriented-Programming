#pragma once
#include "ArgumentText.hpp"
#include "Poem.h"

class TextBook
{
	Text** texts;
	size_t size;
	size_t count;

	void copy(const TextBook& other);

	void free();

public:

	TextBook(size_t inputSize);

	TextBook(const TextBook& other);

	TextBook& operator= (const TextBook& other);

	TextBook(TextBook&& other) noexcept;

	~TextBook();

	void addText(const Text& text);
};