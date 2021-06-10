/**
 * Name: test_int_person.h
 * Purpose: declaration of class Test_INT_PERSON
 * @author Mateusz Bronislaw Wasilewski
**/

#pragma once

#include "dictionary.h"
#include "person.h"

class Test_INT_PERSON
{
public:
    void test_init();
    void test_add_single_record();
    void test_add_random_num_records();
    void test_remove_single_record();
    void test_remove_random_num_records();
    void test_change_single_value();
    void test_is_in_dict_single_time_true();
    void test_is_in_dict_single_time_false();
    void test_is_in_dict_random();
    void test_check_value_single();
    void test_check_value_random_times();
    void test_examplary_print();
    void test_equality_operator();
    void test_not_equal_operator();
    void test_clear();
};