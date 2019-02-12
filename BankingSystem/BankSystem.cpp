/*
Author: Rose-Marie Patrick
Date: 29-Nov-18

This program is for a simplified banking system, where the user can enter new customer details, 
deposit or withdraw money or check the current balance of an account.
No error checking for user entries was implemented.

Menu options
1. Set up new Customer profile
2. Check Balance
3. Cash Withdrawal
4. Cash Deposit
5. Exit

A map is used to store customer data - this has some drawbacks when it comes to storing large amounts of data
Account Number will be the key
Functions
- Print Menu and take input
- New profile - input new customer data when prompted
- Check Balance - input bank account number
- Withdrawal - input bank account and amount to be withdrawn
- Deposit - input bank account number and amount deposited

Future Work
- Inclusion of credit card and loan info
- Error checking user entry and maintenance of format
- Use of external file for storage of accounts information
*/

#include "stdafx.h"
#include "CustomerClass.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_map>

int PrintMenu();
Customer NewProfile(int acctNum);

int main()
{
	int menuChoice, cust_acctnum;
	Customer cust, bank_record;
	double bank_balance, amount;
	std::unordered_map<int, Customer> dataBase;			//Customer database represented using an unordered map 
	std::cout << "Welcome to Imperial Banking!\n";
	do {
		menuChoice = PrintMenu();
		switch (menuChoice) {
		case 1:
			cust_acctnum = rand() % 100000 + 10000;		//flawed determination of unique 5-digit bank numbers; alternatively, user can enter bank acct number
			bank_record = NewProfile(cust_acctnum);
			dataBase.insert({ cust_acctnum, bank_record });
			break;
		case 2:
			std::cout << "Please enter the account number: ";
			std::cin >> cust_acctnum;
			bank_record = dataBase[cust_acctnum];							//search database for matching cust object
			bank_balance = bank_record.GetBalance();
			std::cout << "Your account balance is $" << std::fixed << std::setprecision(2) << bank_balance << std::endl;
			break;
		case 3:
			std::cout << "Please enter the account number: ";
			std::cin >> cust_acctnum;
			std::cout << "Please enter the amount to withdraw: ";
			std::cin >> amount;
			bank_record = dataBase[cust_acctnum];
			bank_record.Withdrawal(amount);
			dataBase[cust_acctnum] = bank_record; //save the updated balance
			break;
		case 4:
			std::cout << "Please enter the account number: ";
			std::cin >> cust_acctnum;
			std::cout << "Please enter the amount to deposit: ";
			std::cin >> amount;
			bank_record = dataBase[cust_acctnum];
			bank_record.Deposit(amount); 
			dataBase[cust_acctnum] = bank_record; //save the updated balance
			break;
		case 5:
			std::cout << "\n*******************************************************************************\n";
			std::cout << "********** Thank you for using the Imperial Banking System. Goodbye. **********\n";
			std::cout << "*******************************************************************************\n";
			return 0;
		default:
			std::cout << "Invalid Menu Option!" << std::endl;
		}
	} while (1);
    return 0;
}

int PrintMenu() {
	int choice;

	//print the menu
	std::cout << "\nPlease select a menu option.\n";
	std::cout << "1. Set up new account\n" << "2. Check Balance\n" << "3. Cash Withdrawal\n" << "4. Cash Deposit\n" << "5. Exit\n";
	std::cout << "Please enter your menu choice (1-5):";

	//get user input and error check
	std::cin >> choice;
	while ((choice < 1) || (choice > 5)) {
		std::cout << "Invalid Input. Please enter a number from 1 to 5: ";
		std::cin >> choice;
	}
	return choice;
}

//Prompt user for relevant information to open an account
Customer NewProfile(int acctNum) {
	std::string lastName, firstName, Addr, bDay, phone, accType;
	Customer cust;
	double acctBal;
	std::cout << "New Customer Profile. Please enter the following data:\n";
	std::cout << "Last Name: ";
	std::cin >> lastName;
	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "Customer Address: ";
	std::cin >> Addr;
	std::cout << "Date of Birth (DD-MM-YYYY): ";
	std::cin >> bDay;
	std::cout << "Phone Number: ";
	std::cin >> phone;
	std::cout << "Account Type - Savings or Checking: ";
	std::cin >> accType;
	std::cout << "Cash amount to be deposited: ";
	std::cin >> acctBal;
	
	cust.SetCustomer(lastName, firstName, Addr, bDay, phone, accType, acctNum, acctBal); //initialize new customer object

	std::cout << "Success! The " << accType << " account for " << firstName << " " << lastName << " has been created.\n";
	std::cout << "The new account number is: " << acctNum << std::endl;
	return cust;
}



