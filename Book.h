#include <iostream>
using namespace std;

#ifndef BOOK_H
#define BOOK_H


class Book {
protected:
	string title;
	string author;
	string description;
	bool isBorrowed = false;


public:
	Book* next;
	Book(string="",string="",string="",bool=0);
	void borrowBook();
	void setNext(Book* n);
	Book* getNext() ;
	void returnBook() ;
	void printbook();
	string getTitle() ;
	string getAuthor() ;
	string getDescription();
	bool getBorrowed();

};
#endif