/**
 * Name: test_int_person.cpp
 * Purpose: implementation of class Test_INT_PERSON
 * @author Mateusz Bronislaw Wasilewski
**/

#include "test_int_person.h"
#include <cassert>
#include <ctime>

void Test_INT_PERSON::test_init()
{
    Dictionary <int, Person> dict;

    int expected = 0;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST INIT:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_add_single_record()
{
    Dictionary <int, Person> dict;
    dict.add(1, Person());

    int expected = 1;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST ADD SINGLE RECORD:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_add_random_num_records()
{
    Dictionary <int, Person> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, Person()); }

    assert(dict.get_size() == rand_records_num);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST ADD RANDOM NUM RECORDS:" << std::endl;
    std::cout << "assert(dict.get_size() == rand_records_num) : ";
    std::cout << (dict.get_size() == rand_records_num) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_remove_single_record()
{
    Dictionary <int, Person> dict;

    Person p;

    dict.add(1, p);
    dict.remove(1, p);

    int expected = 0;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST REMOVE SINGLE RECORD:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_remove_random_num_records()
{
    Dictionary <int, Person> dict;;

    Person p;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, p); }

    int to_be_removed = rand() % rand_records_num;
    for(int i = 0; i < to_be_removed; i++)
    { dict.remove(i, p); }

    int expected = rand_records_num - to_be_removed;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST REMOVE RANDOM NUM RECORDS:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_change_single_value()
{
    Dictionary <int, Person> dict;
    Person p;
    dict.add(1, p);
    assert(dict.check_value(1) == p);

    Person p2(100, 200, "FNAME", "LNAME");
    dict.change(1, p2);
    assert(dict.check_value(1) == p2);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CHANGE SINGLE VALUE:" << std::endl;
    std::cout << "assert(dict.check_value(1) == p) : ";
    std::cout << (dict.check_value(1) == p) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_is_in_dict_single_time_true()
{
    Dictionary <int, Person> dict;
    dict.add(1, Person());

    assert(dict.is_in_dict(1) == true);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST IS IN DICT SINGLE TOME TRUE:" << std::endl;
    std::cout << "assert(dict.is_in_dict(1) == true) : ";
    std::cout << (dict.is_in_dict(1) == true) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_is_in_dict_single_time_false()
{
    Dictionary <int, Person> dict;
    dict.add(1, Person());

    assert(dict.is_in_dict(99) == false);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST IS IN DICT SINGLE TOME TRUE:" << std::endl;
    std::cout << "assert(dict.is_in_dict(99) == false) : ";
    std::cout << (dict.is_in_dict(99) == false) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_is_in_dict_random()
{
    Dictionary <int, Person> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, Person()); }

    for(int i = 0; i < rand_records_num; i++)
    { assert(dict.is_in_dict(i) == true); }

    for(int i = rand_records_num * 2; i < rand_records_num * 3; i++)
    { assert(dict.is_in_dict(i) == false); }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST IS IN DICT RANDOM:" << std::endl;
    std::cout << "ALL QUERIES PASSED" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_check_value_single()
{
    Dictionary <int, Person> dict;
    Person p;
    dict.add(1, p);

    assert(dict.check_value(1) == p);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CHECK VALUE SINGLE:" << std::endl;
    std::cout << "assert(dict.check_value(1) == p) : ";
    std::cout << (dict.check_value(1) == p) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_check_value_random_times()
{
    Dictionary <int, Person> dict;
    Person p;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, p); }

    for(int i = 0; i < rand_records_num; i++)
    { assert(dict.check_value(i) == p); }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CHECK VALUE RANDOM NUMBER OF TIMES:" << std::endl;
    std::cout << "ALL QUERIES PASSED" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_examplary_print()
{
    Dictionary <int, Person> dict;

    for(int i = 0; i < 10; i++)
    { dict.add(i, Person()); }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST EXAMPLARY PRINT:" << std::endl;
    std::cout << dict << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_equality_operator()
{
    Dictionary <int, Person> dict;
    Dictionary <int, Person> dict2;

    Person p;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    {
        dict.add(i, p);
        dict2.add(i, p);
    }

    assert((dict == dict2) == true);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST EQUALITY OPERATOR:" << std::endl;
    std::cout << "assert((dict == dict2) == true) : ";
    std::cout << ((dict == dict2) == true) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_not_equal_operator()
{
    Dictionary <int, Person> dict;
    Dictionary <int, Person> dict2;

    Person p;
    Person p2(100, 2, "NewFName", "NewLName");

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    {
        dict.add(i, p);
        dict2.add(i, p);
    }
    dict2.change(rand_records_num-1, p2);

    assert((dict != dict2) == true);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST NOT EQUAL OPERATOR:" << std::endl;
    std::cout << "assert((dict != dict2) == true) : ";
    std::cout << ((dict != dict2) == true) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void Test_INT_PERSON::test_clear()
{
    Dictionary <int, Person> dict;

    int rand_records_num = rand() % 1000 + 10;
    for(int i = 0; i < rand_records_num; i++)
    { dict.add(i, Person()); }

    dict.clear();
    int expected = 0;
    assert(dict.get_size() == expected);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "TEST CLEAR:" << std::endl;
    std::cout << "assert(dict.get_size() == expected) : ";
    std::cout << (dict.get_size() == expected) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}