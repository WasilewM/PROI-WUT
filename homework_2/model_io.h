/**
 * Name: model_io.h
 * Purpose: declaration of IO api for the project
 * @author Mateusz Bronislaw Wasilewski
**/


#ifndef MODEL_IO_H
#define MODEL_IO_H
#include <string>
#include <iostream>

// function greets the user and displays short
// introduction information
void greet_user();

// function displays the main menu instructions - 
// how to convert units?
void display_main_menu_instructions();

// function displays units that user might want to
// convert to
void display_possible_conversion_units();

// function reads and returns user data input as str
std::string get_user_input();

// function displays asks the users to input data
// and returns get_user_input() function 
void ask_for_distance_value();

// function informs about user's invalid input data
void display_invalid_data_msg();

// function informs the user about invalid option choice
void display_invalid_option_msg();

// function returns chosen unit name
// supplementary function for display_chosen_conversion_type()
std::string get_unit_name(int unit);

// function informs the user about the chosen conversion type
void display_chosen_conversion_type(int start_unit, int expected_unit);

// fucntion displays the result to the user
// with appropriate formatting
void display_result(double distance, double factor);

// displays the last message to inform the user
// that the program has ended
void end_interaction();

#endif