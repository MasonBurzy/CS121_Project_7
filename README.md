# CS121-Project-7

## Algorithm



# Address.h
```
null parameter
private/protected(#)
        # string street
        # string city
        # string state
        # string zip
public:
        print Address
                Address()
                void init("street, city, state, zip")
                void print address
```


# Date.h
```
private/protected(#)
        # string dateString (mm/dd/yyyy)
        # int month
        # int day
        # int year
public:
        print Date
                Date()
                void init(dateString)
                        need algorithm for dataString going into init
                        and for "1" - January, "2" - February
                void printDate()
```

# Student.h
```
private/protected(#)
        # string studentString
        # string firstName
        # string lastName
        # Date* dob
        # Date* expectedgrad
        # Address* Adress
        # int creditHours
public:
        Student()
        -Student (destructor)
        void init(studentString)
                seperate string by commas to have a bunch of strings
        void printStudent()
        string getLastFirst()

```

#main.cpp
```
delete testAddress, testDate, and testStudent


```
