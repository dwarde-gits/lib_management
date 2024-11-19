#ifndef BOOK_MANAGER_H
#define BOOK_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Class definition for Book
class Book
{
public:
    int bookID;
    string title;
    string author;
    string genre;
    string status;

    // Method to display book details
    void displayBookInfo() const;

    // Method to update the status of the book
    void updateStatus(string newStatus);

    // Getters
    int getBookID() const;
    string getTitle() const;
    string getBookAuthor() const;
    string getGenre() const;
    string getStatus() const;
};

// Function declarations
bool is_book_file_empty(std::ifstream &pFile);
Book createBook();
std::vector<Book> readCSVBooks(const std::string &filename);
void displayMenuBook();
void listBooks(std::vector<Book> bookList);
std::vector<Book> deleteBook(std::vector<Book> bookList);
Book *findBookByID(std::vector<Book> &books, int id);

#endif // BOOK_MANAGER_H
