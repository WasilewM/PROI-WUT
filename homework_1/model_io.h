/**
 * Name: model_io.h
 * Purpose: declaration of io functions
 * @author Mateusz Wasilewski
*/

#ifndef MODEL_IO_H
#define MODEL_IO_H
#include <string>

// fucntion reads the data given by the user
std::string read_data();

// fucntions greets the user when it is called
void greet_user();

// functions displays the stats after successfully completed calculations
void show_stats(double max_value, double min_value, double avg_value);

// fucntions informs the user that some of the data were invalid and due to this reason
// calculations cannot be made
void show_error_msg();

// informs the user that no data was entered
void no_input_data_msg();

#endif