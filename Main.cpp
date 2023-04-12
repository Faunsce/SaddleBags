#include <iostream>

// Use a custom namespace for personally created functions
namespace anna {
	// Declare function for testing input
	void testFunc(int);
}

int main()
{
	// Create place in memory to store user input
	int num;

	// Request and process user input
	std::cout << "Please enter a number : ";
	std::cin >> num;
	std::cout << std::endl;

	// Make use of user input data
	anna::testFunc(num);

	return 0;
}

namespace anna {
	// Create function definition so it has functionality
	void testFunc(int num) {
		std::cout << "The number you input was : " << num << std::endl;
	}
}