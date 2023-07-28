#ifndef __USER_HXX__
#define __USER_HXX__

#include "iostream"

class User {
private:
    std::string name;
    std::string id;

public:
    User(const std::string& name, const std::string& id);

    const std::string &getId() const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);
};

#endif