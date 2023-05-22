#ifndef COURSE_H
#define COURSE_H

#include "lecturer.h"
#include "student.h"
#include <vector>
#include <string>

class Course {
private:
    std::string name;
    Lecturer lecturer;
    std::vector<Student> participants;

public:
    Course(const std::string& name, const Lecturer& lecturer);

    const std::string& getName() const;
    const Lecturer& getLecturer() const;
    const std::vector<Student>& getParticipants() const;

    bool addParticipant(const Student& student) ;
    void printParticipants() const;
    void printCourseDetails() const;
    bool isFullyBooked() const;
};

#endif // COURSE_H
