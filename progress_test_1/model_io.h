#ifndef MODEL_IO_H
#define MODEL_IO_H
#include <string>

void ask_for_force();

void ask_for_distance();

std::string read_data();

void show_error_msg();

void display_result(double F, double s);

#endif