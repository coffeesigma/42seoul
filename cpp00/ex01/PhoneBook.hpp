#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int index;
	int contactNum;

	void displayAllContacts();
	void displayContact(int index);
	void formatAndPrint(std::string input);

public:
	PhoneBook();
	~PhoneBook();
	void AddContact();
	void SearchContact();
};

#endif