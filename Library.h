#pragma once
#include "Book.h"

class Library
{
private:
	Book* allBooks;
	size_t size;

public:
	Library();

	Library(const Library&);

	Library& operator=(const Library&);

	~Library();

private:
	void Clear();

public:
	void AddBook(const Book&); 

	void RemoveBook(int idx);

	double Average();

	void SortByTitle();

	const Book& operator[](int) const;

	Book& operator[](int);

};

