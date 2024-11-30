#include "PhoneBook.hpp"
#include <iostream>

void PhoneBook::displayAllContacts() {
	std::cout << "Contact List" << std::endl;
	for (int i = 0; i < this->contactNum; i++) {
		std::cout << std::setw(10) << i << "|";
		formatAndPrint(this->contacts[i].GetFirstName());
		std::cout << "|";
		formatAndPrint(this->contacts[i].GetLastName());
		std::cout << "|";
		formatAndPrint(this->contacts[i].GetNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::displayContact(int index) {
	if (index < 0 || index >= this->contactNum) {
		std::cout << "Out of range!" << std::endl;
	} else {
		std::cout << "First name : " << this->contacts[index].GetFirstName() << std::endl;
		std::cout << "Last name : " << this->contacts[index].GetLastName() << std::endl;
		std::cout << "Nickname : " << this->contacts[index].GetNickname() << std::endl;
		std::cout << "Phone number : " << this->contacts[index].GetPhoneNumber() << std::endl;
		std::cout << "Darkest secret : " << this->contacts[index].GetDarkestSecret() << std::endl;
	}
}

void PhoneBook::formatAndPrint(std::string input) {
	if (input.length() <= 10) {
		std::cout << std::setw(10) << input;
	} else {
		std::string trimmed = input.substr(0, 9) + ".";
		std::cout << trimmed;
	}
}

PhoneBook::PhoneBook() {
	this->index = 0;
	this->contactNum = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::AddContact() {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Please enter your first name." << std::endl;
	std::cin >> firstName;
	std::cout << "Please enter your last name." << std::endl;
	std::cin >> lastName;
	std::cout << "Please enter your nickname." << std::endl;
	std::cin >> nickname;
	std::cout << "Please enter your phone number." << std::endl;
	std::cin >> phoneNumber;
	std::cout << "Please enter your darkest secret." << std::endl;
	std::cin >> darkestSecret;

	this->contacts[this->index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->index = (this->index + 1) % 8;
	if (this->contactNum != 8)
		this->contactNum++;
	std::cout << std::endl;
}

void PhoneBook::SearchContact() {
	int index;

	displayAllContacts();
	std::cout << "Enter the index you are looking for." << std::endl;
	std::cin >> index;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input." << std::endl << std::endl;
		return ;
	}
	displayContact(index);
	std::cout << std::endl;
}