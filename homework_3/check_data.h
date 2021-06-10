/**
 * Name: check_data.h
 * Purpose: declaration of functions that check data correctness
 * @author Mateusz Bronislaw Wasilewski
**/


#ifndef CHECK_DATA_H
#define CHECK_DATA_H
#include <string>

// function checks whether given string only consists of numbers 
bool check_if_only_numbers(std::string to_be_checked);

// function checks whether given string only consists of letters
bool check_if_only_letters(std::string to_be_checked);

// function checks whether given string is of an expected date format
// yyyy.mm.dd-hh:mm:ss
bool check_date_correctness(std::string date);

// function checks whether given string representing passenger luggage
// is equal to "yes" or "no" - if so returns true, otherwise returns false
bool check_luggage(std::string luggage);

// function checls, whether given value is a valid position
bool check_position(std::string position);

#endif