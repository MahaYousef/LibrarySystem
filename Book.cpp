#include "Book.h"

Book::Book(string t,string a, string d, bool b) {
	title = t;
	author = a;
	description = d;
	isBorrowed = b;
	next = nullptr;
}
string Book:: getTitle() {

	title.erase(0, title.find_first_not_of(" "));
	title.erase(title.find_last_not_of(" ") + 1);



	return title;
}
string Book:: getAuthor() {
	author.erase(0, author.find_first_not_of(" "));
	author.erase(author.find_last_not_of(" ") + 1);
	return author;
}
bool  Book :: getBorrowed() {
	return isBorrowed;
}
void Book::borrowBook() {
	isBorrowed = true;
}
void Book::returnBook()
{
	isBorrowed = false;
}
void Book::setNext(Book* n)
{
	next = n;
}
Book* Book:: getNext()
{
	return next;
}
string Book:: getDescription() {
	return description;
}
void Book::printbook() {
	cout << "Title: " << title
	     << " | Author: " << author
	     << " | Description: " << description
	     << " | Borrowed: " << isBorrowed
	     << endl;
}
