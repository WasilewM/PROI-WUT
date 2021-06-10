#include "model_io.h"
#include "calculations.h"
#include <iostream>


void ask_for_force()
{
    std::cout << "Enter Force value in Newtons: " << std::endl;
}

void ask_for_distance()
{
    std::cout << "Enter distance value in meters: " << std::endl;
}

std::string read_data()
{
    // fucntion reads the data given by the user
    std::string input_data;
    std::cin >> input_data;

    return input_data;
}

void show_error_msg()
{
    std::cout << "Some of the data were invalid. Calculations cannot be done." << std::endl;
}

void display_result(double F, double s)
{
    std::cout << "W = F * s = ";
    std::cout << F << " * " << s;
    std::cout << " = " << calculate_work(F, s);
    std::cout << " J" << std::endl;
    std::cout << std::endl;
}
