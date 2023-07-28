#include "book.hxx"

Book::Book(const std::string &name, const std::string &author, int year, int availableUnits) {
    this->name = name;
    this->author = author;
    this->year = year;
    this->availableUnits = availableUnits;
    this->id = Book::idCounter++;
}

bool Book::isBorrowed() {
    return this->requesters.size() > 0;
}

bool Book::thereAreAvailableBooks() {
    return this->availableUnits - this->requesters.size() > 0;
}

void Book::borrow(const User &user) {
    this->requesters.push_back(user);
}

void Book::returnBook(const User &user) {
    int index = -1;
    for (int i = 0; i < this->requesters.size(); i++) {
        if (this->requesters[i].getId() == user.getId()) {
            index = i;
        }
    }

    if (index != -1) {
        this->requesters.erase(this->requesters.begin()+index);

        return;
    }

    std::cout << "El usuario con id " << user.getId() << " no ha solicitado este libro" << std::endl;
}

int Book::getId() const {
    return id;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os <<  book.id << " - " << book.name << " (" << book.author << ", " << book.year << ") [" << book.requesters.size() << "/"<< book.availableUnits << "]";
    return os;
}

void Book::showRequesters() {
    for (auto & user : this->requesters) {
        std::cout << user << std::endl;
    }
}

