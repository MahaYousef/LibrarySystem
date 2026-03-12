# Library System in C++

A console-based library management system written in C++.  
Users can browse categories, borrow and return books, and search for books by title or author.

----------------------------------------

## Features

- Display all book categories
- View books in each category
- Borrow and return books
- Search for a book by title
- Search for books by author
- Save changes to a file (`books.txt`) so data persists

----------------------------------------

## Installation / How to Run

1. Make sure you have a **C++ compiler** (like g++, Visual Studio, or Code::Blocks).
2. Clone or download the repository.
3. Open terminal / command prompt in the project folder.
4. Compile all `.cpp` files:

```bash
g++ main.cpp Book.cpp Category.cpp LibrarySystem.cpp -o LibrarySystem
