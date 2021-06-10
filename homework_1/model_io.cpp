/**
 * Name: model_io.cpp
 * Purpose: implementation of io functions
 * @author Mateusz Wasilewski
*/

#include "model_io.h"
#include <iostream>

std::string read_data()
{
    // fucntion reads the data given by the user
    std::string input_data;
    std::cin >> input_data;

    return input_data;
}

void greet_user()
{
    // fucntions greets the user when it is called
    std::cout << "Hello there! Enter your sequence numbers here (separete them using 'Enter')" << std::endl;
    std::cout << "If you want to calculate numbers you have entered, please type 'calculate' after you numbers." << std::endl;
}

void show_stats(double max_value, double min_value, double avg_value)
{
    // functions displays the stats after successfully completed calculations
    std::cout << "Sequence average value: " << avg_value << std::endl;
    std::cout << "Sequence minimum value: " << min_value << std::endl;
    std::cout << "Sequence maximum value: " << max_value << std::endl;
}

void show_error_msg()
{
    // fucntions informs the user that some of the data were invalid and due to this reason
    // calculations cannot be made
    std::cout << "Some of the data were invalid. Calculations cannot be done." << std::endl;
}

void no_input_data_msg()
{
    // informs the user that no data was entered
    std::cout << "No data entered. Calculations cannot be done." << std::endl;
}