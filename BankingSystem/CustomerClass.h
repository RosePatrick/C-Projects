#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Customer {
private:
	std::string Surname;
	std::string FirstName;
	//std::string CustType;
	std::string Address;
	std::string BirthDate;
	std::string PhoneNumber;
	std::string AcctType;
	int AcctNumber;
	double AcctBalance;

public:
	void SetCustomer(std::string, std::string, /*std::string,*/ std::string, std::string, std::string, std::string, int, double);
	double GetBalance();
	void Withdrawal(double);
	void Deposit(double);
};

void Customer::SetCustomer(std::string lname, std::string fname, /*std::string Type,*/ std::string address, std::string birthdate, std::string phone, std::string actype, int acnum, double balance) {
	Surname = lname;
	FirstName = fname;
	//CustType = Type;
	Address = address;
	BirthDate = birthdate;
	PhoneNumber = phone;
	AcctType = actype;
	AcctNumber = acnum;
	AcctBalance = balance;

}

double Customer::GetBalance() {
	return AcctBalance;
}
void Customer::Withdrawal(double amount) {
	if (amount > AcctBalance) {
		std::cout << "Insufficient Funds" << std::endl;
	}
	else {
		AcctBalance = AcctBalance - amount;
		std::cout << "Your new balance is $" << std::fixed << std::setprecision(2) << AcctBalance << std::endl;
	}
}
void Customer::Deposit(double amount) {
	AcctBalance = AcctBalance + amount;
	std::cout << "Your new balance is $" << std::fixed << std::setprecision(2) << AcctBalance << std::endl;
}