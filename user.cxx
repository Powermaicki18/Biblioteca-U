#include "user.hxx"

User::User(const std::string &name, const std::string &id) {
    this->name = name;
    this->id = id;
}

const std::string &User::getId() const {
    return id;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << user.name << " - " << user.id;
    return os;
}
