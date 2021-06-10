/**
 * Name: number_correctness.h
 * Purpose: checking input number correctness
 * @author Mateusz Bronislaw Wasilewski
**/


#include "number_correctness.h"

std::pair <int, double> check_correctness(std::string input_data)
{
    // checks whether given data is valid

    double numeric_input = 0.0;
    bool if_point_detected = false;
    double fraction = 10;
    int data_length = input_data.length();
    int correctness = 1;  // takes 1 when data is valid
    // takes -1 when the data is incorrect
    int sign = 1;  // takes 1 when positice or -1 when negative

    for(int i = 0; i < data_length; i++)
    {
        // checking whether the values are correct
        if(input_data[i] >= '0' && input_data[i] <= '9')
        {
            if(!if_point_detected)
            {
                // translating the number from string to double
                // before the '.' is detected
                numeric_input *= 10;
                numeric_input += int(input_data[i] - '0');
            }
            else
            {
                // translating the number from string to double
                // after the '.' is detected
                numeric_input += double((int(input_data[i] - '0')) / fraction);
                fraction *= 10;
            }
        }
        else
        {
            // checking whether '.' was detected
            // if yes, then setting if_point_detected = true in order to
            // properly construct the number
            if(input_data[i] == '.' && if_point_detected == false)
            {
                if_point_detected = true;
                continue;
            }
            else
            {
                if(i == 0 && input_data[i] == '-' && data_length > 1)
                {
                    // seting sign value to represent the number sign
                    sign = -1;
                }
                else
                {
                    // detected invalid value, e.g. letters or another '.' in the sequence
                    correctness = -1;
                    break;
                }
            }
            
        }
    }

    // create result and return it
    std::pair <int, double> result (correctness, numeric_input*sign);
    return result;
}
