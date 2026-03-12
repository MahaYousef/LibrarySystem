#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include "Category.h"
using namespace std;
class LibrarySystem {
protected:
	Category* first;
	Category* last;
	int numofCategorys;
	Category * next;

public:
	LibrarySystem();
	~LibrarySystem();
	void addcategory(string );
	void printmenu();
	void displaycategory();
	void loadbooks();
	void savechange();
	Book* findBookByTitle(string t);
	Book* findBookByAuthor(string a);

};
#endif