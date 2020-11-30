//
// Created by Joseph Friedman on 10/28/20.
//

#ifndef WGU_ROSTER_H
#define WGU_ROSTER_H

#include <string>
#include <vector>
#include "Student.h"
class Roster {
    const std::string studentData[5] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Joseph,Friedman,jfri31@roster.edu,36,22,21,23,SOFTWARE"
    };



    std::vector<std::string> parse(std::string studentRow);

public:
    Roster();
    ~Roster();

    void add(std::vector<std::string> data);
     std::vector<Student *> *classRosterArray = new std::vector<Student *>();

    void remove(std::string studentID);

    void printAll();

    int printAverageDaysInCourse(std::string id);

    Student getStudentById(std::string id);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);
};


#endif //WGU_ROSTER_H
