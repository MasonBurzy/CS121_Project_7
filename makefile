classStudent: main.cpp, address.cpp, date.cpp, student.cpp
        g++ -g main.cpp address.cpp date.cpp student.cpp -o studentData

classDate: main.cpp, address.cpp, date.cpp
        g++ -g main.cpp address.cpp date.cpp -o studentData

classAddress: main.cpp, address.cpp
        g++ -g main.cpp address.cpp -o studentData

studentData:  main.cpp
      g++ -g main.cpp -o studentData

run: student
      ./studentData
