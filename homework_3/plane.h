/**
 * Name: plane.h
 * Purpose: declaration of class Plane - main goal/class of the "zadanie3" project
 * @author Mateusz Bronislaw Wasilewski
**/


#pragma once
#include <vector>
#include "crew.h"
#include "passenger.h"

// class Plane - main task of "zadanie 3"
// uses classes Crew and Passenger to represent its values
class Plane
{
private:
    // vector of Crew object added to the Plane instance
    std::vector <Crew> crew;
    // vector of Passenger object added to the Plane instance
    std::vector <Passenger> passengers;
    
    // represents plane number
    std::string plane_number;
    // represents take off date
    std::string take_off_time;
    // represents landing date
    std::string landing_time;
    // represents departure place
    std::string departure;
    // represents destination place
    std::string destination;

public:
    // init function for class Plane instance
    // calls for setters to check the data and set
    // them correctly
    void init_plane(
        std::string plane_number,
        std::string take_off_time,
        std::string landing_time,
        std::string departure,
        std::string destination
    );

    // constructor for class Plane instance
    // calls for init_plane()
    Plane(
        std::string plane_number,
        std::string take_off_time,
        std::string landing_time,
        std::string departure,
        std::string destination
    );

    // copy constructor for class Plane instance
    Plane(const Plane& to_copy);

    // allows to add new crew members to the plane
    void add_crew(Crew new_member);
    // getter for crew
    std::vector <Crew> get_crew();
    // allows to remove the crew member if one exists
    // the condition is checked based on the number of
    // the crew member in the vector
    bool remove_crew(unsigned long crew_member_num);
    // allows to modify crew member attributes
    bool modify_crew(
        unsigned long crew_member_num,
        std::string param,
        std::string new_val
    );

    // allows to add new passengers to the plane
    void add_passenger(Passenger new_passenger);
    // getter for passengers
    std::vector <Passenger> get_passengers();
    // allows to remove the passenger if one exists
    // the condition is checked based on the number of
    // the passenger in the vector
    bool remove_passenger(unsigned long passenger_num);
    // allows to modify crew member attributes
    bool modify_passenger(
        unsigned long passenger_num,
        std::string param,
        std::string new_val
    );

    // allows to board_passengers
    // Passenger object are added to boarded_passenger vector
    bool board_passenger(unsigned long passenger_num);

    // setter for plane_number attribute
    void set_plane_number(std::string pnumber);
    // getter for plane_number attribute
    std::string get_plane_number();

    // setter for take_off_time attribute
    void set_take_off_time(std::string time);
    // getter for take_off_time attribute
    std::string get_take_off_time();

    // setter for landing_time attribute
    void set_landing_time(std::string time);
    // getter for landing_time attribute
    std::string get_landing_time();

    // setter for departure attribute
    void set_departure(std::string new_departure);
    // getter for departure attribute
    std::string get_departure();

    // setter for destination attribute
    void set_destination(std::string new_destination);
    // getter for destination attribute
    std::string get_destination();

    friend std::ostream& operator<< (std::ostream &os, Plane &f);
    friend std::istream& operator>> (std::istream &is, Plane &f);

    Plane& operator=(Plane &f);
    bool operator!=(Plane &f);
    bool operator==(Plane &f);
};
