#pragma once
#include <iostream>

class Book
{
protected:
	char* title;
	unsigned int numbPages;

public:
	Book();

	Book(const char*, unsigned int);

	Book(const Book&);

	Book& operator=(const Book&);

	~Book();

public:
	const char* GetTitle() const;

	unsigned int GetPages() const;

	void SetTitle(const char*);

	void SetPages(unsigned int);

	bool friend operator<(const Book&, const Book&);

	friend std::ostream& operator<<(std::ostream&, const Book&);

	friend std::istream& operator >> (std::istream&, Book&);

protected:

	void CopyFrom(const Book& other);

	void Clear();

};

bool operator>(const Book&, const Book&);

