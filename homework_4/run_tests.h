/**
 * Name: run_tests.cpp
 * Purpose: implementation function calling the tests
 * @author Mateusz Bronislaw Wasilewski
**/

#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "dictionary.h"
#include "test_int_str.h"
#include "test_int_person.h"

// function calls test prepared for Dictionary<int, std::string>
void run_tests_dictionary_int_string(int millis=500);
// function calls test prepared for Dictionary<int, Person>
void run_tests_dictionary_int_person(int millis=500);
