
#include "LibrarySystem.h"

int main() {

	LibrarySystem library;

	library.loadbooks();

	while(true) {
		library.printmenu();
	}

	return 0;
}