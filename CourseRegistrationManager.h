#ifndef COURSEREGISTRATIONMANAGER_H
#define COURSEREGISTRATIONMANAGER_H

#include "courses.h"

class CourseRegistrationManager {
public:
    static void registerStudent(Courses& courses);

private:
    static bool checkExistingParticipant(const Student& student, const Course& course);
};

#endif  // COURSEREGISTRATIONMANAGER_H
