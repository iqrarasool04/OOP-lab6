#ifndef RECORDS_H
#define RECORDS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
    protected:
        string name;
        int ID;

public:
    Student(const string& studentName, int studentID);
    virtual ~Student();
    virtual double calculateAverageGrade() = 0;
    virtual void displayInformation() = 0;
    int getID() const;
};

class UndergraduateStudent : public Student {
    private:
        double grade1, grade2, grade3;

    public:
        UndergraduateStudent(const string& name, int ID, double g1, double g2, double g3);
        double calculateAverageGrade() override;
        void displayInformation() override;
};

class GraduateStudent : public Student {
    private:
        double researchScore;

    public:
        GraduateStudent(const string& name, int ID, double researchScore);
        double calculateAverageGrade() override;
        void displayInformation() override;
};

class StudentRecordSystem {
    private:
        vector<Student*> students;

    public:
        ~StudentRecordSystem();
        void addStudent(Student* student);
        void removeStudent(int ID);
        Student* findStudentByID(int ID);
};

#endif       
        
        
        
        
        
        
        