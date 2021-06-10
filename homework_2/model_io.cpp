/**
 * Name: model_io.cpp
 * Purpose: IO api for the project
 * @author Mateusz Bronislaw Wasilewski
**/


#include "model_io.h"

// function greets the user and displays short
// introduction information
void greet_user()
{
    std::cout << "Hello there! Welcome to the ski jumping units conversion program."
    << std::endl;
}

// functions displays the main menu instructions - 
// how to convert units?
void display_main_menu_instructions()
{
    std::cout << "If you want to convert units, please choose the number corresponding" << std::endl;
    std::cout << "to the conversion you want to preceed." << std::endl;
    std::cout << "List of available conversions:" << std::endl;

    std::cout << "Conversion from Danish alens - 1" << std::endl;
    std::cout << "Conversion from Norwegian alens - 2" << std::endl;
    std::cout << "Conversion from Swedish alens - 3" << std::endl;
    std::cout << "Conversion from fods - 4" << std::endl;
    std::cout << "Conversion from elbows - 5" << std::endl;
    std::cout << "Conversion from meters - 6" << std::endl;
    std::cout << "Conversion from decimeters - 7" << std::endl;
    std::cout << "Conversion from centimeters - 8" << std::endl;
    std::cout << "Conversion from millimeters - 9" << std::endl;

    std::cout << "If you want to close the program, please enter: 0" << std::endl;
}


// function displays units that user might want to
// convert to
void display_possible_conversion_units()
{
    std::cout << "Please choose unit you want to convert to:" << std::endl;

    std::cout << "Danish alens - 1" << std::endl;
    std::cout << "Norwegian alens - 2" << std::endl;
    std::cout << "Swedish alens - 3" << std::endl;
    std::cout << "fods - 4" << std::endl;
    std::cout << "elbows - 5" << std::endl;
    std::cout << "meters - 6" << std::endl;
    std::cout << "decimeters - 7" << std::endl;
    std::cout << "centimeters - 8" << std::endl;
    std::cout << "millimeters - 9" << std::endl;
}


// function reads and returns user data input as str
std::string get_user_input()
{
    std::string data = "";
    std::cin >> data;
    return data;
}

// function displays asks the users to input data
// and returns get_user_input() function
void ask_for_distance_value()
{
    std::cout << "Enter distance value: " << std::endl;
}

// function informs about user's invalid input data
void display_invalid_data_msg()
{
    std::cout << "Invalid data. Please try again." << std::endl;
    std::cout << std::endl;
}

// function informs the user about invalid option choice
void display_invalid_option_msg()
{
    std::cout << "Option no recognised. Please try again." << std::endl;
    std::cout << std::endl;
}

// function returns chosen unit name
// supplementary function for display_chosen_conversion_type()
std::string get_unit_name(int unit)
{
    std::string unit_name = "";
    switch (unit)
    {
        case 1:
            unit_name = "Danish alens";
            break;
        case 2:
            unit_name = "Norwegian alens";
            break;
        case 3:
            unit_name = "Swedish alens";
            break;
        case 4:
            unit_name = "fods";
            break;
        case 5:
            unit_name = "elbows";
            break;
        case 6:
            unit_name = "meters";
            break;
        case 7:
            unit_name = "decimeters";
            break;
        case 8:
            unit_name = "centimeters";
            break;
        case 9:
            unit_name = "millimeters";
            break;
    }

    return unit_name;
}

// function informs the user about the chosen conversion type
void display_chosen_conversion_type(int start_unit, int expected_unit)
{
    std::string message = "Conversion from ";
    message += get_unit_name(start_unit) + " to ";
    message += get_unit_name(expected_unit) + ":";

    std::cout << std::endl << message << std::endl;
}

// fucntion displays the result to the user
// with appropriate formatting
void display_result(double distance, double factor)
{
    std::cout << distance << " * " << factor;
    std::cout << " = " << distance * factor << std::endl;
    std::cout << std::endl;
}

// displays the last message to inform the user
// that the program has ended
void end_interaction()
{
    std::cout << "Thank you for using the program!" << std::endl;
    std::cout << "Have a nice day!" << std::endl;
}