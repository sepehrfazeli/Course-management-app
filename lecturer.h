#ifndef LECTURER_H
#define LECTURER_H

#include "person.h"
#include <string>

class Lecturer : public Person {
private:
    std::string academicTitle;
    std::string university;

public:
    Lecturer(const std::string& surname, const std::string& firstName, const std::string& email,
             const std::string& academicTitle,const std::string& university);
    
    std::string getAcademicTitle() const;
    std::string getUniversity() const;
    
};

#endif // LECTURER_H

