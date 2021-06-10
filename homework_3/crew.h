/**
 * Name: crew.h
 * Purpose: declaration of class Crew - based on class Person, used in class Plane
 * @author Mateusz Bronislaw Wasilewski
**/


#pragma once
#include "person.h"

// represents the crew member
// ingerits from class Person
class Crew: public Person
{
private:
    // represents the position of the crew member
    std::string position;
public:
    // construtor for class Crew instance
    Crew(
        std::string person_id,
        std::string first_name,
        std::string last_name,
        std::string position
    );

    // setter for position attribute
    void set_position(std::string new_position);
    // getter fot position attribute
    std::string get_position();

    friend std::ostream& operator<< (std::ostream &os, Crew &c);
};