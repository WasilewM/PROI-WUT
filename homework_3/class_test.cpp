/**
 * Name: class_test.cpp
 * Purpose: implementation of class that is used to test class Plane
 * @author Mateusz Bronislaw Wasilewski
**/


#include <cstdarg>
#include <string>
#include "class_test.h"
#include "model_io.h"
#include "convert_str_to_int.h"
#include "check_data.h"

// function creates 2*2 instances of class plane
// done due to the requirement of "zadanie 3"
void Test::init_start_objects()
{
    Plane start_plane_1(
        "1",
        "2021.04.09-09:00:00",
        "2021.04.09-12:00:00",
        "Swidnik",
        "Bydgoszcz"
    );

    Plane start_plane_1_copy(start_plane_1);

    planes.push_back(start_plane_1);
    planes.push_back(start_plane_1_copy);
}

// function allows the user to choose plane number
// returns -1 if invalid value
int Test::choose_plane()
{
    show_msg("In order to proceed please choose a number correcponding");
    show_msg("to the plane you want to operate on:");
    
    for (unsigned long i = 0; i < planes.size(); ++i)
    {
        std::string msg_line = std::to_string(i);
        msg_line += ". " + planes[i].get_plane_number();
        msg_line += " from: " + planes[i].get_departure();
        msg_line += " to: " + planes[i].get_destination();
        show_msg(msg_line);
    }

    std::string chosen_option = read_data();
    std::pair <bool, int> chosen_plane = convert_str_to_int(chosen_option);

    if (chosen_plane.first && (unsigned long)chosen_plane.second < planes.size())
    { return chosen_plane.second; }

    return -1; 
}

// function allows to user to choose passenger
int Test::choose_passenger(int plane_id_in_vector)
{
    Plane chosen_plane = planes[plane_id_in_vector];
    if(chosen_plane.get_passengers().size() > 0)
    {
        show_msg("In order to proceed please choose a number correcponding");
        show_msg("to the passenger you want to operate on:");
        
        for (unsigned long i = 0; i < chosen_plane.get_passengers().size(); ++i)
        {
            std::string msg_line = std::to_string(i);
            msg_line += ". " + chosen_plane.get_passengers()[i].get_first_name();
            msg_line += ". " + chosen_plane.get_passengers()[i].get_last_name();
            msg_line += ", id: " + chosen_plane.get_passengers()[i].get_person_id();
            show_msg(msg_line);
        }

        std::string chosen_option = read_data();
        std::pair <bool, int> chosen_passenger = convert_str_to_int(chosen_option);

        if (chosen_passenger.first)
        { return chosen_passenger.second; }
        else
        { return -1; }
    }
    else
    { return -1; }
}

// function allows to user to choose crew member
int Test::choose_crew_member(int plane_id_in_vector)
{
    Plane chosen_plane = planes[plane_id_in_vector];
    if(chosen_plane.get_crew().size() > 0)
    {
        show_msg("In order to proceed please choose a number correcponding");
        show_msg("to the crew member you want to operate on:");
        
        for (unsigned long i = 0; i < chosen_plane.get_crew().size(); ++i)
        {
            std::string msg_line = std::to_string(i);
            msg_line += ". " + chosen_plane.get_crew()[i].get_first_name();
            msg_line += ". " + chosen_plane.get_crew()[i].get_last_name();
            msg_line += ", id: " + chosen_plane.get_crew()[i].get_person_id();
            show_msg(msg_line);
        }

        std::string chosen_option = read_data();
        std::pair <bool, int> chosen_crew_member = convert_str_to_int(chosen_option);

        if (chosen_crew_member.first)
        { return chosen_crew_member.second; }
        else
        { return -1; }
    }
    else
    { return -1; }
}

// function allows the user to add staff members to the
// chosen plane
void Test::append_staff()
{
    int chosen_plane = choose_plane();    
    if(chosen_plane >= 0 && (unsigned long)chosen_plane < planes.size())
    {
        ask_for_data("person id");
        display_expected_data_format_numbers();
        std::string person_id = read_data();
        ask_for_data("first name");
        display_expected_data_format_letters();
        std::string fname = read_data();
        ask_for_data("last name");
        display_expected_data_format_letters();
        std::string lname = read_data();
        ask_for_data("position");
        display_expected_position_values();
        std::string position = read_data();

        if(
            check_if_only_numbers(person_id) &&
            check_if_only_letters(fname) &&
            check_if_only_letters(lname) &&
            check_position(position)
        )
        {
            Crew new_member(
                person_id,
                fname,
                lname,
                position
            );

            planes[chosen_plane].add_crew(new_member);
            display_procedure_completion_msg();
        }
        else
        { display_invalid_data_msg(); }

    }
    else
    { display_invalid_option_msg(); }
}

