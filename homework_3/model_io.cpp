/**
 * Name: model_io.h
 * Purpose: implementation of io used in the project
 * @author Mateusz Bronislaw Wasilewski
**/


#include <iostream>
#include "model_io.h"
#include "class_test.h"

// function greets the user
void greet_the_user()
{ std::cout << "Hello there! Welcome to the test program!" << std::endl; }

// function displays main menu options and instructions
void display_main_menu()
{
    std::cout << "Choose option you want to proceed by entering the number." << std::endl;
    std::cout << "0. Close program" << std::endl;
    std::cout << "1. Add new plane" << std::endl;
    std::cout << "2. Display information about existing plane" << std::endl;
    std::cout << "3. Add crew member to existing plane" << std::endl;
    std::cout << "4. Add passenger to existing plane" << std::endl;   
    std::cout << "5. Board existing passenger" << std::endl;
    std::cout << "6. Copy plane (test copy constructor)" << std::endl;
    std::cout << "7. Delete crew member" << std::endl;
    std::cout << "8. Delete passenger" << std::endl;
    std::cout << "9. Modify chosen crew member attributes" << std::endl;
    std::cout << "10. Modify chosen passenger attributes" << std::endl << std::endl;
}

// function asks the user for entering the date
// information about the type of data is precised using given string
void ask_for_data(std::string data_description)
{ std::cout << "Enter " << data_description << " value." << std::endl; }

// function read the data
std::string read_data()
{
    std::string input_data = "";
    std::cin >> input_data;
    return input_data;
}

// function displays information about all planes added to class Test
// planes own values and its Crew, Passengers and boarded Passengers
void display_planes(std::vector <Plane> planes_list)
{
    std::cout << std::endl;
    for(unsigned long i = 0; i < planes_list.size(); ++i)
    { std::cout << planes_list[i] << std::endl; }
    std::cout << std::endl;
}

// function displays given message to the user
void show_msg(std::string msg)
{ std::cout << msg << std::endl; }

// function informs the user about the invalid option choice
void display_invalid_option_msg()
{
    std::cout << "Option not recognised. Please try again." << std::endl;
    std::cout << "Remember that you should enter only available digits.";
    std::cout << std::endl << std::endl;
}

// function informs the user that at least some data wwas invalid
// and new object cannot be created
void display_invalid_data_msg()
{
    std::cout << "At least some data was invalid; therefore," << std::endl;
    std::cout << "operation cannot be proceeded." << std::endl << std::endl;
}

// function informs the user that the procedure is was completed
void display_procedure_completion_msg()
{ std::cout << "Procedure completed." << std::endl << std::endl; }

// function displays the message at the end of the interaction
void end_interaction_msg()
{
    std::cout << "Thank you for using the program." << std::endl;
    std::cout << "Have a nice day." << std::endl << std::endl;
}

// function informs the user about the expected
// data format of names, places, etc:
void display_expected_data_format_letters()
{ std::cout << "Please enter only letters:" << std::endl; }

// function informs the user about the expected
// data format of id numbers and plane numbers
void display_expected_data_format_numbers()
{ std::cout << "Please enter only numbers:" << std::endl; }

// function informs the user about the expected
// data format of take off and landing times
void display_expected_data_format_daytime()
{ std::cout << "Please use format YYYY.MM.DD-hh:mm:ss" << std::endl; }

// function informs the user which values of "position" are valid
void display_expected_position_values()
{
    std::cout << "Please enter one of the following options:" << std::endl;
    std::cout << "\"captain\", \"pilot\", \"technician\", \"assistant\"" << std::endl;
}

// function displays crew object attributes
void display_crew_attributes()
{
    std::cout << "Please choose option you want to modify:" << std::endl;
    std::cout << "0. person id" << std::endl;
    std::cout << "1. first name" << std::endl;
    std::cout << "2. last name" << std::endl;
    std::cout << "3. position" << std::endl;
}

// function displays passenger object attributes
void display_passenger_attributes()
{
    std::cout << "Please choose option you want to modify:" << std::endl;
    std::cout << "0. person id" << std::endl;
    std::cout << "1. first name" << std::endl;
    std::cout << "2. last name" << std::endl;
    std::cout << "3. ticket id" << std::endl;
    std::cout << "4. luggage" << std::endl;
    std::cout << "5. boarding status" << std::endl;
}
