#ifdef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	Contact(
		std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string darkestSecret
	);
	~Contact();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickname();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
};

#endif