#include "CourseRegistrationManager.h"
#include <iostream>

void CourseRegistrationManager::registerStudent(Courses& courses) {
    std::string courseName;
    std::string surname;
    std::string firstName;
    std::string email;
    int matriculationNumber;
    std::string university;

    std::cout << "Enter the course name: ";
    std::cin.ignore();
    std::getline(std::cin, courseName);

    std::cout << "Enter your surname: ";
    std::getline(std::cin, surname);

    std::cout << "Enter your first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter your email: ";
    std::getline(std::cin, email);

    std::cout << "Enter your matriculation number: ";
    std::cin >> matriculationNumber;

    std::cout << "Enter your university: ";
    std::cin.ignore();
    std::getline(std::cin, university);

    Student student(surname, firstName, email, matriculationNumber, university);

    bool courseFound = false;
    bool otherUniParticipant = false;

    for (const auto& course : courses.getAllCourses()) {
        if (university != course.getLecturer().getUniversity()) {
            for (const auto& participant : course.getParticipants()) {
                if (participant.getEmail() == email) {
                    if (participant.getUniversity() == university) {
                        std::cout << "Error: Students from other universities can only take one course.\n";
                        otherUniParticipant = true;
                        break;
                    }
                }
            }
        }
        if (otherUniParticipant) {
            break;
        }
    }

    for (auto& course : courses.getAllCourses()) {
        if (course.getName() == courseName) {
            courseFound = true;
            if (!otherUniParticipant) {
                if (!checkExistingParticipant(student, course)) {
                    if (course.addParticipant(student)) {
                        std::cout << "Registration successful!\n";
                    }
                } else {
                    std::cout << "Error: Student already registered in the course.\n";
                }
            }
            break;
        }
    }

    if (!courseFound) {
        std::cout << "Error: Invalid course name.\n";
    }
}

bool CourseRegistrationManager::checkExistingParticipant(const Student& student, const Course& course) {
    for (const auto& participant : course.getParticipants()) {
        if (participant.getEmail() == student.getEmail() &&
            participant.getUniversity() == student.getUniversity()) {
            return true;
        }
    }
    return false;
}
