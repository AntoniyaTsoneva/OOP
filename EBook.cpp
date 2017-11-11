#include "EBook.h"



EBook::EBook() : sizeBytes(0), views(0)
{
}

EBook::EBook(const char * t, unsigned int p, int s, unsigned int v) :
	Book(t,p) , sizeBytes(s), views(v)
{
	s = 0;
	v = 0;
}

EBook::EBook(const EBook & other) : Book(other)
{
	sizeBytes = other.sizeBytes;
	views = other.views;
}

EBook & EBook::operator=(const EBook & other)
{
	if(this != &other)
	{
		Book::Clear();
		Book::operator=(other);

		sizeBytes = other.sizeBytes;
		views = other.views;

	}

	return *this;
	
}


EBook::~EBook()
{
}

const int EBook::GetBytes() const
{
	return sizeBytes;
}

const unsigned int EBook::GetViews() const
{
	return views;
}

void EBook::SetBytes(int b)
{
	sizeBytes = b;
}

void EBook::SetViews(unsigned int v)
{
	views = v;
}

double EBook::Rating(const EBook & b)
{
	
	if (b.views > 200)
		return 5;

	else
		return b.views / 40;
}
