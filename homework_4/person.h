/**
 * Name: person.cpp
 * Purpose: declaration of class Person
 * @author Mateusz Bronislaw Wasilewski
**/

#pragma once
#include <string>

class Person
{
private:
    int id;
    int age;
    std::string first_name;
    std::string last_name;
public:
    // constructor
    Person(int id_num=1, int age_val=20, std::string fname="FNAME", std::string lname="LNAME");

    // getter for id
    int get_id();
    // getter for age
    int get_age();
    // getter for first_name
    std::string get_first_name();
    // getter for last_name
    std::string get_last_name();

    // overloaded operator<<
    friend std::ostream& operator<< (std::ostream &os, Person &p);
    // overloaded operator==
    bool operator==(Person &p);
    // overloaded operator!=
    bool operator!=(Person &p);
};