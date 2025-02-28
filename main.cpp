#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "student.h"

/*
void testAddress();
void testDate();
void testStudent();
*/

void loadStudents(std::vector<Student*>& students);
void printStudents(const std::vector<Student*>& students);
void showStudentNames(const std::vector<Student*>& students);
void findStudent(const std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();


int main(){
	std::vector<Student*> students;
	loadStudents(students);
	std::string choice;
	while (true) {
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

} // end main
*/


void loadStudents(std::vector<Student*>& students) {
	std::ifstream file("data.csv");
	std::string line;
	while (std::getline(file, line)) {
		students.push_back(new Student(line));
	}

	file.close();

} // end loadStudent

void printStudents(const std::vector<Student*>& students) {
	for (const Student* student : students) {
		student->printStudent();
		std::cout << "------------------------\n";
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
	for (const Student* student : students) {
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

