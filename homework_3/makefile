test_plane: check_data.o class_test.o convert_str_to_int.o crew.o main.o model_io.o passenger.o person.o plane.o
	g++ check_data.o class_test.o convert_str_to_int.o crew.o main.o model_io.o passenger.o person.o plane.o -o test_plane

check_data.o: check_data.cpp
	g++ -c check_data.cpp

class_test.o: class_test.cpp
	g++ -c class_test.cpp

convert_str_to_int.o: convert_str_to_int.cpp
	g++ -c convert_str_to_int.cpp

crew.o: crew.cpp
	g++ -c crew.cpp

main.o: main.cpp
	g++ -c main.cpp

model_io.o: model_io.cpp
	g++ -c model_io.cpp

passenger.o: passenger.cpp
	g++ -c passenger.cpp

person.o: person.cpp
	g++ -c person.cpp

plane.o: plane.cpp
	g++ -c plane.cpp

clean:
	rm *.o test_plane