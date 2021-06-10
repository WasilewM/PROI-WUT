#include "convert_data.h"

double convert_data(std::string input_data)
{
    double numeric_input = 0.0;
    bool if_point_detected = false;
    double fraction = 10;
    int data_length = input_data.length();
    int sign = 1;

    for(int i = 0; i < data_length; i++)
    {
        if(input_data[i] >= '0' && input_data[i] <= '9')
        {
            if(!if_point_detected)
            {
                numeric_input *= 10;
                numeric_input += int(input_data[i] - '0');
            }
            else
            {
                numeric_input += double((int(input_data[i] - '0')) / fraction);
                fraction *= 10;
            }
        }
        else
        {
            if(input_data[i] == '.' && if_point_detected == false)
            {
                if_point_detected = true;
                continue;
            }
            else
            {
                if(i == 0 && input_data[i] == '-' && data_length > 1)
                {
                    sign = -1;
                }
            }
            
        }
    }
    return sign*numeric_input;
}

bool check_correctness(std::string input_data)
{
    bool if_point_detected = false;
    int data_length = input_data.length();

    for(int i = 0; i < data_length; i++)
    {
        if(input_data[i] >= '0' && input_data[i] <= '9')
        {
            if(!if_point_detected)
            {
                continue;
            }
            else
            {
                continue;
            }
        }
        else
        {
            if(input_data[i] == '.' && if_point_detected == false)
            {
                if_point_detected = true;
                continue;
            }
            else
            {
                if(i == 0 && input_data[i] == '-' && data_length > 1)
                {
                    continue;
                }
                else
                {
                    // detected invalid value, e.g. letters or another '.' in the sequence
                    return false;
                }
            
            }
        }
    }
    
    return true;
}