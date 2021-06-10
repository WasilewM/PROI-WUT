/**
 * Name: main.cpp
 * Purpose: main file of the "zadanie3" project
 * @author Mateusz Bronislaw Wasilewski
**/


#include <iostream>
#include "class_test.h"
#include "model_io.h"
#include "convert_str_to_int.h"

int main()
{
    bool if_continue_program = true;
    Test test_program;
    enum Main_menu {
        close_program,
        new_plane,
        display_existing_planes,
        new_crew_member,
        new_passenger,
        try_to_board_passenger,
        copy_plane,
        delete_crew,
        delete_pssngr,
        mdfy_crew,
        mdfy_passenger
    };

    greet_the_user();
    while(if_continue_program)
    {
        // main menu loop

        display_main_menu();
        std::string chosen_option = read_data();
        std::pair <bool, int> converted_option = convert_str_to_int(chosen_option);
        if(converted_option.first)
        {
            // according to the user choice calls for appropriate functions
            
            if(converted_option.second == Main_menu::close_program)
            {
                if_continue_program = false;
                end_interaction_msg();
            }
            else if(converted_option.second == Main_menu::new_plane)
            { test_program.append_plane(); }
            else if(converted_option.second == Main_menu::display_existing_planes)
            { display_planes(test_program.return_planes()); }
            else if(converted_option.second == Main_menu::new_crew_member)
            { test_program.append_staff(); }
            else if(converted_option.second == Main_menu::new_passenger)
            { test_program.append_passenger(); }
            else if(converted_option.second == Main_menu::try_to_board_passenger)
            { test_program.board_passenger(); }
            else if(converted_option.second == Main_menu::copy_plane)
            { test_program.copy_plane(); }
            else if(converted_option.second == Main_menu::delete_crew)
            { test_program.delete_staff(); }
            else if(converted_option.second == Main_menu::delete_pssngr)
            { test_program.delete_passenger();}
            else if(converted_option.second == Main_menu::mdfy_crew)
            { test_program.modify_staff_attributes(); }
            else if(converted_option.second == Main_menu::mdfy_passenger)
            { test_program.modify_passenger_attributes(); }
            else
            { display_invalid_option_msg(); }
        }
        else
        { display_invalid_option_msg();  }
    }

    return 0;
}