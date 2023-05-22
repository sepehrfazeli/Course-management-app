#include "person.h"

Person::Person(const std::string& surname, const std::string& firstName, const std::string& email)
    : surname(surname), firstName(firstName), email(email) {
}

std::string Person::getEmail() const {
    return email;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getSurname() const {
    return surname;
}

