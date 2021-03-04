#include "student.h"
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = 0;
    for ( int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
    this->degreeType = DegreeType::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, double daysInCourse[], DegreeType degreeType)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    for ( int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeType = degreeType;
}

Student::~Student() {}

string Student::getStudentID() { return this-> studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getStudentAge() { return this->studentAge; }
double* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeType Student::getDegreeType() { return this->degreeType; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setStudentAge(int studentAge) { this->studentAge = studentAge; }
void Student::setDaysInCourse(double daysInCourse[])
{
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeType(DegreeType dt) { this->degreeType = dt;}

void Student::printHeader()
{
    cout << "Output format: StudentID|FirstName|LastName|EmailAddress|StudentAge|DaysInCourse|DegreeType\n";
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getStudentAge() << '\t';
    cout << this->getDaysInCourse()[0] << ',';
    cout << this->getDaysInCourse()[1] << ',';
    cout << this->getDaysInCourse()[2]<< ',';
    cout << degreeTypeString[this->getDegreeType()] << '\n';
    
}

