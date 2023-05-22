#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string surname;
    std::string firstName;
    std::string email;

public:
    Person(const std::string& surname, const std::string& firstName, const std::string& email);
    
    std::string getEmail() const;

    std::string getFirstName() const;

    std::string getSurname() const;
};

#endif // PERSON_H
