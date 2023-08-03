#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "records.h"
using namespace std;

Student::Student(const string& studentName, int studentID){
    name = studentName; 
    ID = studentID;
}
Student::~Student() {}
int Student::getID() const{ 
    return ID; 
}

UndergraduateStudent::UndergraduateStudent(const string& name, int ID, double g1, double g2, double g3): Student(name, ID){
    grade1 = g1;
    grade2 = g2;
    grade3 = g3;
}
double UndergraduateStudent::calculateAverageGrade() {
    return (grade1 + grade2 + grade3) / 3.0;
}
void UndergraduateStudent::displayInformation() {
    cout << "Undergraduate Student Information" <<endl;
    cout << "Name: " << name <<endl;
    cout << "ID: " << ID <<endl;
    cout << "Grades: " << grade1 << ", " << grade2 << ", " << grade3 <<endl;
    cout << "Average Grade: " << calculateAverageGrade() <<endl;
}

GraduateStudent::GraduateStudent(const string& name, int ID, double researchScore): Student(name, ID){
    researchScore = researchScore;
}

double GraduateStudent::calculateAverageGrade() {
    // Graduate students do not have grades, so we return their research score as "average grade"
    return researchScore;
}

void GraduateStudent::displayInformation() {
    cout << "Graduate Student Information" <<endl;
    cout << "Name: " << name <<endl;
    cout << "ID: " << ID <<endl;
    cout << "Research Score: " << researchScore <<endl;
}

StudentRecordSystem::~StudentRecordSystem() {
    // Clean up memory for student objects
    for (Student* student : students) {
        delete student;
    }
}

void StudentRecordSystem::addStudent(Student* student) {
    students.push_back(student);
}

void StudentRecordSystem::removeStudent(int ID) {
    auto it = std::find_if(students.begin(), students.end(), [ID](Student* student) {
        return student->getID() == ID;
    });

    if (it != students.end()) {
        delete *it;
        students.erase(it);
    }
}

Student* StudentRecordSystem::findStudentByID(int ID) {
    auto it = std::find_if(students.begin(), students.end(), [ID](Student* student) {
        return student->getID() == ID;
    });

    return (it != students.end()) ? *it : nullptr;
}
