#include "Category.h"


Category::Category(string n) {
	name=n;
	first = NULL;
	last = NULL;
	bookCount = 0;
}
string Category::returnname() {
	return name;
}

void Category:: addBook(string t,string a,string d,bool b) {
	Book *newbook;
	newbook= new Book(t,a,d,b);

	if (first == nullptr)              // if list empty
		first = last = newbook;
	else {
		last->setNext(newbook);
		last=newbook;
	}
	bookCount++;

}

int Category:: numofbooks() {
	return bookCount;
}
void  Category::printcategory() {
	cout<<name<<endl;
}
void Category:: print() {

	Book * current=first;
	int i=1;
	while (current!=NULL)
	{
		cout<<i<<"- ";
		current->printbook();
		current = current->getNext();
		i++;
	}

}
Category::~Category() {
	Book * temp=NULL;
	while (first!=NULL)
	{
		temp=first;
		first=first->next;
		delete temp;
	}

}
Book* Category::getFirstBook() {
	return first;
}

Book *Category::serchtitle(string t) {
	Book * temp=first;
	while(temp!=NULL) {
		if(temp->getTitle()==t)
			return temp;
		else
			temp=temp->next;
	}
	return NULL;
}

Book * Category:: serchauthor(string a) {
	Book * temp=first;
	while(temp!=NULL) {
		if(temp->getAuthor()==a)
			return temp;
		else
			temp=temp->next;
	}
	return NULL;
}