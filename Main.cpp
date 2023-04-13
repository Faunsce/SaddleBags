#include <iostream>
#include <string>

// Use a custom namespace for personally created functions
namespace anna {
	// Declare function for testing input
	void testFunc(int);
	bool integerCheck(std::string);
}

int main()
{
	// Create place in memory to store user input
	long int num = 0; // 8 bit Integer
	std::pair<std::string, bool> userInput{"", false}; // Store data alongside a "clean" check

	// Request and process user input
	do {
		std::cout << "Please enter a number : ";
		std::getline(std::cin, userInput.first);
		std::cin.clear();

		userInput.second = true;
		
		if (userInput.first.empty()) { // Check if the input had any data
			std::cout << "No data input";
			userInput.second = false;
		} else if (userInput.first.length() > 10) { // Check that the input is no less than 10 digits
			std::cout << "Number must be smaller than digits in length";
			userInput.second = false;
		} else if (!anna::integerCheck(userInput.first)) { //  Check that the input is an integer
			std::cout << "Input must be an integer";
			userInput.second = false;
		}

		if (!userInput.second) { // If data is unclean, finish warn and then try again
			std::cout << ", please try again." << std::endl << std::endl;
		} else {
			std::cout << "Input accepted!" << std::endl;
			num = std::stoi(userInput.first);
		}

	} while (!userInput.second); // Check if data is clean, otherwise have the user re-enter their input

	// Make use of user input data
	anna::testFunc(num);

	return 0;
}

namespace anna {
	// Create function definition so it has functionality
	void testFunc(int num) {
		std::cout << "The number you input was : " << num << std::endl;
	}

	bool integerCheck(std::string data) {
		if (data[0] == '-') {
			if (data.length() > 1) {
				data = data.erase(0, 1);
			} else {
				return false;
			}
		}
		for (auto&& slot : data) {
			if (!(slot >= '0' && slot <= '9')) {
				return false; // Data unclean
			}
		}
		return true; // Data clean
	}
}

// Notes

/*
- Add the ability to capture negative values
- Add the ability to input a float and report if the number is a float vs int and pos vs neg
- Create print function for easy printing with optional arguments for formatting
*/