#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "records.h"
using namespace std;

int main() {
    StudentRecordSystem recordSystem;
    char choice;

    do {
        cout << "Menu:" <<endl;
        cout << "a) Add a new student" <<endl;
        cout << "b) Remove a student" <<endl;
        cout << "c) Display student information" <<endl;
        cout << "d) Calculate average grade" <<endl;
        cout << "e) Exit" <<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                string name;
                int ID;
                char studentType;

                cout << "Enter student name: ";
                cin.ignore();
                getline(std::cin, name);

                cout << "Enter student ID: ";
                cin >> ID;

                cout << "Enter student type (u for Undergraduate, g for Graduate): ";
                cin >> studentType;
                cin.ignore(); 
                
                if (studentType == 'u') {
                    double grade1, grade2, grade3;
                    cout << "Enter three grades: ";
                    cin >> grade1 >> grade2 >> grade3;

                    Student* newStudent = new UndergraduateStudent(name, ID, grade1, grade2, grade3);
                    recordSystem.addStudent(newStudent);
                } else if (studentType == 'g') {
                    double researchScore;
                    cout << "Enter research score: ";
                    cin >> researchScore;

                    Student* newStudent = new GraduateStudent(name, ID, researchScore);
                    recordSystem.addStudent(newStudent);
                } else {
                    cout << "Invalid student type!" <<endl;
                }

                break;
            }
            case 'b': {
                int ID;
                cout << "Enter student ID to remove: ";
                cin >> ID;
                recordSystem.removeStudent(ID);
                break;
            }
            case 'c': {
                int ID;
                cout << "Enter student ID to display information: ";
                cin >> ID;
                Student* student = recordSystem.findStudentByID(ID);
                if (student) {
                    student->displayInformation();
                } else {
                    cout << "Student not found!" <<endl;
                }
                break;
            }
            case 'd': {
                int ID;
                cout << "Enter student ID to calculate average grade: ";
                cin >> ID;
                Student* student = recordSystem.findStudentByID(ID);
                if (student) {
                    cout << "Average Grade: " << student->calculateAverageGrade() <<endl;
                } else {
                    cout << "Student not found!" <<endl;
                }
                break;
            }
            case 'e':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

        cout << endl;
    } while (choice != 'e');

    return 0;
}
