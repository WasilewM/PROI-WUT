#include "train.h"
#include <iostream>

Train::Train(int wagons_num, int seats_num) : wagons_number(wagons_num), seats_number_per_wagon(seats_num)
{
    // if invalid value, sets deafult
    if(wagons_number < 0)
    { wagons_number = 0; }

    // if invalid value, sets deafult
    if(seats_number_per_wagon < 0)
    { seats_number_per_wagon = 0; }

    total_seats_number = wagons_number * seats_number_per_wagon;
    occupied_seats = 0;
}

bool Train::add_new_passenger()
{
    if(occupied_seats < total_seats_number)
    {
        occupied_seats += 1;
        return true;
    }
    return false;
}

bool Train::passenger_gets_out()
{
    if(occupied_seats > 0)
    {
        occupied_seats -= 1;
        return true;
    }

    return false;
}

bool Train::add_wagons(int new_wagon_num)
{
    if(new_wagon_num > 0)
    {
        wagons_number += new_wagon_num;
        total_seats_number += new_wagon_num * seats_number_per_wagon;
    }
    return false;
}

bool Train::remove_wagons(int wagons_num)
{
    if(wagons_number > 0)
    {
        if(total_seats_number - wagons_num * seats_number_per_wagon >= occupied_seats)
        {
            total_seats_number -= wagons_num * seats_number_per_wagon;
            wagons_number -= wagons_num;
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, Train &t)
{
    os << "Train description / Train state:" << std::endl;;
    os << "wagons number: " << t.wagons_number << std::endl;
    os << "seats number per wagon: " << t.seats_number_per_wagon << std::endl;
    os << "total seat number: " << t.total_seats_number << std::endl;
    os << "occupied seats number: " << t.occupied_seats << std::endl;
    return os;
}


void Train::get_train_state(Train &t)
{
    std::cout << t;
}