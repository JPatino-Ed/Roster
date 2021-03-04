#include "roster.h"
void Roster::parse(string studentdata)
{
    DegreeType dt = SECURITY;
    if (studentdata.back() == 'K') dt = NETWORK;
    else if (studentdata.back() == 'E') dt = SOFTWARE;
    
    int rhs = studentdata.find(",");
    string rStudentID = studentdata.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string rFirstName = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string rLastName = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string rEmailAddress = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int rStudentAge = stod(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    double rDaysInCourse1 = stod(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    double rDaysInCourse2 = stod(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    double rDaysInCourse3 = stod(studentdata.substr(lhs, rhs - lhs));
    
    add(rStudentID, rFirstName, rLastName, rEmailAddress, rStudentAge, rDaysInCourse1, rDaysInCourse2, rDaysInCourse3, dt);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeType dt)
{
    double parr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, studentAge, parr, dt);
}


void Roster::printAll()
{
    Student::printHeader();
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        classRosterArray[i]->print(); 
        /*cout << classRosterArray[i]->getStudentID(); cout << '\t';
        cout << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << classRosterArray[i]->getLastName(); cout << '\t';
        cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
        cout << classRosterArray[i]->getStudentAge(); cout << '\t';
        cout << classRosterArray[i]->getDaysInCourse()[0]; cout << '\t';
        cout << classRosterArray[i]->getDaysInCourse()[1]; cout << '\t';
        cout << classRosterArray[i]->getDaysInCourse()[2]; cout << '\t';
        cout << degreeTypeString[classRosterArray[i]->getDegreeType()] << std::endl;*/
    }
}


void Roster::printByDegreeType(DegreeType dt)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeType() == dt) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidStudentEmailAddress()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string rStudentEmailAddress = (classRosterArray[i]->getEmailAddress());
        if (rStudentEmailAddress.find(' ') == string::npos || (rStudentEmailAddress.find('@') == string::npos && rStudentEmailAddress.find('.') == string::npos))
        {
            any = true;
            cout << rStudentEmailAddress << ": " << classRosterArray[i]->getFirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if ( classRosterArray[i]->getStudentID() == studentID) {
            cout << classRosterArray[i]->getStudentID() << ": ";
            cout << (classRosterArray[i]->getDaysInCourse()[0] +
                 classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2])/3.0 << std::endl;
        }
    }
    cout << std::endl;
}

void Roster::removeStudentByStudentID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            success = true;
            if (i < numStudents - 1 )
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " removed from repository." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
    cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
