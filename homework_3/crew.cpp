/**
 * Name: crew.cpp
 * Purpose: implementation of class Crew - based on class Person, used in class Plane
 * @author Mateusz Bronislaw Wasilewski
**/


#include <iostream>
#include "crew.h"
#include "check_data.h"

// construtor for class Crew instance
Crew::Crew(std::string id,
        std::string fname,
        std::string lname,
        std::string position
    ) : Person(id, fname, lname), position(position)
{ set_position(position); }

// setter for position attribute
void Crew::set_position(std::string new_position)
{
    if(check_position(new_position))
    { position = new_position; }
    else
    { position = "INVALID_POSITION"; }
}

// getter fot position attribute
std::string Crew::get_position()
{ return position; }

std::ostream& operator<<(std::ostream& os, Crew &c)
{
    os << "Person id: " << c.get_person_id() << std::endl;
    os << "First name: " << c.get_first_name() << std::endl;
    os << "Last name: " << c.get_last_name() << std::endl;
    os << "Position: " << c.get_position() << std::endl;

    return os;
}