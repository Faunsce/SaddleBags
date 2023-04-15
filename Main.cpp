#include <iostream>
#include <string>

// Use a custom namespace for personally created functions
namespace anna {
	// Declare types
	struct flags
	{
		bool clean; 
		bool sign; // The "Polarity" so to speak, of the value
		bool whole; // If the number is "whole" aka float vs int
		
	};
	// Declare function for testing input
	anna::flags inputCheck(std::string);
}

int main()
{
	// Create place in memory to store user input
	std::string userInput; // Store user input

	// Request and process user input
	anna::flags returnedData;
	do {
		std::cout << "Please enter a number : ";
		std::getline(std::cin, userInput);
		std::cin.clear();

		returnedData = anna::inputCheck(userInput);

	} while (!returnedData.clean); // Check if data is clean, otherwise have the user re-enter their input

	// Make use of user input data
	std::cout << "Your value is : " << userInput << std::endl
		<< "You had a " << ((returnedData.sign) ? "positive " : "negative ") << ((returnedData.whole) ? "integer " : "float ");

	return 0;
}

namespace anna {
	// Create function definition so it has functionality
	anna::flags inputCheck(std::string data) {
		anna::flags dataFlags = anna::flags{ false, true, true };
		
		if (data.length() > 0) { // Ensure input isn't empty
			if (data.length() < 10) { // Ensure input isn't too long
				if (data[0] == '-') { // Check for negative input
					if (data.length() > 1 && (data[1] > '0' && data[1] < '9')) { // Ensure there is data after the sign
						data.erase(0, 1);
						dataFlags.sign = false;
					} else {
						std::cout << "Input must contain data after sign of number" << std::endl;
						return dataFlags;
					}
				} 
				for (auto&& pos : data) { // Scan string for decimals and numbers, fail on non decimal and numbers
					if (pos == '.') {
						if (dataFlags.whole == true) {
							dataFlags.whole = false;
							continue; // Keep num check from failing first decimal
						} else {
							std::cout << "Input may not have more than one decimal indicator, please try again!" << std::endl;
							return dataFlags;
						}
					} else {
						if (!(pos > '0' && pos < '9')) {
							std::cout << "Only numbers, decimals, and a sign indicator are allowed, please try again!" << std::endl;
							return dataFlags;
						} 
					}
				}
				dataFlags.clean = true;
				return dataFlags; // Data clean
			} else {
				std::cout << "Data must be no longer than 10 characters, please try again!" << std::endl;
				return dataFlags;
			}
		} else {
			std::cout << "No data input, please try again!" << std::endl;
			return dataFlags;
		}
	}
}

// Notes

/*
- Add the ability to input a float and report if the number is a float vs int and pos vs neg
- Create print function for easy printing with optional arguments for formatting
- Add ability for program to loop, give ability to exit without killing window.
*/