#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook phoneBook = PhoneBook();

	std::cout << "Welcome to the phone book!" << std::endl;
	while (true) {
		std::string input;

		if (std::cin.eof()) {
			break ;
		}
		std::cout << "Select Option (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> input;
		if (input == "ADD") {
			phoneBook.AddContact();
		} else if (input == "SEARCH") {
			phoneBook.SearchContact();
		} else if (input == "EXIT" || std::cin.eof()) {
			break ;
		} else {
			std::cout << "Invalid option." << std::endl;
		}
	}
}