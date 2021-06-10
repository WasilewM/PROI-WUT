/**
 * Name: dictionary.cpp
 * Purpose: declaration of template Dictionary<class Key, class Value>
 * @author Mateusz Bronislaw Wasilewski
**/


#pragma once
#include <utility>
#include <string>
#include <iostream>

template <class Key, class Value> class Dictionary
{
private:
    int keys_number;
    std::pair <Key, Value> *s;
public:
    // constructor for template Dictionary
    Dictionary();
    // destructor for template Dictionary
    ~Dictionary();

    // getter for keys_number
    int get_size();

    // method used for appending new record to Dictionary
    void add(Key new_key, Value new_value);

    // method used for removing record from Dictionary
    bool remove(Key del_key, Value del_value);

    // method used for changing value in record
    bool change(Key given_key, Value new_value);

    // method used to check whether the record with given_key is in Dictionary
    bool is_in_dict(Key given_key);

    // method returns the value paired with given_key
    Value check_value(Key given_key);

    // overloading operator<<
    friend std::ostream& operator<< (std::ostream &os, Dictionary<Key, Value> &d)
    {
        os << "DICTIONARY:" << std::endl;
        for(int i = 0; i < d.keys_number; i++)
        { os << "Key:" << d.s[i].first << " - Value:" << d.s[i].second << std::endl; }

        return os;
    }

    // overloading operator==
    bool operator==(Dictionary &d);

    // overloading operator!=
    bool operator!=(Dictionary &d);

    // method used for cleaning all records in Dictionary
    void clear();
};