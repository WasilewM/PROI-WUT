#include <iostream>
#include "train.h"

int main()
{
    Train t1(10, 100);
    for(int i = 0; i < 500; ++i)
    { t1.add_new_passenger(); }
    t1.add_wagons(1);
    t1.remove_wagons(2);
    t1.get_train_state(t1);
    return 0;
}