//
// Created by Joseph Friedman on 10/27/20.
//
#include <iostream>
#include "Student.h"


Student::Student(const std::string studentId, const std::string firstName, const std::string lastName,
                 const std::string email, const std::string age, int comp1,int comp2 , int comp3, DegreeProgram program) {
    this->studentID = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->completionDays[0] = comp1 ;
    this->completionDays[1] = comp2 ;
    this->completionDays[2] = comp3 ;
    this->program = program;



}

std::string Student::getStudentId() {
    return this->studentID;
}

void Student::setStudentId(const std::string &studentId) {
    studentID = studentId;
}

const std::string &Student::getFirstName() const {
    return firstName;
}

void Student::setFirstName(const std::string &firstName) {
    Student::firstName = firstName;
}

const std::string &Student::getLastName() const {
    return lastName;
}

void Student::setLastName(const std::string &lastName) {
    Student::lastName = lastName;
}

const std::string &Student::getEmail() const {
    return email;
}

void Student::setEmail(const std::string &email) {
    Student::email = email;
}

const std::string &Student::getAge() const {
    return age;
}

void Student::setAge(const std::string &age) {
    Student::age = age;
}



int * Student::getCompletionDays() {
    return completionDays;
}

DegreeProgram Student::getProgram() const {
    return program;
}

void Student::setProgram(DegreeProgram program) {
    Student::program = program;
}
std::string programNames[] {"SECURITY","NETWORK","SOFTWARE"};

void Student::print() {
    std::cout << this->studentID + "\t First Name: " + this->firstName + "\t Last Name: " + this->lastName + "\t Age: " + this->age +
            "\t" + this->printCompletion() +"\t Degree Program: "+ programNames[static_cast<int>(DegreeProgram(this->program))] << std::endl;

}

std::string Student::printCompletion() {
    std::string tmp = "daysInCourse: {";
    for (size_t i = 0; i < 3; i++) {
        tmp+= std::to_string(this->completionDays[i]);
        if(i<2){
            tmp+=", ";
        }else{
            tmp+="}";
        }
    }
    return tmp;
}



