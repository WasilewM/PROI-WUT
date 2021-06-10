/**
 * Name: main.cpp
 * Purpose: calls for functions performing tests
 * @author Mateusz Bronislaw Wasilewski
**/


#include "run_tests.h"

int main()
{
    srand (time(NULL));

    // run tests
    run_tests_dictionary_int_string(250);
    run_tests_dictionary_int_person(250);
    return 0;
}