#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include "address.h"
#include "date.h"
#include <string>


class Student {
        protected:
                std::string studentString;
                std::string firstName;
                std::string lastName;
                Date* dob;
                Date* expectedGrad;
                Address* address;
                int creditHours;
        public:
                Student();
                Student(std::string studentString);
                ~Student();

                void init(std::string studentString);
                void printStudent();
                std::string getLastFirst();
                std::string getLastName();

};

#endif
