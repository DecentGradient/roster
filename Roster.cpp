//
// Created by Joseph Friedman on 10/28/20.
//

#include "Roster.h"
#include <vector>
#include <iostream>

Roster::Roster() {
    for (auto data:studentData) {
//    std::cout<<data<<std::endl;
        std::vector<std::string> tmp = this->parse(data);    //add
        this->add(tmp);
    }

}

void Roster::add(std::vector<std::string> data) {
//    for (std::string datum: data) {
//        std::cout << datum << std::endl;
//    }
    DegreeProgram program;
    if (data[8].compare("SECURITY")) {
        program = DegreeProgram::SECURITY;
    }
    if (data[8].compare("NETWORK")) {
        program = DegreeProgram::NETWORK;
    }
    if (data[8].compare("SOFTWARE")) {
        program = DegreeProgram::SOFTWARE;
    }
    Student *studentobj = new Student(data[0], data[1], data[2], data[3], data[4], std::stoi(data[5]),
                                      std::stoi(data[6]), std::stoi(data[7]), program);
    this->classRosterArray->push_back(studentobj);

}

std::vector<std::string> Roster::parse(std::string studentRow) {
//    std::cout<<studentRow<<std::endl;

    std::vector<std::string> result;
    int start = 0;
    while (start < studentRow.length()) {
        std::string word;
        int endPos = studentRow.substr(start).find(",");
        word = studentRow.substr(start, endPos);
//        std::cout<<word<<std::endl;
        result.push_back(word);


        start += word.length() + 1;
    }
//    for (std::string word :  result){
//        std::cout<< word<<std::endl;
//    }

    return result;

}

void Roster::remove(std::string studentID) {
    bool removed = false;
    for (int i = 0; i < this->classRosterArray->size(); ++i) {
        if (this->classRosterArray->at(i)->getStudentId().compare(studentID) == 0) {
            this->classRosterArray->erase(this->classRosterArray->begin() + i);
            removed = true;
        }
    }
    if (!removed) {
        std::cout << "Id not found" << std::endl;
    }
}

void Roster::printAll() {
    for (Student *student: *this->classRosterArray) {
        Student tmp = *student;
        tmp.print();
    }
}

int Roster::printAverageDaysInCourse(std::string id) {
    Student student = this->getStudentById(id);
    int *comp = student.getCompletionDays();
    return (comp[0] + comp[1] + comp[2]) / 3;

}

Student Roster::getStudentById(std::string id) {
    for (Student *current : *this->classRosterArray) {
        std::string cid = current->getStudentId();
        if (cid.compare(id) == 0) {
            return *current;
        }

    }
}

void Roster::printInvalidEmails() {
    for (Student *current : *this->classRosterArray) {
        std::string email = current->getEmail();
        std::size_t space = email.find(" ");
        std::size_t at = email.find("@");
        std::size_t period = email.find(".");
        if (space == std::string::npos && at != std::string::npos && period != std::string::npos) {
            continue;
        } else {
            std::cout << email << std::endl;
        }

    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (Student *current : *this->classRosterArray) {
        DegreeProgram currentDp = current->getProgram();
        if (currentDp == degreeProgram) {
            current->print();
        }
    }
}

Roster::~Roster() {
    for (Student *student : *this->classRosterArray) {
        delete[] student;
    }
    delete this->classRosterArray;
    delete[] &this->studentData;
    std::cout << "destroyed" << std::endl;
};