#include "LibrarySystem.h"
#include <fstream>
#include <sstream>

LibrarySystem::LibrarySystem() {
	first=NULL;
	last=NULL;
	numofCategorys=0;

}
LibrarySystem::~LibrarySystem() {
	Category * temp=NULL;
	while (first!=NULL)
	{
		temp=first;
		first=first->next;
		delete temp;
	}

}
void  LibrarySystem::addcategory(string n) {
	Category *newcat;
	newcat= new Category(n);
	newcat->next=nullptr;

	if (first == nullptr)              // if list empty
		first = last = newcat;
	else {
		last->next=newcat;
		last=newcat;
	}
	numofCategorys++;
}
Book*  LibrarySystem ::findBookByTitle(string t) {
	Category * cat=first;
	Book* book = nullptr;

	while(cat!=NULL) {
		book=cat->serchtitle(t);
		if(book!=nullptr)
			return book;

		cat=cat->next;

	}
	return nullptr;
}
Book* LibrarySystem ::findBookByAuthor(string a) {

	Category * cat=first;
	Book * book=nullptr;

	while(cat!=NULL) {
		book=cat->serchauthor(a);
		if(book!=nullptr)
			return book;

		cat=cat->next;
	}
	return nullptr;
}

void LibrarySystem ::displaycategory() {
	Category* current=first;
	int i=1;
	while(current!=NULL) {
		cout<<i<<"- ";
		current->printcategory();
		current = current->next;
		i++;
	}
}




void  LibrarySystem ::loadbooks() {

	ifstream fin("books.txt");

	if(!fin) {
		cout << "Could not open books.txt\n";
		return;
	}

	string line;
	Category* cat = nullptr;

	while(getline(fin, line)) {

		if(line.empty())
			continue;

		if(line.rfind("Category:", 0) == 0) {

			string name = line.substr(10);


			addcategory(name);
			cat = last;
		}

		else if(line.rfind("Book:",0) == 0) {


			string data = line.substr(6);
			stringstream ss(data);

			string title, author, description, borrowstr;

			getline(ss, title, '|');
			getline(ss, author, '|');
			getline(ss, description, '|');
			getline(ss, borrowstr);




			bool isborrow = (borrowstr == "1");

			cat->addBook(title, author, description, isborrow);
		}
	}
	fin.close();
}

void  LibrarySystem ::savechange() {
	ofstream fout("books.txt");

	Category *cat = first;

	while(cat != nullptr) {

		fout << "Category: ";
		fout << cat->returnname() << endl;

		Book *book = cat->getFirstBook();


		while(book != nullptr) {
			fout << "Book: ";
			fout<< book->getTitle() << " | "
			    << book->getAuthor() << " | "
			    <<book->getDescription()<<" | "
			    << book->getBorrowed()<< endl;

			book = book->getNext();
		}

		cat = cat->next;
		cout<<endl;
	}

	fout.close();
}

void LibrarySystem ::printmenu() {
	int choice;
	cout <<endl<< "===== Library Menu =====\n";
	cout << "1. Display Categories\n";
	cout << "2. Borrow Book\n";
	cout << "3. Return Book\n";
	cout << "4. Search Book by Title\n";
	cout << "5. Search Book by Author\n";
	cout << "6. Exit";//at exit we should save the chnges
	cout <<endl<< "=======================\n";
	cin >> choice;
	if(choice==1) {
		displaycategory();
		int choice1;
		cout<<endl<<"choose witch Category do you want: ";
		cin>>choice1;

		Category* temp=first;
		for(int i=0; i<choice1-1; i++) {
			temp=temp->next;
		}
		temp->print();

	}
	if(choice==2) {
		displaycategory();
		int choice1;
		cout<<endl<<"choose witch Category do you want: ";
		cin>>choice1;
		cout<<endl;


		Category* temp=first;
		for(int i=0; i<choice1-1; i++) {
			temp=temp->next;
		}
		temp->print();
		int choice2;
		cout<<endl<<"choose the book you want to borrow : ";
		cin>>choice2;
		cout<<endl;
		Book* book=temp->getFirstBook();
		for(int i=0; i<choice2-1; i++) {
			book=book->next;
		}
		if(book->getBorrowed()) {
			cout<< "Book already borrowed!\n";
			cout<<endl;
		}
		else {
			cout << "You borrowed: "<<book->getTitle()<<endl;
			book->borrowBook();
		}

	}
	if(choice==3) {
		Category* cat=first;
		string t;
		cout << "Enter title: ";
		getline(cin,t);
		Book * book=cat->getFirstBook();
		while(book!=NULL && book->getTitle()!=t ) {
			book=book->next;
		}
		if (!book->getBorrowed()) cout << "Book was not borrowed!\n";
		else {
			book->returnBook();
			cout << "You borrowed: " << book->getTitle() << "\n";
		}


	}
	if(choice==4) {
		string t;
		cout << "Enter title: ";
		cin.ignore();
		getline(cin, t);

		Book* book = findBookByTitle(t);


		if(book != nullptr) {
			cout << "The book you are searching for is:\n";
			book->printbook();
		}
		else {
			cout << "Book not found\n";
		}

	}
	if(choice==5) {
		string a;
		cout << "Enter author: ";
		cin.ignore();
		getline(cin, a);

		Book* book = findBookByAuthor(a);

		if(book != nullptr) {
			cout << "The book you are searching for is:\n";
			book->printbook();
		}
		else {
			cout << "Book not found\n";
		}

	}
	if(choice==6) {
		savechange();
		exit(0);
	}
}