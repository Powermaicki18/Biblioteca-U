#include "library.hxx"
#include "iostream"


Book Library::createBook(
    const std::string &name,
    const std::string &author,
    int year,
    int availableUnits
) {
    Book newBook = Book(name, author, year, availableUnits);
    this->books.push_back(newBook);
    return newBook;
}

void Library::borrowBook(const int bookId, const User &user) {
    int index = -1;
    for (int i = 0; i < this->books.size(); i++) {
        if (this->books[i].getId() == bookId) {
            index = i;
        }
    }

    if (index != -1) {
        if (this->books[index].thereAreAvailableBooks()) {
            this->books[index].borrow(user);
            return;
        }

        std::cout << "El libro con id " << bookId << " no esta disponible" << std::endl;
        return;
    }

    std::cout << "El libro con id " << bookId << " no existe" << std::endl;
}

void Library::returnBook(const int bookId, const User &user) {
    int index = -1;
    for (int i = 0; i < this->books.size(); i++) {
        if (this->books[i].getId() == bookId) {
            index = i;
        }
    }

    if (index != -1) {
        Book bookToBorrow = this->books[index];

        if (bookToBorrow.isBorrowed()) {
            bookToBorrow.returnBook(user);
            return;
        }

        std::cout << "El libro con id " << bookId << " no esta prestado" << std::endl;
        return;
    }

    std::cout << "El libro con id " << bookId << " no existe" << std::endl;
}

void Library::showAvailableBooks() {
    for (auto & book : this->books) {
        if (book.thereAreAvailableBooks()) {
            std::cout << book << std::endl;
        }
    }
}

void Library::showBorrowedBooks() {
    for (auto & book : this->books) {
        if (book.isBorrowed()) {
            std::cout << book << std::endl;
            std::cout << "Solicitado por:" << std::endl;
            book.showRequesters();
            std::cout << std::endl;
        }
    }
}
