//
// Created by Joseph Friedman on 10/27/20.
//

#include <string>
#include "degree.h"

#ifndef WGU_STUDENT_H
#define WGU_STUDENT_H


class Student {
public:
    Student();

//    Student(std::string studentId, const std::string firstName, const std::string lastName,
//            const std::string email, const std::string age, int *completionDays, std::string program);

    Student(const std::string studentId, const std::string firstName, const std::string lastName,
            const std::string email, const std::string age, int comp1, int comp2, int comp3, DegreeProgram program);

    std::string getStudentId() ;

    void setStudentId(const std::string &studentId);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    const std::string &getAge() const;

    void setAge(const std::string &age);

    DegreeProgram getProgram() const;

    void setProgram(DegreeProgram program);


    void print();

public:
    int * getCompletionDays();

private:
    std::string studentID;

private:
    std::string firstName;

private:
    std::string lastName;

private:
    std::string email;

private:
    std::string age;


private:
    DegreeProgram program;
private:
    int completionDays[3]{};

    std::string printCompletion();

};


#endif //WGU_STUDENT_H
