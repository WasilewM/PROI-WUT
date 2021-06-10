/**
 * Name: dictionary.cpp
 * Purpose: implementation of template Dictionary<class Key, class Value>
 * @author Mateusz Bronislaw Wasilewski
**/


#include "dictionary.h"
#include "person.h"
#include <string>

// constructor for template Dictionary
template <class Key, class Value>
Dictionary<Key, Value>::Dictionary() : keys_number(0) {}

// destructor for template Dictionary
template <class Key, class Value>
Dictionary<Key, Value>::~Dictionary()
{
    if(keys_number > 0)
    { delete [] s; }
}

// getter for keys_number
template <class Key, class Value>
int Dictionary<Key, Value>::get_size()
{ return keys_number; }

// method used for appending new record to Dictionary
template <class Key, class Value>
void Dictionary<Key, Value>::add(Key new_key, Value new_value)
{
    // checks whether the keys_number is greater then 0
    if(keys_number > 0)
    {
        //  keys_number is greater then 0

        // allocates new memory area to accomodate Dictionary with new added record
        std::pair<Key, Value> *temp = new std::pair<Key, Value>[keys_number + 1];
        // copying existing records into new memory area
        for(int i = 0; i < keys_number; i++)
        { temp[i] = s[i]; }

        // adding new record which values were given to the function
        temp[keys_number] = std::pair<Key, Value> {new_key, new_value};
        // deleting old data - free the memory
        delete [] s;
        // assignig new Dicitionary to the pointer
        s = temp;
    }
    else
    {
        // allocates new memory area to accomodate Dictionary with new added record
        s = new std::pair<Key, Value>[keys_number + 1];
        // adding new record which values were given to the function
        s[keys_number] = std::pair<Key, Value> {new_key, new_value};
    }

    // increments keys_number to properly represent Dictionary size
    keys_number++;
}

// method used for removing record from Dictionary
template <class Key, class Value>
bool Dictionary<Key, Value>::remove(Key del_key, Value del_value)
{
    // checks whether the keys_number is greater then 0
    if(keys_number > 0)
    {
        //  keys_number is greater then 0

        bool if_in_dict = false;
        // allocates new memory area to represent Dictionary with removed record
        std::pair<Key, Value> *temp = new std::pair<Key, Value>[keys_number + 1];
        int temp_idx = 0;

        // checking whether given values exist in Dictionary
        for(int i = 0; i < keys_number; i++)
        {
            if(s[i].first == del_key && s[i].second == del_value)
            { if_in_dict = true; }
            else
            {
                // copying existing records into new memory area
                // only records diffrent then given data
                temp[temp_idx] = s[i];
                temp_idx++;
            }
        }

        if(if_in_dict)
        {
            // if appropriate record was found

            // deleting old data - free the memory
            delete [] s;
            // assignig new Dicitionary to the pointer
            s = temp;
            // decrements keys_number to properly represent Dictionary size
            keys_number--;
            return true;
        }
        else
        {
            // appropriate record not found

            // free allocated memory
            delete [] temp;
            return false;
        }
    }

    return false;
}

// method used for changing value in record
template <class Key, class Value>
bool Dictionary<Key, Value>::change(Key given_key, Value new_value)
{
    // checks whether the keys_number is greater then 0
    if(keys_number > 0)
    {
        //  keys_number is greater then 0

        for(int i = 0; i < keys_number; i++)
        {
            if(s[i].first == given_key)
            {
                // given_key found, set new value
                s[i].second = new_value;
                return true;
            }
        }
    }

    // fiven_key not found
    return false;
}

// method used to check whether the record with given_key is in Dictionary
template <class Key, class Value>
bool Dictionary<Key, Value>::is_in_dict(Key given_key)
{
    // checks whether the keys_number is greater then 0
    if(keys_number > 0)
    {
        //  keys_number is greater then 0

        for(int i = 0; i < keys_number; i++)
        {
            // checks if given_key is represented in Dictionary
            // if found, returns true
            if(s[i].first == given_key)
            { return true; }
        }
    }

    // fiven_key not found
    return false;
}

// method returns the value paired with given_key
template <class Key, class Value>
Value Dictionary<Key, Value>::check_value(Key given_key)
{
    for(int i = 0; i < keys_number; i++)
    {
        // checks if given_key is represented in Dictionary
        // if found, returns its value
        if(s[i].first == given_key)
        { return s[i].second; }
    }

    // given_key not found, reutrn first value from the Dictionary
    return s[0].second;
}

// overloading operator<<
template <class Key, class Value>
bool Dictionary<Key, Value>::operator==(Dictionary &d)
{
    // checks whether 2 Dictionaries are equal
    // checks all fields of the Dictionaries

    if(this->keys_number == d.keys_number)
    {
        for(int i = 0; i < d.keys_number; i++)
        {
            if(this->s[i].first == d.s[i].first &&
            this->s[i].second == d.s[i].second)
            { continue; }
            else
            { return false; }
        }
        return true;
    }
    return false;
}

// overloading operator!=
template <class Key, class Value>
bool Dictionary<Key, Value>::operator!=(Dictionary &d)
{
    // checks whether 2 Dictionaries are different
    // checks all fields of the Dictionaries

    if(this->keys_number == d.keys_number)
    {
        for(int i = 0; i < d.keys_number; i++)
        {
            if(this->s[i].first != d.s[i].first ||
            this->s[i].second != d.s[i].second)
            { return true; }
        }
        return false;
    }
    return true;
}

// method used for cleaning all records in Dictionary
template <class Key, class Value>
void Dictionary<Key, Value>::clear()
{
    // free allocated memory
    delete [] s;
    // decrements keys_number to properly represent Dictionary size
    keys_number = 0;
}

template class Dictionary<int, std::string>;
template class Dictionary<int, char>;
template class Dictionary<int, Person>;