/**
 * Name: main.cpp
 * Purpose: main file of the "zadanie2" project
 * @author Mateusz Bronislaw Wasilewski
**/


#include <iostream>
#include "model_io.h"
#include "number_correctness.h"
#include "calculate_conversion_ratio.h"


int main()
{
    greet_user();

    bool if_continue_program = true;
    // loop continues until the user stops the program
    while(if_continue_program)
    {
        // displaying instructions of the main menu
        // and collecting user input
        display_main_menu_instructions();
        std::string user_input = get_user_input();

        // checking input correctness
        std::pair <int, double> user_choice = check_correctness(user_input);
        int option = int(user_choice.second);

        if(user_choice.first == 1 && double(option) == user_choice.second)
        {
            // case when eneterd data are valid
            if(option == 0)
            {
                // case when user wants to stop the program
                if_continue_program = false;
                end_interaction();
                continue;
            }
            else
            {
                if(option >= 1 && option <= 9)
                {
                    // case when user wants to convert units

                    // displying possible conversion options
                    display_possible_conversion_units();
                    std::string expected_unit = get_user_input();
                    // checking input correctness
                    std::pair <int, double> user_expected_unit = check_correctness(expected_unit);
                    int chosen_unit = user_expected_unit.second;

                    if(user_expected_unit.first == 1 && double(option) == user_expected_unit.second)
                    {
                        if(chosen_unit >= 1 && chosen_unit <= 9)
                        {
                            // case when all entered data are valid

                            // asking for distance value and checking input correctness
                            ask_for_distance_value();
                            std::string entered_distance = get_user_input();
                            std::pair <int, double> distance = check_correctness(entered_distance);

                            if(distance.first == 1)
                            {
                                // case when all entered data are valid and calculations can be done
                                display_chosen_conversion_type(option, chosen_unit);

                                double conversion_ratio = get_conversion_ratio(option, chosen_unit);
                                display_result(distance.second, conversion_ratio);
                            }
                            else
                            {
                                // case when entered distance is invalid
                                display_invalid_data_msg();
                                continue;
                            }

                        }
                        else
                        {
                            // case when chosen option is invalid or invalid data were entered
                            display_invalid_option_msg();
                            continue;
                        }
                    }
                    else
                    {
                        // case when chosen option is invalid or invalid data were entered
                        display_invalid_option_msg();
                        continue;
                    }
                }
                else
                {
                    // case when chosen option is invalid or invalid data were entered
                    display_invalid_option_msg();
                    continue;
                }
            }
        }
        else
        {
            // case when chosen option is invalid or invalid data were entered
            display_invalid_option_msg();
            continue;
        }
    }
    return 0;
}