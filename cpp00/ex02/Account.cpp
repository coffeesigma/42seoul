#include "Account.hpp"
#include <iostream>

void Account::_displayTimestamp( void ) {
	time_t ts;
	char format[16];

	time(&ts);
	strftime(format, sizeof(format), "%Y%m%d_%H%M%S", localtime(&ts));
	std::cout << "[" << format << "] ";
}

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "amount: " << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "amount: " << _amount << ";";
	std::cout << "closed" << std::endl;
}

