#include "course.h"
#include <iostream>
using namespace std;

Course::Course(const string& name, const Lecturer& lecturer)
    : name(name), lecturer(lecturer) {
}

const string& Course::getName() const {
    return name;
}

const Lecturer& Course::getLecturer() const {
    return lecturer;
}

const vector<Student>& Course::getParticipants() const {
    return participants;
}

bool Course::addParticipant(const Student& student) {
    for (const auto& participant : participants) {
        if (participant.getEmail() == student.getEmail()) {
            cout << "Error: Student with the same email is already registered in this course.\n";
            return false;
        }
    }

    if (participants.size() >= 10) {
        cout << "Error: Maximum number of participants reached for this course.\n";
        return false;
    }

    participants.push_back(student);
    return true;
}

void Course::printParticipants() const {
    cout << "Participants of the course '" << name << "':\n";
    for (const auto& participant : participants) {
        cout << "- " << participant.getFirstName() << " " << participant.getSurname()
            << " (Email: " << participant.getEmail() << ")\n";
    }
}

void Course::printCourseDetails() const {
    cout << "Course Name: " << name << "\n";
    cout << "Lecturer: " << lecturer.getFirstName() << " " << lecturer.getSurname()
        << " (Academic Title: " << lecturer.getAcademicTitle() << ")\n";
}

bool Course::isFullyBooked() const {
    return participants.size() == 10;
}
