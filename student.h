#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <string>

class Student : public Person {
private:
    int matriculationNumber;
    std::string university;

public:
    Student(const std::string& surname, const std::string& firstName, const std::string& email,
            int matriculationNumber, const std::string& university)
        : Person(surname, firstName, email), matriculationNumber(matriculationNumber), university(university) {}

    std::string getUniversity() const;
};

#endif // STUDENT_H
