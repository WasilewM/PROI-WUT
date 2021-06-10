/**
 * Name: passenger.h
 * Purpose: declaration of class Passenger - based on class Person, used in class Plane
 * @author Mateusz Bronislaw Wasilewski
**/


#pragma once
#include "person.h"

// represents the Passenger
// inherits after class Person
class Passenger: public Person
{
private:
    // represents the ticket value of the passenger
    std::string ticket;
    // tells whether the passenger has a luggage ("yes" or "no")
    bool luggage;
    bool boarding_status;
public:
    // constructor for class Passenger instance 
    Passenger(std::string person_id,
        std::string first_name,
        std::string last_name,
        std::string ticket,
        bool luggage=0,
        bool if_boarded=0
    );

    // setter for ticket attribute
    void set_ticket(std::string new_ticket);
    // getter for ticket attribute
    std::string get_ticket();

    // setter for luggage attribute
    void set_luggage(bool new_luggage);
    // getter for luggage attribute
    bool if_has_luggage();

    // setter for if_boarded attribute
    void set_boarding_status(bool new_status);
    // getter for if_boarded attribute
    bool if_boarded();

    friend std::ostream& operator<< (std::ostream &os, Passenger &p);
};