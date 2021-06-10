/**
 * Name: decribe_sequence.cpp
 * Purpose: finding max, min and avg values in the given sequence
 * @author Mateusz Wasilewski
*/

#include "describe_sequence.h"

std::pair <int, double> check_correctness(std::string input_data)
{
    // checks whether given data is valid

    double numeric_input = 0.0;
    bool if_point_detected = false;
    double fraction = 10;
    int data_length = input_data.length();
    int correctness = 1;  // takes 1 when data is valid, 0 when asked to calulate already
    // given data or -1 when the data is incorrect
    int sign = 1;  // takes 1 when positice or -1 when negative

    if(input_data == "calculate")  // checking whether this is the end of the sequence
    {
        std::pair <int, double> result (0, 0);
        return result; 
    }

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
    std::pair <int, double> result (correctness, numeric_input*sign);
    return result;
}

void describe_sequence()
{
    // function manages the process of calling other functions
    // in order to caluculate min, max and avg values of the 
    // given sequence

    // greeting the user and printing the instructions  
    greet_user();

    bool if_correct_data = true;
    bool are_all_data_entered = false;
    double max_value = 0;
    double min_value = 0;
    double sum_of_values = 0;
    int data_amount = 0;

    while(are_all_data_entered == 0)
    {
        // loop that continues as long as the input is correct
        // or when 'calculate' was entered

        std::string input_data = read_data();
        std::pair <int, double> checked_data = check_correctness(input_data);
        double numeric_data = checked_data.second;

        // checking whether the given value is correct
        // the correctness of the given value was verified by check_correctness()
        if(checked_data.first == 1)
        {
            if(data_amount == 0)
            {
                // in order to properly calculate max, min and avg values
                // first number in sequence is assigned to max, min and sum variables
                max_value = numeric_data;
                min_value = numeric_data;
                sum_of_values = numeric_data;
            }
            else
            {
                // this case for every correct value after the first one in sequence
    
                // checking whether the value is greater then current max
                if(numeric_data > max_value)
                {
                    max_value = numeric_data;
                }

                // checking whether the value is smaller then current min
                if(numeric_data < min_value)
                {
                    min_value = numeric_data;
                }
                
                // adding numbers to sum in order to be able to calculate average
                // at the end of the program
                sum_of_values += numeric_data;
            }
            
            // counting the number of values in sequence in order to
            // be able to calculate average at the end of the program
            data_amount++;
        }
        else
        {
            if (checked_data.first == 0)
            {
                // if the command 'calculate' was entered then here the vairable 
                // are_all_data_entered is set to true to perform calculations 
                are_all_data_entered = true;
            }
            else
            {
                // if some invalid value was entered then the variables below are set
                // in order to assure that the user will be informed about
                // this situation
                if_correct_data = false;
                are_all_data_entered = true;
            }
        }
    }

    if(if_correct_data)
    {
        if (data_amount == 0)
        {
            // informs the user that no data was entered
            no_input_data_msg();
        }
        else
        {
            // show max, min and avg values of the sequence if all
            // provided data are correct
            double avg_value = double(sum_of_values / data_amount);
            show_stats(max_value, min_value, avg_value);
        }
        
    }
    else
    {
        // inform the user that some data were invalid
        show_error_msg();
    }
}
