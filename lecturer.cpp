#include "lecturer.h"

Lecturer::Lecturer(const std::string& surname, const std::string& firstName, const std::string& email,
                   const std::string& academicTitle, const std::string& university)
    : Person(surname, firstName, email), academicTitle(academicTitle), university(university) {
}

std::string Lecturer::getAcademicTitle() const {
    return academicTitle;
}
std::string Lecturer::getUniversity() const {
    return university;
}
