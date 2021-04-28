//Tracks the amount of water consumed in a given session
//Ian Zimmerman
//April 28, 2021

#include <iostream>
#include <fstream>
#include <string>
#include "tracker.hpp"
//#include "log.txt"

using std::cout; using std::cin; using std::endl;
using std::string; using std::ifstream; using std::ofstream;

int main() {
	double input = 0.0; //amount of water drank
	char choice = 'd'; //chooses by count or by volume
	double totalVolume = 0.0;
	string temp = "0.0"; //takes input from log

	//opens and reads from log.txt
	ifstream log1;
	log1.open("log.txt");

	getline(log1, temp);
	input = stod(temp);
	totalVolume = input;

	//closes log and reopens for writing
	log1.close();
	ofstream log2;
	log2.open("log.txt");

	//takes user input
	std::cout << "How would you like to enter your water consumption?" << endl;
	std::cout << "By bottle count (b) or by volume (v)" << endl;
	std::cin >> choice;

	//adds water
	switch (choice) {
		case 'b':
			std::cout << "How many bottles would you like to add?" << endl;
			std::cin >> input;

			for (double i = 0.0; i < input; ++i)
				totalVolume = addBottle(totalVolume);
			break;
		case 'v':
			std::cout << "How much water would you like to add? (fl oz.)" << endl;
			std::cin >> input;

			totalVolume = addVol(totalVolume, input);
			break;
		default:
			std::cout << "Please enter a valid input method." << endl;
			break;
	}

	//displays and updates the total volume
	std::cout << "You have consumed " << totalVolume << " fl oz. of water" << endl;
	log2 << totalVolume;

	log2.close();

	return 0;
}
