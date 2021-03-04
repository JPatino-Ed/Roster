#pragma once
#include "student.h"
class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 6;
    
    
public:
    Student* classRosterArray[numStudents];
    
    void parse(string row);
    
    void add(string rStudentID,
             string rFirstName,
             string rLastName,
             string rEmailAddress,
             int rStudentAge,
             double rDaysInCourse1,
             double rDaysInCourse2,
             double rDaysInCourse3,
             DegreeType dt);
    
    
    void printAll();
    void printByDegreeType(DegreeType dt);
    void printInvalidStudentEmailAddress();
    void printAverageDaysInCourse(string studentID);
    void removeStudentByStudentID(string studentID);
    ~Roster();
};

