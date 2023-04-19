﻿#include <iostream>
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
	void print(std::string message, bool isError = false, int newlines = 1);
	anna::flags inputCheck(std::string);
}

int main()
{
	// Create place in memory to store user input
	std::string userInput; // Store user input

	// Request and process user input
	anna::flags returnedData;
	do {
		anna::print("Please enter a number : ", false, 0);
		std::getline(std::cin, userInput);
		std::cin.clear();

		returnedData = anna::inputCheck(userInput);

	} while (!returnedData.clean); // Check if data is clean, otherwise have the user re-enter their input

	// Make use of user input data
	anna::print("Your value is : " + userInput + "\nYou had a " + ((returnedData.sign) ? "positive " : "negative ") + ((returnedData.whole) ? "integer " : "float "));

	return 0;
}

namespace anna {
	// Create function definition so it has functionality
	void print(std::string message, bool isError, int newlines) {
		if (isError) {
			message = "[ERROR] " + message + " (Please try again!)";
		} else {
			message = "[INFO] " + message;
		}
		std::cout << message;
		for (int i = 0; i < newlines; i++) {
			std::cout << std::endl;
		}
	}

	anna::flags inputCheck(std::string data) {
		anna::flags dataFlags = anna::flags{ false, true, true };
		
		if (data.length() > 0) { // Ensure input isn't empty
			if (data.length() < 10) { // Ensure input isn't too long
				if (data[0] == '-') { // Check for negative input
					if (data.length() > 0) { // Ensure there is data after the sign
						data.erase(0, 1);
						dataFlags.sign = false;
					} else {
						print("Input must contain data after sign of number", true);
						return dataFlags;
					}
				} 
				
				auto decimalSlot = data.find('.'); // Locate first decimal
				if (decimalSlot != std::string::npos) { // If decimal found, find numbers before and after 
					if (decimalSlot > 0 && decimalSlot < data.size() - 1) { // Make sure decimal isn't at end or beginning
						dataFlags.whole = false;
						data.erase(decimalSlot, 1);
					} else {
						print("Input must contain data before and after decimal sign", true);
						return dataFlags;
					}
				}
				for (auto&& pos : data) { // Scan string for decimals and numbers, fail on non decimal and numbers
					if (!std::isdigit(pos)) {
						if (std::isalpha(pos)) {
							print("Letters are not valid input", true);
							return dataFlags;
						} else {
							switch (pos)
							{
							case '.':
								print("You may only use one decimal", true);
								return dataFlags;
							case '-':
								print("You may only use one sign", true);
								return dataFlags;
							default:
								print("You may only use a sign, a decimal, and numbers", true);
								return dataFlags;
							}
						}
					}
				}

				dataFlags.clean = true;
				return dataFlags; // Data clean
			} else {
				print("Data must be no longer than 10 characters", true);
				return dataFlags;
			}
		} else {
			print("No data input", true);
			return dataFlags;
		}
	}
}

// Notes

/*
- Create print function for easy printing with optional arguments for formatting
- Add ability for program to loop, give ability to exit without killing window.
*/