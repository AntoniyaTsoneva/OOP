#pragma once
#include "Book.h"

class EBook : public Book
{
private:
	int sizeBytes;
	unsigned int views;

public:
	EBook();

	EBook(const char*, unsigned int, int, unsigned int);

	EBook(const EBook&);

	EBook& operator=(const EBook&);

	~EBook();

	const int GetBytes() const;

	const unsigned int GetViews() const;

	void SetBytes(int);

	void SetViews(unsigned int);


public:

	double Rating(const EBook&);
};

