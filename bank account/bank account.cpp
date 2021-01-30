/*Abstract and interface accounts form the hidden base from which a 
lot of 'include'd code inherits. I am currently working with wxWidgets 
and it made me think I need to understand the polymorphic process at this 
root. To do so, I have created an interface class bank account, and 
inherited from it to form a savings account and a current account. 
This could, of course, be improved on. 
1) The interface doesn't do anything, or add much to the hierachy.
2) A non-numeric input causes the while loop to continue past future inputs.
3) Although a return code of 1 is used, there's no exceptions structure.
If you can think of other improvements, or just improve this code, please show me how.*/


#include <iostream>
#include <string>



class bankAccount {

private:

public:
	virtual ~bankAccount() {};
	virtual int accessBalance() = 0;
	virtual int withdrawel() = 0;


};


class savingsAccount : public bankAccount {

private:

	double _balance;
	int _pin;

public:

	savingsAccount(double balance, int pin) : _balance(balance), _pin(pin) {};
	~savingsAccount() {};
	double getBalance() { return _balance; }
	int getPin() { return _pin; }

	virtual int accessBalance() {
		int pin = 0;
		int pin_attempt = 0;
		std::cout << "Hi, this is your savings account. For your balance, please input your pin: " << std::endl;
		std::cin >> pin;
		//the input loops until the correct pin is entered. If three incorrect pins are entered, the program exits.
		while (pin != getPin()) {
			++pin_attempt;
			if (pin_attempt == 3) {
				std::cout << "Sorry. You have entered too many pins. Your card has, I'm afraid, been removed from you." << std::endl;
				return 1;
			}
			std::cout << "Sorry, wrong pin. Try again." << std::endl;
			std::cin >> pin;
		}
		std::cout << "Your balance is: " << getBalance() << "." << std::endl;
		return 0;
	}

	virtual int withdrawel() {
		int pin = 0;
		int pin_attempt = 0;
		std::cout << "Hi, this is your savings account. For a withdrawel, please input your pin: " << std::endl;
		std::cin >> pin;
		//the input loops until the correct pin is entered. If three incorrect pins are entered, the program exits.
		while (pin != getPin()) {
			++pin_attempt;
			if (pin_attempt == 3) {
				std::cout << "Sorry. You have entered too many pins. Your card has, I'm afraid, been removed from you." << std::endl;
				return 1;
			}
			std::cout << "Sorry, wrong pin. Try again." << std::endl;
			std::cin >> pin;
		}
		double amount = 0.0;
		double new_balance = 0.0;
		std::cout << "Please note - there is a 5 percent penalty on withdrawels from this type of account. How much do you want to withdraw?" << std::endl;
		std::cin >> amount;
		new_balance = getBalance() - amount * 1.05;
		std::cout << "There you go! Your new balance is: " << new_balance << "." << std::endl;
		return 0;

	}
};

class currentAccount : public bankAccount {

private:

	double _balance;
	int _pin;

public:

	currentAccount(double balance, int pin) : _balance(balance), _pin(pin) {};
	~currentAccount(){};
	double getBalance() { return _balance; }
	int getPin() { return _pin; }

	virtual int accessBalance() {
		int pin = 0;
		int pin_attempt = 0;
		std::cout << "Hi, this is your current account. For your balance, please input your pin: " << std::endl;
		std::cin >> pin;
		//the input loops until the correct pin is entered. If three incorrect pins are entered, the program exits.
		while (pin != getPin()) {
			++ pin_attempt;
			if (pin_attempt == 3) {
				std::cout << "Sorry. You have entered too many pins. Your card has, I'm afraid, been removed from you." << std:: endl;
				return 1;
			}
			std::cout << "Sorry, wrong pin. Try again." << std::endl;
			std::cin >> pin;
		}
		std::cout << "Your balance is: " << getBalance() << "." << std::endl;
		return 0;
	}


	virtual int withdrawel() {
		int pin = 0;
		int pin_attempt = 0;
		std::cout << "Hi, this is your current account. For a withdrawel, please input your pin: " << std::endl;
		std::cin >> pin;
		//the input loops until the correct pin is entered. If three incorrect pins are entered, the program exits.
		while (pin != getPin()) {
			++pin_attempt;
			if (pin_attempt == 3) {
				std::cout << "Sorry. You have entered too many pins. Your card has, I'm afraid, been removed from you." << std::endl;
				return 1;
			}
			std::cout << "Sorry, wrong pin. Try again." << std::endl;
			std::cin >> pin;
		}
		double amount = 0.0;
		double new_balance = 0.0;
		std::cout << "How much do you want to withdraw?" << std::endl;
		std::cin >> amount;
		new_balance = getBalance() - amount;
		std::cout << "There you go! Your new balance is: " << new_balance << "." << std::endl;
		return 0;
	}
};


int main() {
	savingsAccount SavingsAccount{ 347.09, 6777 };
	SavingsAccount.accessBalance();
	SavingsAccount.withdrawel();
	currentAccount CurrentAccount{ 2456.78, 5678 };
	CurrentAccount.accessBalance();
	CurrentAccount.withdrawel();







}