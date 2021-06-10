/**
 * Name: run_tests.cpp
 * Purpose: implementation function calling the tests
 * @author Mateusz Bronislaw Wasilewski
**/

#include "run_tests.h"

// macro used to make a delay between test to allow for easier reading of the results
#define wait(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

// function calls test prepared for Dictionary<int, std::string>
void run_tests_dictionary_int_string(int millis)
{
    std::cout << "***********************************";
    std::cout << "***********************************" << std::endl;
    std::cout << "INT_STR" << std::endl;
    wait(millis);
    Test_INT_STR test1;
    test1.test_init();
    wait(millis);
    test1.test_add_single_record();
    wait(millis);
    test1.test_add_random_num_records();
    wait(millis);
    test1.test_remove_single_record();
    wait(millis);
    test1.test_remove_random_num_records();
    wait(millis);
    test1.test_change_single_value();
    wait(millis);
    test1.test_is_in_dict_single_time_true();
    wait(millis);
    test1.test_is_in_dict_single_time_false();
    wait(millis);
    test1.test_is_in_dict_random();
    wait(millis);
    test1.test_check_value_single();
    wait(millis);
    test1.test_check_value_random_times();
    wait(millis);
    test1.test_examplary_print();
    wait(millis);
    test1.test_equality_operator();
    wait(millis);
    test1.test_not_equal_operator();
    wait(millis);
    test1.test_clear();
    std::cout << "***********************************";
    std::cout << "***********************************" << std::endl;
    wait(millis);
}

// function calls test prepared for Dictionary<int, Person>
void run_tests_dictionary_int_person(int millis)
{
    std::cout << "***********************************";
    std::cout << "***********************************" << std::endl;
    std::cout << "INT_PERSON" << std::endl;
    wait(millis);
    Test_INT_PERSON test1;
    test1.test_init();
    wait(millis);
    test1.test_add_single_record();
    wait(millis);
    test1.test_add_random_num_records();
    wait(millis);
    test1.test_remove_single_record();
    wait(millis);
    test1.test_remove_random_num_records();
    wait(millis);
    test1.test_change_single_value();
    wait(millis);
    test1.test_is_in_dict_single_time_true();
    wait(millis);
    test1.test_is_in_dict_single_time_false();
    wait(millis);
    test1.test_is_in_dict_random();
    wait(millis);
    test1.test_check_value_single();
    wait(millis);
    test1.test_check_value_random_times();
    wait(millis);
    test1.test_examplary_print();
    wait(millis);
    test1.test_equality_operator();
    wait(millis);
    test1.test_not_equal_operator();
    wait(millis);
    test1.test_clear();
    std::cout << "***********************************";
    std::cout << "***********************************" << std::endl;
}