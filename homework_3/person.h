/**
 * Name: passenger.h
 * Purpose: declaration of class Person - used as a basis for classess Crew and Passenger
 * @author Mateusz Bronislaw Wasilewski
**/


#pragma once
#include <string>

// class created to simplify classes Crew and Passenger
class Person
{
protected:
    // represents person id number
    std::string person_id;
    // represents first name
    std::string first_name;
    // represents last name
    std::string last_name;
public:
    // constructor for class Person instance
    Person(std::string person_id,
        std::string first_name,
        std::string last_name
    );

    // setter for person_id attribute
    void set_person_id(std::string new_id);
    // getter for person_id attribute
    std::string get_person_id();

    // setter for first_name attribute
    void set_first_name(std::string new_fname);
    // getter for first_name attribute
    std::string get_first_name();

    // setter for last_name attribute
    void set_last_name(std::string new_lname);
    // getter for last_name attribute
    std::string get_last_name();
};
