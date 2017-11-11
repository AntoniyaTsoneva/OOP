#include "Book.h"



Book::Book() : title(nullptr), numbPages(0)
{
}

Book::Book(const char * t, unsigned int n)
{
	title = new char[strlen(t) + 1];
	strcpy(title, t);

	numbPages = n;
}

Book::Book(const Book & other)
{
	CopyFrom(other);
}

Book & Book::operator=(const Book & other)
{
	if (this != &other)
	{
		Clear();
		CopyFrom(other);
	}

	return *this;
}


Book::~Book()
{
	Clear();
}

void Book::CopyFrom(const Book & other)
{
	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	numbPages = other.numbPages;

}

void Book::Clear()
{
	delete[] title;

	title = nullptr;
}

const char * Book::GetTitle() const
{
	return title ? title : "";
}

unsigned int Book::GetPages() const
{
	return numbPages;
}

void Book::SetTitle(const char * t)
{
	if (title == NULL)
		return;
	
	delete[] title;

	title = new char[strlen(t) + 1];
	strcpy(title, t);
}

void Book::SetPages(unsigned int p)
{
	numbPages = p;
}

bool operator<(const Book & b1, const Book & b2)
{
	if (strcmp(b1.title, b2.title) < 0)
		return true;

	else if (strcmp(b1.title, b2.title) > 0)
		return false;
}

std::ostream & operator<<(std::ostream & ostr, const Book & b)
{
	return ostr << b.title << ' ' << b.numbPages << std::endl;
}

std::istream & operator >> (std::istream & istr, Book & b)
{
	char buff[256];
	istr.getline(buff, 255);

	delete[] b.title;

	b.title = new char[strlen(buff) + 1];
	strcpy(b.title, buff);

	istr >> b.title >> b.numbPages;

	return istr;
}

bool operator>(const Book & b1, const Book & b2)
{
	return ((b1 < b2) ? false : true);
}
