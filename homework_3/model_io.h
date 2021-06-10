/**
 * Name: model_io.h
 * Purpose: declaration of io used in the project
 * @author Mateusz Bronislaw Wasilewski
**/


#pragma once
#include <string>
#include "plane.h"

// function greets the user
void greet_the_user();

// function displays main menu options and instructions
void display_main_menu();

// function asks the user for entering the date
// information about the type of data is precised using given string
void ask_for_data(std::string data_description);

// function read the data
std::string read_data();

// function displays information about all planes added to class Test
// planes own values and its Crew, Passengers and boarded Passengers
void display_planes(std::vector <Plane> planes_list);

// function displays given message to the user
void show_msg(std::string msg);

// function informs the user about the invalid option choice
void display_invalid_option_msg();

// function informs the user that at least some data was invalid
// and new object cannot be created
void display_invalid_data_msg();

// function informs the user that the procedure is was completed
void display_procedure_completion_msg();

// function displays the message at the end of the interaction
void end_interaction_msg();

// function informs the user about the expected
// data format of names, places, etc:
void display_expected_data_format_letters();

// function informs the user about the expected
// data format of id numbers and plane numbers
void display_expected_data_format_numbers();

// function informs the user about the expected
// data format of take off and landing times
void display_expected_data_format_daytime();

// function informs the user which values of "position" are valid
void display_expected_position_values();

// function displays crew object attributes
void display_crew_attributes();

// function displays passenger object attributes
void display_passenger_attributes();
