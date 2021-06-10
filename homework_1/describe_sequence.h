/**
 * Name: decribe_sequence.h
 * Purpose: declaration of the functions
 * @author Mateusz Wasilewski
*/

#ifndef DESCRIBE_SEQUENCE_H
#define DESCRIBE_SEQUENCE_H
#include "model_io.h"

// checks whether given data is valid
std::pair <int, double> check_correctness(std::string input_data);

// function manages the process of calling other functions
// in order to caluculate min, max and avg values of the 
// given sequence
void describe_sequence();

#endif