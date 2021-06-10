/**
 * Name: calculate_conversion_ratio.h
 * Purpose: declaration of functions that find ratio between conversion units
 * @author Mateusz Bronislaw Wasilewski
**/


#ifndef CALCULATE_CONVERSION_RATIO_H
#define CALCULATE_CONVERSION_RATIO_H

// function asks for dedicated functions and returns the ration
// between given option/unit and its value in millimeters
double get_ratio_from_start_unit_to_mm(int option);

// function manages the process of calculationg the ratio
// between the start unit and the expected one
double get_conversion_ratio(int option, int chosen_unit);

#endif