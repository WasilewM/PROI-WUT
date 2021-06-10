/**
 * Name: class_test.h
 * Purpose: declaration of class that is used to test class Plane
 * @author Mateusz Bronislaw Wasilewski
**/


#pragma once
#include "plane.h"

// class created to allow the user to test class Plane
class Test
{
private:
    // vector of planes used during tests
    std::vector <Plane> planes;
public:
    // function creates 2*2 instances of class plane
    // done due to the requirement of "zadanie 3"
    void init_start_objects();

    // constructor for class Test instance
    Test()
    { init_start_objects(); }

    // function allows the user to choose plane number
    // returns -1 if invalid value
    int choose_plane();

    // function allows to user to choose passenger
    int choose_passenger(int plane_id_in_vector);

    // function allows to user to choose crew member
    int choose_crew_member(int plane_id_in_vector);

    // function allows the user to add staff members to the
    // chosen plane
    void append_staff();
    // function allows the user to remove staff members from the
    // chosen plane
    void delete_staff();
    // functions allows the user to modify chosen staff member
    // attributes if chosen staff member exists
    void modify_staff_attributes();

    // function allows the user to add passengers to the
    // chosen plane
    void append_passenger();
    // function allows the user to remove passengers from the
    // chosen plane
    void delete_passenger();
    // functions allows the user to modify chosen passenger
    // attributes if chosen passenger exists
    void modify_passenger_attributes();

    // function allows the user to board chosen passenger
    void board_passenger();

    // function allows the user to add plane
    void append_plane();

    // returns vector of planes
    std::vector <Plane> return_planes();

    // allows the user to copy plane
    void copy_plane();
};