// function allows the user to remove staff members from the
// chosen plane
void Test::delete_staff()
{
    int chosen_plane = choose_plane();    
    if(chosen_plane >= 0 && (unsigned long)chosen_plane < planes.size())
    {
        if(planes[chosen_plane].get_crew().size() > 0)
        {
            int chosen_crew_member = choose_crew_member(chosen_plane);

            if(chosen_crew_member >= 0 && (unsigned long)chosen_crew_member < planes[chosen_plane].get_crew().size())
            {
                bool result = planes[chosen_plane].remove_crew(chosen_crew_member);
                if(result)
                { display_procedure_completion_msg(); }
                else
                { show_msg("Something went wrong."); }
            }
            else
            { show_msg("Chosen crew member does not exist."); }
        }
        else
        { show_msg("Chosen plane does not have crew members yet."); }
    }
    else
    { display_invalid_option_msg(); }
}

// functions allows the user to modify chosen staff member
// attributes if chosen passenger exists
void Test::modify_staff_attributes()
{
    int chosen_plane = choose_plane();    
    if(chosen_plane >= 0 && (unsigned long)chosen_plane < planes.size())
    {
        if(planes[chosen_plane].get_crew().size() > 0)
        {
            int chosen_crew_member = choose_crew_member(chosen_plane);

            if(chosen_crew_member >= 0 && (unsigned long)chosen_crew_member < planes[chosen_plane].get_crew().size())
            {
                display_crew_attributes();
                std::string read_option = read_data();
                std::pair <bool, int> chosen_option = convert_str_to_int(read_option);

                if(chosen_option.first && chosen_option.second < 4)
                {
                    if(chosen_option.second == 0)
                    {
                        ask_for_data("person id");
                        display_expected_data_format_numbers();
                        std::string person_id = read_data();

                        bool result = planes[chosen_plane].modify_crew(
                            chosen_crew_member,
                            "id",
                            person_id
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 1)
                    {
                        ask_for_data("first name");
                        display_expected_data_format_letters();
                        std::string fname = read_data();

                        bool result = planes[chosen_plane].modify_crew(
                            chosen_crew_member,
                            "fname",
                            fname
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 2)
                    {
                        ask_for_data("last name");
                        display_expected_data_format_letters();
                        std::string lname = read_data();

                        bool result = planes[chosen_plane].modify_crew(
                            chosen_crew_member,
                            "lname",
                            lname
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 3)
                    {
                        ask_for_data("position");
                        display_expected_position_values();
                        std::string position = read_data();

                        bool result = planes[chosen_plane].modify_crew(
                            chosen_crew_member,
                            "position",
                            position
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }                    
                }
                else
                { show_msg("Invalid option."); }
            }
            else
            { show_msg("Chosen crew member does not exist."); }
        }
        else
        { show_msg("Chosen plane does not have crew members yet."); }
    }
    else
    { display_invalid_option_msg(); }
}

// function allows the user to add passengers to the
// chosen plane
void Test::append_passenger()
{
    int chosen_plane = choose_plane(); 
    if(chosen_plane >= 0 && (unsigned long)chosen_plane< planes.size())
    {
        ask_for_data("person id");
        display_expected_data_format_numbers();
        std::string person_id = read_data();
        ask_for_data("first name");
        display_expected_data_format_letters();
        std::string fname = read_data();
        ask_for_data("last name");
        display_expected_data_format_letters();
        std::string lname = read_data();
        ask_for_data("ticket id");
        display_expected_data_format_numbers();
        std::string ticket = read_data();
        ask_for_data("luggage (enter yes or no)");
        std::string luggage = read_data();

        if(
            check_if_only_numbers(person_id) &&
            check_if_only_letters(fname) &&
            check_if_only_letters(lname) &&
            check_if_only_numbers(ticket) &&
            check_luggage(luggage)
        )
        {
            bool luggage_status = true;
            if(luggage == "no")
            { luggage_status = false; }

            Passenger new_passenger(
                person_id,
                fname,
                lname,
                ticket,
                luggage_status
            );

            planes[chosen_plane].add_passenger(new_passenger);
            display_procedure_completion_msg();
        }
        else
        { display_invalid_data_msg(); }
    }
    else
    { display_invalid_option_msg(); }
}

// function allows the user to remove passengers from the
// chosen plane
void Test::delete_passenger()
{
    int chosen_plane = choose_plane();    
    if(chosen_plane >= 0 && (unsigned long)chosen_plane < planes.size())
    {
        if(planes[chosen_plane].get_passengers().size() > 0)
        {
            int chosen_passenger = choose_passenger(chosen_plane);

            if(chosen_passenger >= 0 && (unsigned long)chosen_passenger < planes[chosen_plane].get_passengers().size())
            {
                bool result = planes[chosen_plane].remove_passenger(chosen_passenger);
                if(result)
                { display_procedure_completion_msg(); }
                else
                { show_msg("Something went wrong."); }
            }
            else
            { show_msg("Chosen passenger does not exist."); }
        }
        else
        { show_msg("Chosen plane does not have crew members yet."); }
    }
    else
    { display_invalid_option_msg(); }
}

// functions allows the user to modify chosen passenger
// attributes if chosen passenger exists
void Test::modify_passenger_attributes()
{
    int chosen_plane = choose_plane();    
    if(chosen_plane >= 0 && (unsigned long)chosen_plane < planes.size())
    {
        if(planes[chosen_plane].get_passengers().size() > 0)
        {
            int chosen_passenger = choose_passenger(chosen_plane);

            if(chosen_passenger >= 0 && (unsigned long)chosen_passenger < planes[chosen_plane].get_passengers().size())
            {
                display_passenger_attributes();
                std::string read_option = read_data();
                std::pair <bool, int> chosen_option = convert_str_to_int(read_option);

                if(chosen_option.first && chosen_option.second < 6)
                {
                    if(chosen_option.second == 0)
                    {
                        ask_for_data("person id");
                        display_expected_data_format_numbers();
                        std::string person_id = read_data();

                        bool result = planes[chosen_plane].modify_passenger(
                            chosen_passenger,
                            "id",
                            person_id
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 1)
                    {
                        ask_for_data("first name");
                        display_expected_data_format_letters();
                        std::string fname = read_data();

                        bool result = planes[chosen_plane].modify_passenger(
                            chosen_passenger,
                            "fname",
                            fname
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 2)
                    {
                        ask_for_data("last name");
                        display_expected_data_format_letters();
                        std::string lname = read_data();

                        bool result = planes[chosen_plane].modify_passenger(
                            chosen_passenger,
                            "lname",
                            lname
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 3)
                    {
                        ask_for_data("ticket id");
                        display_expected_data_format_numbers();
                        std::string ticket = read_data();

                        bool result = planes[chosen_plane].modify_passenger(
                            chosen_passenger,
                            "ticket",
                            ticket
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 4)
                    {
                        ask_for_data("luggage (enter yes or no)");
                        std::string luggage = read_data();

                        bool result = planes[chosen_plane].modify_passenger(
                            chosen_passenger,
                            "luggage",
                            luggage
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }
                    else if(chosen_option.second == 5)
                    {
                        ask_for_data("boarding status (enter yes or no)");
                        std::string boarding_status = read_data();

                        bool result = planes[chosen_plane].modify_passenger(
                            chosen_passenger,
                            "boarding_status",
                            boarding_status
                        );

                        if(result)
                        { display_procedure_completion_msg(); }
                        else
                        { show_msg("Something went wrong."); }
                    }              
                }
                else
                { show_msg("Invalid option."); }
            }
            else
            { show_msg("Chosen crew member does not exist."); }
        }
        else
        { show_msg("Chosen plane does not have crew members yet."); }
    }
    else
    { display_invalid_option_msg(); }
}

// function allows the user to board chosen passenger
void Test::board_passenger()
{
    int chosen_plane = choose_plane();

    if(chosen_plane >= 0 && (unsigned long)chosen_plane < planes.size())
    {
        if(planes[chosen_plane].get_passengers().size() > 0)
        {
            int chosen_passenger = choose_passenger(chosen_plane);

            if(chosen_passenger >= 0 && (unsigned long)chosen_passenger < planes[chosen_plane].get_passengers().size())
            {
                bool result = planes[chosen_plane].board_passenger(chosen_passenger);
                if(result)
                { display_procedure_completion_msg(); }
                else
                { show_msg("Something went wrong."); }
            }
            else
            { show_msg("Chosen passenger does not exist."); }
        }
        else
        { show_msg("Chosen plane does not have passengers yet."); }
    }
    else
    { show_msg("Chosen plane does not exist yet."); }
}

// function allows the user to add plane
void Test::append_plane()
{
    ask_for_data("plane number");
    display_expected_data_format_numbers();
    std::string plane_num = read_data();
    ask_for_data("take off time");
    display_expected_data_format_daytime();
    std::string take_off_t = read_data();
    ask_for_data("landing time");
    display_expected_data_format_daytime();
    std::string landing_t = read_data();
    ask_for_data("departure place");
    display_expected_data_format_letters();
    std::string departure_p = read_data();
    ask_for_data("destination place");
    display_expected_data_format_letters();
    std::string destination_p = read_data();

    if(
        check_if_only_numbers(plane_num) &&
        check_date_correctness(take_off_t) &&
        check_date_correctness(landing_t) &&
        check_if_only_letters(departure_p) &&
        check_if_only_letters(destination_p)
    )
    {
        Plane new_plane(
            plane_num,
            take_off_t,
            landing_t,
            departure_p,
            destination_p
        );

        planes.push_back(new_plane);
        display_procedure_completion_msg();
    }
    else
    { display_invalid_data_msg(); }
    
}

// returns vector of planes
std::vector <Plane> Test::return_planes()
{ return planes; }

// allows the user to copy plane
void Test::copy_plane()
{
    int chosen_plane_number = choose_plane();

    if(chosen_plane_number != -1)
    { planes.push_back(planes[chosen_plane_number]); }
    else
    { display_invalid_option_msg(); }
}