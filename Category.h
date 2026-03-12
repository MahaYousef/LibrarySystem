#include "Book.h"
#ifndef CATEGORY_H
#define CATEGORY_H

class Category{
protected:
Book* first;
Book* last;
int bookCount;

public:
 string name;
 Category* next;
Category(string);
void addBook(string,string,string,bool);
int numofbooks();
void print();
void printcategory();
Book* getFirstBook(); 
Book *serchtitle(string);
Book * serchauthor(string);
string returnname();
 ~Category();


};
#endif