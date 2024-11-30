#include "Contact.hpp"

Contact::Contact() {
	SetData("", "", "", "", "");
}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret
) {
	SetData(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

Contact::~Contact() {
}

void Contact::SetData(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

std::string Contact::GetFirstName() {
	return (this->firstName);
}

std::string Contact::GetLastName() {
	return (this->lastName);
}

std::string Contact::GetNickname() {
	return (this->nickname);
}

std::string Contact::GetPhoneNumber() {
	return (this->phoneNumber);
}

std::string Contact::GetDarkestSecret() {
	return (this->darkestSecret);
}