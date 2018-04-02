#include "Array.h"
#include <iostream>

int main() {
	Array arr1(5,4);

	//test arr1 copy to arr2
	Array arr2(arr1);
	std::cout << arr2 << std::endl;

	//test equality and inequality
	std::cout << (arr1 == arr2) << std::endl;
	std::cout << (arr1 != arr2) << std::endl;

	arr2.resize(arr2.length() + 1);

	//test exception with different sizes
	try {
		arr1 == arr2;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	//test arr1 < arr2
	std::cout << (arr1 < arr2) << std::endl;

	//test arr1 + arr2
	std::cout << (arr1 + arr2) << std::endl;

	system("pause");
}