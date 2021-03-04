#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student
{
public:
    const static int daysInCourseArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    double daysInCourse[daysInCourseArraySize];
    DegreeType degreeType;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAdress, int studentAge, double daysInCourse[], DegreeType degreeType);
    ~Student();
    
    
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge();
    double* getDaysInCourse();
    DegreeType getDegreeType();
    
    void setStudentID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAdress);
    void setStudentAge(int studentAge);
    void setDaysInCourse(double daysInCourse[]);
    void setDegreeType(DegreeType dt);
    
    static void printHeader();
    
    void print();
    
};


