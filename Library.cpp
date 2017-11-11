#include "Library.h"



Library::Library() : allBooks(nullptr), size(0)
{
}

Library::Library(const Library & other)
{
	allBooks = new Book[other.size];

	for (int i = 0; i < other.size; i++)
	{
		allBooks[i] = other.allBooks[i];
	}

	size = other.size;
}

Library & Library::operator=(const Library & other)
{
	if (this != &other)
	{
		Clear();

		allBooks = new Book[other.size];

		for (int i = 0; i < size; i++)
		{
			allBooks[i] = other.allBooks[i];
		}

		size = other.size;
	}

	return *this;
}


Library::~Library()
{
	Clear();
}


void Library::Clear()
{

	delete[] allBooks;
	allBooks = nullptr;
	size = 0;
}

void Library::AddBook(const Book& newBook)
{
	Book* books = new Book[size + 1];

	for (int i = 0; i < size; i++)
	{
		books[i] = allBooks[i];
	}

	books[size] = newBook;

	size++;

	delete [] allBooks;

	allBooks = books;
}

void Library::RemoveBook(int idx)
{
	if (((idx - 1) >= size) || size == 0)    
		throw std::out_of_range("out of range");

	idx--;

	Book* temp = allBooks;

	allBooks = new Book[size - 1];

	int i = 0;
	for (int j = 0; j < size; j++)
	{
		if (idx != j)		
			allBooks[i++] = temp[j];
	}

	delete[] temp;

	size--;
}

double Library::Average()
{
	double avg = 0;

	for (int i = 0; i < size; i++)
	{
		avg += allBooks[i].GetPages();
	}

	return avg / size;
}

void Library::SortByTitle()
{
	int min;

	for (int i = 0; i < size - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(allBooks[j].GetTitle(), allBooks[min].GetTitle()))
				min = j;
		}

		if (min != i)
			//swap([min],[i]);
	}

}

const Book& Library::operator[](int index) const
{
	if (index > size)
		throw std::out_of_range("bad index");

	return allBooks[index];
}

Book& Library::operator[](int index)
{
	if (index > size)
		throw std::out_of_range("bad index");

	return allBooks[index];
}

