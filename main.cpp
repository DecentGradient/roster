#include <iostream>
#include "Student.h"
#include "Roster.h"

int main() {
    std::cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS — C867\tc++\t001171996\tJoseph Friedman" << std::endl;
    Roster classRoster;//data loaded in constuctor
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for (Student *current: *classRoster.classRosterArray) {
        std::cout << classRoster.printAverageDaysInCourse(current->getStudentId()) << std::endl;
    }
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    return 0;

}
