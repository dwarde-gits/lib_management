#include "book_manager.h"

// Method definitions for Book class
void Book::displayBookInfo() const
{
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Status: " << status << endl;
    cout << "-------------------------" << endl;
}

void Book::updateStatus(string newStatus)
{
    status = newStatus;
    cout << "Status updated to: " << status << endl;
}

int Book::getBookID() const
{
    return bookID;
}

string Book::getTitle() const
{
    return title;
}

string Book::getBookAuthor() const
{
    return author;
}

string Book::getGenre() const
{
    return genre;
}

string Book::getStatus() const
{
    return status;
}

// Function definitions
bool is_book_file_empty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

Book createBook()
{
    int bookID;
    string bookTitle, bookAuthor, bookGenre, bookStatus;

    cout << "\n==== Add New Book Menu ====\n";
    cout << "1. Enter book ID: ";
    cin >> bookID;
    cin.ignore();

    cout << "2. Enter book title: ";
    getline(cin, bookTitle);

    cout << "3. Enter book author: ";
    getline(cin, bookAuthor);

    cout << "4. Enter book genre: ";
    getline(cin, bookGenre);

    cout << "5. Enter book status: ";
    getline(cin, bookStatus);

    Book book{bookID, bookTitle, bookAuthor, bookGenre, bookStatus};
    return book;
}

std::vector<Book> readCSVBooks(const std::string &filename)
{
    std::vector<Book> bookList;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        cerr << "Could not open file: " << filename << endl;
        return bookList;
    }

    bool header = true;
    while (getline(file, line))
    {
        if (header)
        {
            header = false;
            continue;
        }

        std::stringstream ss(line);
        std::string item;
        Book book;

        getline(ss, item, ',');
        book.bookID = stoi(item);

        getline(ss, item, ',');
        book.title = item;

        getline(ss, item, ',');
        book.author = item;

        getline(ss, item, ',');
        book.genre = item;

        getline(ss, item, ',');
        book.status = item;

        bookList.push_back(book);
    }

    file.close();
    return bookList;
}

void displayMenuBook()
{
    cout << "\n==== Library Menu ====\n";
    cout << "1. Add Book\n";
    cout << "2. List Books\n";
    cout << "3. Delete Book\n";
    cout << "4. Edit Book\n";
    cout << "5. Exit\n";
    cout << "Select an option: ";
}

void listBooks(std::vector<Book> bookList)
{
    if (bookList.empty())
    {
        cout << "No books available.\n";
        return;
    }

    cout << "\nList of Books:\n";
    for (const auto &book : bookList)
    {
        book.displayBookInfo();
    }
}

std::vector<Book> deleteBook(std::vector<Book> bookList)
{
    int id;
    cout << "Enter book ID to delete: ";
    cin >> id;
    cin.ignore();

    auto it = std::remove_if(bookList.begin(), bookList.end(),
                             [id](const Book &book)
                             { return book.getBookID() == id; });

    if (it != bookList.end())
    {
        bookList.erase(it, bookList.end());
        cout << "Book deleted successfully!\n";
    }
    else
    {
        cout << "Book with ID " << id << " not found.\n";
    }
    return bookList;
}

Book *findBookByID(std::vector<Book> &books, int id)
{
    auto it = std::find_if(books.begin(), books.end(),
                           [id](Book &b)
                           { return b.getBookID() == id; });

    return it != books.end() ? &(*it) : nullptr;
}
