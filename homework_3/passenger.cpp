/**
 * Name: passenger.cpp
 * Purpose: implementation of class Passenger - based on class Person, used in class Plane
 * @author Mateusz Bronislaw Wasilewski
**/


#include <iostream>
#include "passenger.h"
#include "check_data.h"

// constructor for class Passenger instance
Passenger::Passenger(std::string id,
        std::string fname,
        std::string lname,
        std::string ticket,
        bool luggage,
        bool boarding_status
    ) : Person(id, fname, lname)
{
    set_ticket(ticket);
    set_luggage(luggage);
    set_boarding_status(boarding_status);
}

// setter for ticket attribute
void Passenger::set_ticket(std::string new_ticket)
{
    if(check_if_only_numbers(new_ticket))
    { ticket = new_ticket; }
    else
    { ticket = "INVALID_TICKET"; }
}

// getter for ticket attribute
std::string Passenger::get_ticket()
{ return ticket; }

// setter for luggage attribute
void Passenger::set_luggage(bool new_luggage)
{ luggage = new_luggage; }

bool Passenger::if_has_luggage()
{ return luggage; }

// getter for luggage attribute
std::ostream& operator<<(std::ostream& os, Passenger &p)
{
    os << "Person id: " << p.get_person_id() << std::endl;
    os << "First name: " << p.get_first_name() << std::endl;
    os << "Last name: " << p.get_last_name() << std::endl;
    os << "Ticket id: " << p.get_ticket() << std::endl;
    os << "Luggage: " << ((p.if_has_luggage())?("yes"):("no")) << std::endl;
    os << "If boarded: " << ((p.if_boarded())?("yes"):("no")) << std::endl;

    return os;
}

// setter for if_boarded attribute
void Passenger::set_boarding_status(bool new_status)
{ boarding_status = new_status; }
// getter for if_boarded attribute
bool Passenger::if_boarded()
{ return boarding_status; }