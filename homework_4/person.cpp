/**
 * Name: person.cpp
 * Purpose: implementation of class Person
 * @author Mateusz Bronislaw Wasilewski
**/

#include "person.h"
#include <iostream>

// constructor
Person::Person(int id_num, int age_val, std::string fname, std::string lname)
{
    // if given values are not valid, sets default

    if(id >= 0)
    { id = id_num; }
    else
    { id = 0; }

    if(age_val >= 0)
    { age = age_val; }
    else
    { age = 0; }

    if(fname != "")
    { first_name = fname; }
    else
    { first_name = "FNAME"; }

    if(lname != "")
    { last_name = lname; }
    else
    { last_name = "LNAME"; }
}

// getter for id
int Person::get_id()
{ return id; }

// getter for age
int Person::get_age()
{ return age; }

// getter for first_name
std::string Person::get_first_name()
{ return first_name; }

// getter for last_name
std::string Person::get_last_name()
{ return last_name; }

// overloaded operator<<
std::ostream& operator<<(std::ostream& os, Person &p)
{
    os << p.get_id() << ' ' << p.get_age() << ' ' << p.get_first_name();
    os << ' ' << p.get_last_name();

    return os;
}

// overloaded operator==
bool Person::operator==(Person &p)
{
    if(this->get_id() == p.get_id() &&
    this->get_age() == p.get_age() &&
    this->get_first_name() == p.get_first_name() &&
    this->get_last_name() == p.get_last_name())
    {
        return true;
    }

    return false;
}

// overloaded operator!=
bool Person::operator!=(Person &p)
{
    return ((*this==p)?false:true);
}
