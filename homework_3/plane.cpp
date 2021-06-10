/**
 * Name: plane.h
 * Purpose: declaration of class Plane - main goal/class of the "zadanie3" project
 * @author Mateusz Bronislaw Wasilewski
**/


#include <iostream>
#include <string>
#include <vector>
#include "plane.h"
#include "check_data.h"

// init function for class Plane instance
// calls for setters to check the data and set
// them correctly
void Plane::init_plane(
    std::string plane_number,
    std::string take_off_time,
    std::string landing_time,
    std::string departure,
    std::string destination
)
{
    set_plane_number(plane_number);
    set_take_off_time(take_off_time);
    set_landing_time(landing_time);
    set_departure(departure);
    set_destination(destination);
}

// constructor for class Plane instance
// calls for init_plane()
Plane::Plane(
    std::string plane_number,
    std::string take_off_time,
    std::string landing_time,
    std::string departure,
    std::string destination
    )
{
    init_plane(
        plane_number,
        take_off_time,
        landing_time,
        departure,
        destination
    );
}

// copy constructor for class Plane instance
Plane::Plane(const Plane &to_copy) :
    plane_number(to_copy.plane_number),
    take_off_time(to_copy.take_off_time),
    landing_time(to_copy.landing_time),
    departure(to_copy.departure),
    destination(to_copy.destination)
{
    crew = to_copy.crew;
    passengers = to_copy.passengers;
}

// allows to add new crew members to the plane
void Plane::add_crew(Crew new_member)
{ crew.push_back(new_member); }

// getter for crew
std::vector <Crew> Plane::get_crew()
{ return crew; }

// allows to remove the crew member if one exists
// the condition is checked based on the number of
// the crew member in the vector
bool Plane::remove_crew(unsigned long crew_member_num)
{
    if(crew_member_num < crew.size())
    {
        std::vector <Crew> copied_crew = crew;
        crew.clear();

        for(unsigned long i = 0; i < copied_crew.size(); i++)
        {
            if(i != crew_member_num)
            { crew.push_back(copied_crew[i]); }
        }
        return true;
    }
    return false;
}

// allows to modify crew member attributes
bool Plane::modify_crew(
        unsigned long crew_member_num,
        std::string param,
        std::string new_val
    )
{
    if(crew_member_num < crew.size())
    {
        if(param == "id" && check_if_only_numbers(new_val))
        {
            crew[crew_member_num].set_person_id(new_val);
            return true;
        }
        else if(param == "fname" && check_if_only_letters(new_val))
        {
            crew[crew_member_num].set_first_name(new_val);
            return true;
        }
        else if(param == "lname" && check_if_only_letters(new_val))
        {
            crew[crew_member_num].set_last_name(new_val);
            return true;
        }
        else if(param == "position" && check_position(new_val))
        {
            crew[crew_member_num].set_position(new_val);
            return true;
        }
    }

    return false;
}

// allows to add new passengers to the plane
void Plane::add_passenger(Passenger new_passenger)
{ passengers.push_back(new_passenger); }

// getter for passengers
std::vector <Passenger> Plane::get_passengers()
{ return passengers; }

// allows to remove the passenger if one exists
// the condition is checked based on the number of
// the passenger in the vector
bool Plane::remove_passenger(unsigned long passenger_num)
{
    if(passenger_num < passengers.size())
    {
        std::vector <Passenger> copied_passengers = passengers;
        passengers.clear();

        for(unsigned long i = 0; i < copied_passengers.size(); i++)
        {
            if(i != passenger_num)
            { passengers.push_back(copied_passengers[i]); }
        }

        return true;
    }
    return false;
}

// allows to modify crew member attributes
bool Plane::modify_passenger(
    unsigned long passenger_num,
    std::string param,
    std::string new_val
)
{
    if(passenger_num < passengers.size())
    {
        if(param == "id" && check_if_only_numbers(new_val))
        {
            passengers[passenger_num].set_person_id(new_val);
            return true;
        }
        else if(param == "fname" && check_if_only_letters(new_val))
        {
            passengers[passenger_num].set_first_name(new_val);
            return true;
        }
        else if(param == "lname" && check_if_only_letters(new_val))
        {
            passengers[passenger_num].set_last_name(new_val);
            return true;
        }
        else if(param == "ticket" && check_if_only_numbers(new_val))
        {
            passengers[passenger_num].set_ticket(new_val);
            return true;
        }
        else if(param == "luggage")
        {
            if(new_val == "yes" || new_val == "no")
            {
                bool new_luggage = true;
                if(new_val == "no")
                { new_luggage = false; }

                passengers[passenger_num].set_luggage(new_luggage);
                return true;
            }
        }
        else if(param == "boarding_status")
        {
            if(new_val == "yes" || new_val == "no")
            {
                bool new_boarding_status = true;
                if(new_val == "no")
                { new_boarding_status = false; }

                passengers[passenger_num].set_boarding_status(new_boarding_status);
                return true;
            }
        }
    }

    return false;
}

