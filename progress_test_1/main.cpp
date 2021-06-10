// Name: main.cpp
// Purpose: main file of the first lab-test
// @author Mateusz Bronislaw Wasilewski
// index: 310972

#include <iostream>
#include "model_io.h"
#include "convert_data.h"

int main()
{
    ask_for_force();
    std::string force = read_data();
    ask_for_distance();
    std::string distance = read_data();
    if(check_correctness(force) && check_correctness(distance))
    {
        double converted_F = convert_data(force);
        double converted_s = convert_data(distance);
        display_result(converted_F, converted_s);
    }
    else
    {
        show_error_msg();
    }
    return 0;
}