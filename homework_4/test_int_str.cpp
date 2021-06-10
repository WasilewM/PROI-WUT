/**
 * Name: test_int_str.cpp
 * Purpose: declaration of class Test_INT_STR
 * @author Mateusz Bronislaw Wasilewski
**/

#include "test_int_str.h"
#include <cassert>
#include <ctime>

void Test_INT_STR::test_init()
{
    Dictionary <int, std::string> dict;

    int expected = 0;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST INIT:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_add_single_record()
{
    Dictionary <int, std::string> dict;
    dict.add(1, "single record");

    int expected = 1;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST ADD SINGLE RECORD:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_add_random_num_records()
{
    Dictionary <int, std::string> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, std::to_string(i)); }

    assert(dict.get_size() == rand_records_num);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST ADD RANDOM NUM RECORDS:" << std::endl;
    std::cout << "assert(dict.get_size() == rand_records_num) : ";
    std::cout << (dict.get_size() == rand_records_num) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_remove_single_record()
{
    Dictionary <int, std::string> dict;

    dict.add(1, "single record");
    dict.remove(1, "single record");

    int expected = 0;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST REMOVE SINGLE RECORD:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_remove_random_num_records()
{
    Dictionary <int, std::string> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, std::to_string(i)); }

    int to_be_removed = rand() % rand_records_num;
    for(int i = 0; i < to_be_removed; i++)
    { dict.remove(i, std::to_string(i)); }

    int expected = rand_records_num - to_be_removed;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST REMOVE RANDOM NUM RECORDS:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_change_single_value()
{
    Dictionary <int, std::string> dict;
    dict.add(1, "first_value");
    assert(dict.check_value(1) == "first_value");

    dict.change(1, "changed_value");
    assert(dict.check_value(1) == "changed_value");

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CHANGE SINGLE VALUE:" << std::endl;
    std::cout << "assert(dict.check_value(1) == \"changed_value\") : ";
    std::cout << (dict.check_value(1) == "changed_value") << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_is_in_dict_single_time_true()
{
    Dictionary <int, std::string> dict;
    dict.add(1, "first_value");

    assert(dict.is_in_dict(1) == true);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST IS IN DICT SINGLE TOME TRUE:" << std::endl;
    std::cout << "assert(dict.is_in_dict(1) == true) : ";
    std::cout << (dict.is_in_dict(1) == true) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_is_in_dict_single_time_false()
{
    Dictionary <int, std::string> dict;
    dict.add(1, "first_value");

    assert(dict.is_in_dict(99) == false);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST IS IN DICT SINGLE TOME TRUE:" << std::endl;
    std::cout << "assert(dict.is_in_dict(99) == false) : ";
    std::cout << (dict.is_in_dict(99) == false) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_is_in_dict_random()
{
    Dictionary <int, std::string> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, std::to_string(i)); }

    for(int i = 0; i < rand_records_num; i++)
    { assert(dict.is_in_dict(i) == true); }

    for(int i = rand_records_num * 2; i < rand_records_num * 3; i++)
    { assert(dict.is_in_dict(i) == false); }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST IS IN DICT RANDOM:" << std::endl;
    std::cout << "ALL QUERIES PASSED" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_check_value_single()
{
    Dictionary <int, std::string> dict;
    dict.add(1, "first_value");

    assert(dict.check_value(1) == "first_value");

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CHECK VALUE SINGLE:" << std::endl;
    std::cout << "assert(dict.check_value(1) == \"first_value\") : ";
    std::cout << (dict.check_value(1) == "first_value") << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_check_value_random_times()
{
    Dictionary <int, std::string> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, std::to_string(i)); }

    for(int i = 0; i < rand_records_num; i++)
    { assert(dict.check_value(i) == std::to_string(i)); }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CHECK VALUE RANDOM NUMBER OF TIMES:" << std::endl;
    std::cout << "ALL QUERIES PASSED" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_examplary_print()
{
    Dictionary <int, std::string> dict;

    for(int i = 0; i < 10; i++)
    { dict.add(i, "examplary_value-" + std::to_string(i) + "ABC"); }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST EXAMPLARY PRINT:" << std::endl;
    std::cout << dict << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_equality_operator()
{
    Dictionary <int, std::string> dict;
    Dictionary <int, std::string> dict2;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    {
        dict.add(i, std::to_string(i));
        dict2.add(i, std::to_string(i));
    }

    assert((dict == dict2) == true);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST EQUALITY OPERATOR:" << std::endl;
    std::cout << "assert((dict == dict2) == true) : ";
    std::cout << ((dict == dict2) == true) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_not_equal_operator()
{
    Dictionary <int, std::string> dict;
    Dictionary <int, std::string> dict2;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    {
        dict.add(i, std::to_string(i));
        dict2.add(i, std::to_string(i));
    }
    dict2.change(rand_records_num-1, "CHANGED");

    assert((dict != dict2) == true);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST NOT EQUAL OPERATOR:" << std::endl;
    std::cout << "assert((dict != dict2) == true) : ";
    std::cout << ((dict != dict2) == true) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_STR::test_clear()
{
    Dictionary <int, std::string> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, std::to_string(i)); }

    dict.clear();
    int expected = 0;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CLEAR:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}