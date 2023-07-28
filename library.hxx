#ifndef __LIBRARY_HXX__
#define __LIBRARY_HXX__

#include "vector"
#include "book.hxx"
#include "user.hxx"

class Library {
private:
    std::vector<Book> books;

public:
    Book createBook(
        const std::string &name,
        const std::string &author,
        int year,
        int availableUnits
    );
    void borrowBook(int bookId, const User& user);
    void returnBook(int bookId, const User& user);
    void showAvailableBooks();
    void showBorrowedBooks();


};

#endif