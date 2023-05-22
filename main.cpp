#include "course.h"
#include "courses.h"
#include "CourseRegistrationManager.h"
#include "lecturer.h"
#include "student.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Creating the lecturer instances
    Lecturer programmingLecturer("John", "Doe", "john.doe@example.com", "Professor", "University A");
    Lecturer databasesLecturer("Jane", "Smith", "jane.smith@example.com", "Dr.", "University A");
    Lecturer softwareEngineeringLecturer("David", "Brown", "david.brown@example.com", "Ph.D.", "University A");
    
    // Creating the course instances
    Course programmingCourse("Programming", programmingLecturer);
    Course databasesCourse("Databases", databasesLecturer);
    Course softwareEngineeringCourse("Software Engineering", softwareEngineeringLecturer);
    
    // Creating student instances
    Student student1("Alice", "Johnson", "alice.johnson@example.com", 1001, "University A");
    Student student2("Bob", "Smith", "bob.smith@example.com", 1002, "University A");
    Student student3("Charlie", "Brown", "charlie.brown@example.com", 1003, "University A");
    Student student4("David", "Lee", "david.lee@example.com", 1004, "University A");
    Student student5("Emily", "Davis", "emily.davis@example.com", 1005, "University B");
    
    // Registering students to courses
    programmingCourse.addParticipant(student1);
    programmingCourse.addParticipant(student2);
    programmingCourse.addParticipant(student3);
    
    databasesCourse.addParticipant(student2);
    databasesCourse.addParticipant(student4);
    databasesCourse.addParticipant(student5);
    
    softwareEngineeringCourse.addParticipant(student1);
    softwareEngineeringCourse.addParticipant(student2);
    softwareEngineeringCourse.addParticipant(student3);
    softwareEngineeringCourse.addParticipant(student4);
    
    // Create an instance of Courses
    Courses courses;
    
    // Add the courses to the Courses object
    courses.addCourse(programmingCourse);
    courses.addCourse(databasesCourse);
    courses.addCourse(softwareEngineeringCourse);
    
    // Menu
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Registration for a course\n";
        cout << "2. Output of one/all courses with data of the participants\n";
        cout << "3. Output of all courses that are not fully booked yet\n";
        cout << "4. End of program\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                CourseRegistrationManager::registerStudent(courses);
//                string courseName;
//                string surname;
//                string firstName;
//                string email;
//                int matriculationNumber;
//                string university;
//
//                cout << "Enter the course name: ";
//                cin.ignore();
//                getline(cin, courseName);
//
//                cout << "Enter your surname: ";
//                getline(cin, surname);
//
//                cout << "Enter your first name: ";
//                getline(cin, firstName);
//
//                cout << "Enter your email: ";
//                getline(cin, email);
//
//                cout << "Enter your matriculation number: ";
//                cin >> matriculationNumber;
//
//                cout << "Enter your university: ";
//                cin.ignore();
//                getline(cin, university);
//
//                Student student(surname, firstName, email, matriculationNumber, university);
//
//                bool courseFound = false;
//                bool otherUniParticipant = false;
////                int i = 0;
//                for (auto& course : courses.getAllCourses()) {
//                    if (student.getUniversity() != course.getLecturer().getUniversity()) {
//                        for (const auto& participant : course.getParticipants()) {
//                            if (participant.getEmail() == student.getEmail()) {
//                                if (participant.getUniversity() == student.getUniversity()) {
//                                    cout << "Error: Students from other universities can only take one course.\n";
//                                    otherUniParticipant = true;
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                    if (otherUniParticipant){
//                        break;
//                    }
//                }
//                for (auto& course : courses.getAllCourses()) {
//                    if (course.getName() == courseName) {
//                        courseFound = true;
//                        if (!otherUniParticipant) {
//                            if (course.addParticipant(student)) {
//                                cout << "Registration successful!\n";
//                            }
//                        }
//                        break;
//                    }
//                }
//
//
//
//                if (!courseFound) {
//                    cout << "Error: Invalid course name.\n";
//                }
//
                break;
            }
            case 2: {
                cout << "1. Output data for a specific course\n";
                cout << "2. Output data for all courses\n";
                cout << "Enter your choice (1-2): ";
                int subChoice;
                cin >> subChoice;
                
                if (subChoice == 1) {
                    string courseName;
                    cout << "Enter the course name: ";
                    cin.ignore();
                    getline(cin, courseName);
                    
                    bool courseFound = false;
                    for (const auto& course : courses.getAllCourses()) {
                        if (course.getName() == courseName) {
                            courseFound = true;
                            course.printParticipants();
                            break;
                        }
                    }
                    
                    if (!courseFound) {
                        cout << "Error: Invalid course name.\n";
                    }
                } else if (subChoice == 2) {
                    for (const auto& course : courses.getAllCourses()) {
                        course.printCourseDetails();
                        course.printParticipants();
                        cout << endl;
                    }
                } else {
                    cout << "Error: Invalid choice.\n";
                }
                
                break;
            }
            case 3: {
                vector<Course> availableCourses;
                
                for (const auto& course : courses.getAllCourses()) {
                    if (!course.isFullyBooked()) {
                        availableCourses.push_back(course);
                    }
                }
                
                if (availableCourses.empty()) {
                    cout << "All courses are fully booked.\n";
                } else {
                    cout << "Courses not fully booked yet:\n";
                    for (const auto& course : availableCourses) {
                        cout << "- " << course.getName() << " (Lecturer: "
                        << course.getLecturer().getFirstName() << " "
                        << course.getLecturer().getSurname() << ", Academic Title: "
                        << course.getLecturer().getAcademicTitle() << ")\n";
                        unsigned long freePlaces = 10 - course.getParticipants().size();
                        cout << "  Free places: " << freePlaces << "\n";
                    }
                }
                
                break;
            }
            case 4: {
                cout << "Ending the program. Participants to be notified:\n";
                for (const auto& course : courses.getAllCourses()) {
                    if (!course.isFullyBooked()) {
                        cout << "- Participants of the course '" << course.getName() << "'\n";
                        course.printParticipants();
                    }
                }
                break;
            }
            default:
                cout << "Error: Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}
