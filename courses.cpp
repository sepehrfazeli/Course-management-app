#include "courses.h"
using namespace std;

void Courses::addCourse(const Course& course) {
    courses.push_back(course);
}

vector<Course>& Courses::getAllCourses()  {
    return courses;
}
