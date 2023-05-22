#ifndef COURSES_H
#define COURSES_H

#include "course.h"
#include <vector>

class Courses {
private:
    std::vector<Course> courses;

public:
    void addCourse(const Course& course);
    std::vector<Course>& getAllCourses() ;
};

#endif // COURSES_H
