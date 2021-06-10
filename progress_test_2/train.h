#pragma once
#include <iostream>

class Train
{
private:
    int wagons_number;
    int seats_number_per_wagon;
    int total_seats_number;
    int occupied_seats;     // train state
public:
    Train(int wagons_num, int seats_num);

    bool add_new_passenger();
    bool passenger_gets_out();

    bool add_wagons(int new_wagons_num);
    bool remove_wagons(int wagons_num);

    friend std::ostream& operator<< (std::ostream &os, Train &t);

    void get_train_state(Train &t);
};