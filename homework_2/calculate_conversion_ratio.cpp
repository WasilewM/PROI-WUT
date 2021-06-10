/**
 * Name: calculate_conversion_ratio.cpp
 * Purpose: finding ratios between conversion units
 * @author Mateusz Bronislaw Wasilewski
**/


#include "ratios_between_units.h"

// function asks for dedicated functions and returns the ration
// between given option/unit and its value in millimeters
double get_unit_ratio_to_millimeters(int unit)
{
    double ratio = 1.0;

    switch (unit)
    {
        case 1:
            ratio = get_ratio_between_dalens_and_mm();
            break;
        case 2:
            ratio = get_ratio_between_nalens_and_mm();
            break;
        case 3:
            ratio = get_ratio_between_salens_and_mm();
            break;
        case 4:
            ratio = get_ratio_between_fods_and_mm();
            break;
        case 5:
            ratio = get_ratio_between_elbows_and_mm();
            break;
        case 6:
            ratio = get_ratio_between_meters_and_mm();
            break;
        case 7:
            ratio = get_ratio_between_decimeters_and_mm();
            break;
        case 8:
            ratio = get_ratio_between_centimeters_and_mm();
            break;
        case 9:
            ratio = 1.0;
            break;
        default:
            break;
    }

    return ratio;
}

// function manages the process of calculating the ratio
// between the start unit and the expected one
double get_conversion_ratio(int option, int chosen_unit)
{
    // determining the ratio between the start unit and millimeters
    double ratio = 1.0;
    double partial_ratio = get_unit_ratio_to_millimeters(option);
    ratio *= partial_ratio;

    // determining the ratio between the expected unit and millimeters
    partial_ratio = get_unit_ratio_to_millimeters(chosen_unit);

    // determining the ratio between the start unit and the expected one
    ratio /= partial_ratio;

    return ratio;
}