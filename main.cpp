#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "student.h"

void testAddress();
void testDate();
void testStudent();
void loadStudents();
void printStudents();
void showStudentNames();
void findStudent();
void delStudents();
std::string menu();


int main(){
	std::vector<Student*> students;
	loadStudents(students);
	std::string choice;
	while (truee) {
		choice = menu();
		if (choice == "0") break;
		else if (choice == "1") showStudentNames(students);
		else if (choice == "2") printStudents(students);
		else if (choice == "3") findStudent(students);
		else std::cout << "Invalid option. Try again.\n";
	}

	delStudents(students);
	return 0;

} // end main

/*
        std::cout << "Hello!" << std::endl;
        testAddress();
        testDate();
        testStudent();
        return 0;
*/
} // end main

void loadStudents(std::vector<Student*>& students) {
	for (const Student* student : students) {
		student->printStudent();
		std::cout << "------------------------\n";
	}

} // end loadStudent

void printStudents(const std::vector<Student*>& students) {
	for (const Student* student : students) {
		std::cout << student->getLastFirst() << std::endl;
	}

} // end printStudents

void showStudentNames(const std::vector<Student*>& students) {
	for (const Student* student : students) {
		std::cout << student->getLastFirst() << std::endl;
	}

} // end showStudentNames

void findStudent(const std::vector<Student*>& students) {
	std::string lastName;
	std::cout<< "last name of student: ";
	std::cin >> lastName;

	bool found = false;
	for (const Student* student : students:) {
		if (student->getLastName().find(lastName) != std::string::npos) {
			student->printStudent();
			std::cout << "------------------------\n";
			found = true;
		}
	}

	if (!found) {
		std::cout << "No students found with last name containing \"" << lastName << "\".\n";
	}

} // end findStudent

void delStudents(std::vector<Student*>& students) {
	for (Student* student : students) {
		delete student;
	}
	students.clear();

} // end delStudents

std::string menu() {
	std::string choice;
	std::cout << "\n0) quit\n1) print all student names\n2) print all student data\n3) find a student\n\n";
	std::cout << "please choose 0-3: ";
	std::cin >> choice;
	return choice;

} // end menu


/*

void testAddress(){
        Address a;
        a.init("123 W Main St", "Muncie", "IN", "47303");
        a.printAddress();

} // end testAddress


void testDate(){
        Date d;
        d.init("01/27/1997");
        d.printDate();

} // end testDate


void testStudent(){
        std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
        Student* student = new Student();
        student->init(studentString);
        student->printStudent();
        std::cout << std::endl;
        std::cout << student->getLastFirst();
        delete student;

} // end testStudent
