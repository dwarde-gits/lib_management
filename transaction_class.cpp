#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
// #include "book_class.h"
using namespace std;

// Design a Transaction class to handle borrowing and returning of books. Each transaction should store the transactionID, memberID, bookID, borrowDate, and returnDate.
// Allow the librarian to:
// Borrow a book (update the book’s status and record the transaction).
// Return a book (update the book’s status and calculate any overdue fees).

// class definition of Transaction
class Transaction
{
public:
    int transactionID;
    int memberID;
    int bookID;
    string borrowDate;
    string returnDate;

public:
    // Getter for bookID
    int getTransactionID() const
    {
        return transactionID;
    }
    // Getter for memberID
    int getMemberID() const
    {
        return memberID;
    }
    int getBookID() const
    {
        return bookID;
    }
    string getBorrowDate() const
    {
        return borrowDate;
    }
    string getReturnDate() const
    {
        return returnDate;
    }
};

// Function to read CSV file into vector of Transactions.
std::vector<Transaction> readCSV(const std::string &filename)
{
    std::vector<Transaction> transactionList;
    std::ifstream file(filename);
    std::string line;
    bool header = true; // Skip the header line

    if (!file.is_open())
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return transactionList;
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
        Transaction transaction;

        // Parse each field separated by comma
        std::getline(ss, item, ',');
        transaction.transactionID = std::stoi(item);

        std::getline(ss, item, ',');
        transaction.memberID = std::stoi(item);

        std::getline(ss, item, ',');
        transaction.bookID = std::stoi(item);

        std::getline(ss, item, ',');
        transaction.borrowDate = item;

        std::getline(ss, item, ',');
        transaction.returnDate = item;

        transactionList.push_back(transaction);
    }

    file.close();
    return transactionList;
}
// the librarian can do a borrow transaction.
void borrowBook()
{
    
}
// the librarian can return a book.
void returnBook()
{
}

int main()
{
    vector<Transaction> transactionList2 = readCSV("transactions.csv");
    // vector<Book> bookList2 = readCSV("books.csv");

    return 0;
}