// allows to board_passengers
// Passenger object are added to boarded_passenger vector
bool Plane::board_passenger(unsigned long passenger_num)
{
    if(passenger_num < passengers.size())
    {
        passengers[passenger_num].set_boarding_status(true);
        return true;
    }
    return false;
}

// setter for plane_number attribute
void Plane::set_plane_number(std::string pnumber)
{
    if(check_if_only_numbers(pnumber))
    { plane_number = pnumber; }
    else
    {
        // in case of empty string / invalid data
        pnumber = "DefaultPlaneNumber";
    }
}

// getter for plane_number attribute
std::string Plane::get_plane_number()
{ return plane_number; }

// setter for take_off_time attribute
void Plane::set_take_off_time(std::string time)
{
    if(check_date_correctness(time))
    { take_off_time = time; }
    else
    {
        // in case of empty string / invalid data
        take_off_time = "01.01.1900-00:00";
    }
}

// getter for take_off_time attribute
std::string Plane::get_take_off_time()
{ return take_off_time; }

// setter for landing_time attribute
void Plane::set_landing_time(std::string time)
{
    if(check_date_correctness(time))
    { landing_time = time; }
    else
    {
        // in case of empty string / invalid data
        landing_time = "01.01.1900-00:00";
    }
}

// getter for landing_time attribute
std::string Plane::get_landing_time()
{ return landing_time; }

// setter for departure attribute
void Plane::set_departure(std::string new_departure)
{
    if(check_if_only_letters(new_departure))
    { departure = new_departure; }
    else
    {
        // in case of empty string / invalid data
        departure = "DefaultDeparture";
    }
}

// getter for departure attribute
std::string Plane::get_departure()
{ return departure; }

// setter for destination attribute
void Plane::set_destination(std::string new_destination)
{
    if(check_if_only_letters(new_destination))
    { destination = new_destination; }
    else
    {
        // in case of empty string / invalid data
        destination = "DefaultDestination";
    }
}

// getter for destination attribute
std::string Plane::get_destination()
{ return destination; }

std::ostream& operator<<(std::ostream& os, Plane &f)
{
    os << "--------------------------------------" << std::endl;

    os << "Plane number: " << f.get_plane_number() << std::endl;
    os << "Take off time: " << f.get_take_off_time() << std::endl;
    os << "Landing time: " << f.get_landing_time() << std::endl;
    os << "Departure place: " << f.get_departure() << std::endl;
    os << "Destination place: " << f.get_destination() << std::endl;

    os << "--------------------------------------" << std::endl;

    os << "Crew members:" << std::endl;
    for(unsigned long i = 0; i < f.get_crew().size(); ++i)
    { os << f.get_crew()[i] << std::endl; }

    os << "--------------------------------------" << std::endl;

    os << "Passengers: " << std::endl;
    for(unsigned long i = 0; i < f.get_passengers().size(); ++i)
    { os << f.get_passengers()[i] << std::endl; }

    os << "--------------------------------------" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Plane &f)
{
    is >> f.plane_number;
    is >> f.take_off_time;
    is >> f.landing_time;
    is >> f.departure;
    is >> f.destination;

    return is;
}

Plane& Plane::operator=(Plane &f)
{
    if(this != &f)
    {
        this -> plane_number = f.get_plane_number();
        this -> take_off_time = f.get_take_off_time();
        this -> landing_time = f.get_landing_time();
        this -> departure = f.get_departure();
        this -> destination = f.get_destination();

        init_plane(
            plane_number,
            take_off_time,
            landing_time,
            departure,
            destination
        );
    }
    return *this;
}

bool Plane::operator!=(Plane &f)
{
    Plane temp = *this;

    if(temp.get_plane_number() == f.get_plane_number()
    && temp.get_take_off_time() == f.get_take_off_time()
    && temp.get_landing_time() == f.get_landing_time()
    && temp.get_departure() == f.get_departure()
    && temp.get_destination() == f.get_destination())
    { return false; }

    return true;
}

bool Plane::operator==(Plane &f)
{
    Plane temp = *this;

    if(temp.get_plane_number() == f.get_plane_number()
    && temp.get_take_off_time() == f.get_take_off_time()
    && temp.get_landing_time() == f.get_landing_time()
    && temp.get_departure() == f.get_departure()
    && temp.get_destination() == f.get_destination())
    { return true; }

    return false;
}