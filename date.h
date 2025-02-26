#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <iostream>
#include <string>

class Date {
        protected:
                int month;
                int day;
                int year;
        public:
                Date();
                void init(std::string dateString);
                void printDate();


};

#endif
