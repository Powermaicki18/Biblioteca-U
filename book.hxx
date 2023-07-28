#ifndef __BOOK_HXX__
#define __BOOK_HXX__

#include "vector"
#include "iostream"
#include "user.hxx"

class Book {
private:
    std::string name;
    std::string author;
    int year;
    int availableUnits;
    int id;
    std::vector<User> requesters;

public:
    inline static int idCounter = 0;
    Book(
        const std::string &name,
        const std::string &author,
        int year,
        int availableUnits
    );

    bool isBorrowed();
    bool thereAreAvailableBooks();
    void borrow(const User& user);
    void returnBook(const User& user);
    void showRequesters();
    int getId() const;
    friend std::ostream &operator<<(std::ostream &os, const Book &book);
};

#endif