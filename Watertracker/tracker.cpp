//functions used to track water consumption
//Ian Zimmerman
//April 28, 2021

#include <iostream>
#include "tracker.hpp"
//#include "log.txt"

using std::cout; using std::cin; using std::endl;
using std::string; using std::ifstream; using std::ofstream;

//adds the volume of a 16.9 fl oz water bottle
double addBottle(double total) {
	const double bottle = 16.9; //bottle size
	total = total + bottle;
	return total;
}

//adds a given volume to the total
double addVol(double total, double vol) {
	total = total + vol;
	return total;
}
