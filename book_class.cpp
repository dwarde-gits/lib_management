#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
// #include "book_class.h"
using namespace std;

// class definition of Book
class Book
{
public:
    int bookID;
    string title;
    string author;
    string genre;
    string status;

public:
    // Method to display book details
    void displayBookInfo()
    {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Status: " << status << endl;
        cout << "-------------------------" << endl;
    }

    // Method to update the status of the book
    void updateStatus(string newStatus)
    {
        status = newStatus;
        cout << "Status updated to: " << status << endl;
    }

    // Getter for bookID
    int getBookID() const
    {
        return bookID;
    }
    // const means that the function isn't modifying variables
    string getTitle() const
    {
        return title;
    }
    string getBookAuthor() const
    {
        return author;
    }
    string getGenre() const
    {
        return genre;
    }

    // Getter for status
    string getStatus() const
    {
        return status;
    }
};
// function to check if a file is empty.
bool is_file_empty(std::ifstream &pFile)
{
    if (pFile.tellg() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// create and return a new book object
Book createBook()
{
    int bookID = 0;
    string bookTitle = "";
    string bookAuthor = "";
    string bookGenre = "";
    string bookStatus = "";

    std::cout << "\n==== Add New Book Menu ====\n";
    std::cout << "1. enter book id: ";
    std::cin >> bookID;
    std::cin.ignore();

    std::cout << "2. enter book title: ";
    std::cin >> bookTitle;
    std::cin.ignore(); // Clear newline from input buffer

    std::cout << "3. enter book author: ";
    std::cin >> bookAuthor;
    std::cin.ignore();

    std::cout << "4. enter book genre: ";
    std::cin >> bookGenre;
    std::cin.ignore();

    std::cout << "5. enter book status: ";
    std::cin >> bookStatus;
    std::cin.ignore();

    Book book;
    book.bookID = bookID;
    book.title = bookTitle;
    book.author = bookAuthor;
    book.genre = bookGenre;
    book.status = bookStatus;
    return book;
}

// Function to read CSV file into vector of Books.
std::vector<Book> readCSV(const std::string &filename)
{
    std::vector<Book> bookList;
    std::ifstream file(filename);
    std::string line;
    bool header = true; // Skip the header line

    if (!file.is_open())
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return bookList;
    }

    while (std::getline(file, line))
    {
        // Skip the header line. first line is the header line.
        if (header)
        {
            header = false;
            continue;
        }

        std::stringstream ss(line);
        std::string item;
        Book book;

        // Parse each field separated by comma
        std::getline(ss, item, ',');
        book.bookID = std::stoi(item);

        std::getline(ss, item, ',');
        book.title = item;

        std::getline(ss, item, ',');
        book.author = item;

        std::getline(ss, item, ',');
        book.genre = item;
        std::getline(ss, item, ',');
        book.status = item;

        bookList.push_back(book);
    }

    file.close();
    return bookList;
}

// Function to display the main menu
void displayMenu()
{
    std::cout << "\n==== Library Menu ====\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. List Books\n";
    std::cout << "3. Delete Book\n";
    std::cout << "4. Edit Book\n";
    std::cout << "5. Exit\n";
    std::cout << "Select an option: ";
}

void listBooks(vector<Book> bookList)
{
    if (bookList.empty())
    {
        std::cout << "No books available.\n";
        return;
    }

    std::cout << "\nList of Books:\n";
    for (const auto &book : bookList)
    {
        std::cout << "bookID: " << std::to_string(book.getBookID())
                  << ", Title: " << book.getTitle()
                  << ", Author: " << book.getBookAuthor()
                  << ", genre: " << book.getGenre()
                  << ", Status: " << book.getStatus()
                  << "\n";
    }
}
// Function to delete a book
vector<Book> deleteBook(vector<Book> bookList)
{
    int id;
    std::cout << "Enter book ID to delete: ";
    std::cin >> id;
    std::cin.ignore(); // Clear newline from input buffer

    auto it = std::remove_if(bookList.begin(), bookList.end(), [id](const Book &book)
                             { return book.getBookID() == id; });

    if (it != bookList.end())
    {
        bookList.erase(it, bookList.end());
        std::cout << "Book deleted successfully!\n";
    }
    else
    {
        std::cout << "Book with ID " << id << " not found.\n";
    }
    return bookList;
}
// function to search for a specific book.
Book *findBookByID(std::vector<Book> &books, int id)
{
    auto it = std::find_if(books.begin(), books.end(), [id](Book &b)
                           { return b.getBookID() == id; });

    // If the book is found, return a pointer to it
    if (it != books.end())
    {
        return &(*it);
    }
    return nullptr; // Book not found
}

int main()
{

    vector<Book> bookList2 = readCSV("books.csv");
    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        switch (choice)
        {
        case 1:
            // using extra braces since the the book object is created here.
            // because https://stackoverflow.com/questions/5136295/switch-transfer-of-control-bypasses-initialization-of-when-calling-a-function
            {

                Book book = createBook();
                bookList2.push_back(book);
            }
            break;
        case 2:
            listBooks(bookList2);
            break;
        case 3:
            // new booklist after a deletion is done.
            bookList2 = deleteBook(bookList2);
            break;
        case 4:
        {
            // modify/edit a book.
            int id;
            int bookID;
            string bookTitle;
            string bookAuthor;
            string bookGenre;
            string bookStatus;

            std::cout << "Enter book ID to edit: ";
            std::cin >> id;
            std::cin.ignore(); // Clear newline from input buffer
            Book *bookToModify = findBookByID(bookList2, id);
            if (bookToModify)
            {
                std::cout << "Modifying book with ID: " << bookToModify->getBookID() << "\n";
                // Modify book details
                // std::cout << "1. enter new book id: ";
                // std::cin >> bookID;
                // std::cin.ignore();

                std::cout << "2. enter new book title (enter to keep as is): ";
                std::cin >> bookTitle;
                std::cin.ignore(); // Clear newline from input buffer
                if (!bookTitle.empty())
                {
                    bookToModify->title = bookTitle;
                }

                std::cout << "3. enter new book author (enter to keep as is ): ";
                std::cin >> bookAuthor;
                std::cin.ignore();

                std::cout << "4. enter new book genre (enter to keep as is ): ";
                std::cin >> bookGenre;
                std::cin.ignore();

                std::cout << "5. enter new book status (enter to keep as is ): ";
                std::cin >> bookStatus;
                std::cin.ignore();

                //     book.status = bookStatus;

                if (!bookAuthor.empty())
                {
                    bookToModify->author = bookAuthor;
                }
                if (!bookGenre.empty())
                {
                    bookToModify->genre = bookGenre;
                }
                if (!bookStatus.empty())
                {
                    bookToModify->status = bookStatus;
                }
            }
            else
            {
                std::cout << "Book with ID " << id << " not found.\n";
            }
        }
        break;
        case 5:
            // before existing. write the records to file.
            // if the file was previously empty will need to write header first,
            // otherwise just proceed to write actual record content.
            {
                std::ofstream myfile;
                std::ifstream file("books.csv");
                myfile.open("books.csv");
                bool header_set = false;
                for (const auto &book : bookList2)
                {
                    std::cout << "ID: " << std::to_string(book.getBookID())
                              << ", Title: " << book.getTitle()
                              << ", Author: " << book.getBookAuthor() << "\n";

                    string record1 = std::to_string(book.getBookID()) + "," +
                                     book.getTitle() + "," +
                                     book.getBookAuthor() + "," +
                                     book.getGenre() + "," +
                                     book.getStatus() + "\n";
                    if (is_file_empty(file) && header_set == false)
                    {
                        // the header only needs to be written once.
                        myfile << "BookID, title, author, genre, status\n";
                        header_set = true;
                    }
                    myfile << record1;
                }
                myfile.close();
                file.close();
                std::cout << "Exiting...\n";
            }
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
