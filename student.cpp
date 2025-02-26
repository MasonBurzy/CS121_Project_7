#include "student.h"
#include <iostream>
#include <sstream>

Student::Student() {
    firstName = "";
    lastName = "";
    dob = new Date();
    expectedGrad = new Date();
    address = new Address();
    creditHours = 0;
}

Student::Student(std::string studentString) {
    dob = new Date();
    expectedGrad = new Date();
    address = new Address();
    init(studentString);
}

Student::~Student() {
    delete dob;
    delete expectedGrad;
    delete address;
}

void Student::init(std::string studentString) {
    std::stringstream ss(studentString);
    std::string first, last, street, city, state, zip, birth, grad;
    int credits;

    std::getline(ss, first, ',');
    std::getline(ss, last, ',');
    std::getline(ss, street, ',');
    std::getline(ss, city, ',');
    std::getline(ss, state, ',');
    std::getline(ss, zip, ',');
    std::getline(ss, birth, ',');
    std::getline(ss, grad, ',');
    ss >> credits;

    firstName = first;
    lastName = last;
    dob->init(birth);
    expectedGrad->init(grad);
    address->init(street, city, state, zip);
    creditHours = credits;
}

void Student::printStudent() {
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();
    std::cout << "DOB: ";
    dob->printDate();
    std::cout << "Grad: ";
    expectedGrad->printDate();
    std::cout << "Credits: " << creditHours << std::endl;
}

std::string Student::getLastFirst() {
    return lastName + ", " + firstName;
}

std::string Student::getLastName() {
    return lastName;
}
