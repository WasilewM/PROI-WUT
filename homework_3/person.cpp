/**
 * Name: passenger.cpp
 * Purpose: implementation of class Person - used as a basis for classess Crew and Passenger
 * @author Mateusz Bronislaw Wasilewski
**/


#include "person.h"
#include "check_data.h"

// constructor for class Person instance
Person::Person(std::string id,
        std::string fname,
        std::string lname
    ) : person_id(id), first_name(fname), last_name(lname)
{
    set_person_id(id);
    set_first_name(fname);
    set_last_name(lname);
}

// setter for person_id attribute
void Person::set_person_id(std::string new_id)
{
    if(check_if_only_numbers(new_id))
    { person_id = new_id; }
    else
    { person_id = "INVALID_ID"; }
}

// getter for person_id attribute
std::string Person::get_person_id()
{ return person_id; }

// setter for first_name attribute
void Person::set_first_name(std::string new_fname)
{
    if(check_if_only_letters(new_fname))
    { first_name = new_fname; }
    else
    { first_name = "INVALID_FIRST_NAME"; }
}

// getter for first_name attribute
std::string Person::get_first_name()
{ return first_name; }

// setter for last_name attribute
void Person::set_last_name(std::string new_lname)
{
    if(check_if_only_letters(new_lname))
    { last_name = new_lname; }
    else
    { last_name = "INVALID_FIRST_NAME"; }
}

// getter for last_name attribute
std::string Person::get_last_name()
{ return last_name; }
