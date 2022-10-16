#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

void addTransact();
void menu();

void exit()
{
	cout << "\n\nThank you for Banking with Us. Have a nice day.\n\n";
}

int balance = 1000;

void menu()
{
	int choice;
	int with_amount, w = 1;
	int dep_amount, s = 1;
	cout << "\n\n********************\n";
	cout << "Welcome to BIBE Bank\n";
	cout << "=====================\n";
	cout << "Press [1] for Balance Inquiry\n";
	cout << "Press [2] for Withdrawal Transactions\n";
	cout << "Press [3] for Deposit Transactions\n";
	cout << "Press [0] for Exit\n\n";

	cout << "Enter Transaction: ";
	cin >> choice;

	switch (choice) {

	case 1:

		cout << "\nThe Current Balance is Php " << balance;
		addTransact();
		break;

	case 2:


		do {
			cout << "\nEnter the amount to be withdrawn: ";
			cin >> with_amount;
			w++;
			int show = w - 1;

			if (with_amount < 100)
			{
				cout << "Sorry the amount should be divisible by 100 and not lower than 100.\n\n";
				cout << show << " out of 5 tries \n\n";

			}
			else if (with_amount % 100 != 0)
			{
				cout << "Sorry the amount should be divisible by 100\n";
				cout << show << " out of 5 tries \n\n";

			}
			else if (balance == 0 || with_amount > balance)
			{
				cout << "Sorry the amount should be within your current balance.\n";
				cout << show << " out of 5 tries \n\n";
			}
			else
			{
				cout << "\nTransaction completed!\n";
				balance = balance - with_amount;
				addTransact();
				break;
			}
		} while (w <= 5);

		if (w > 5)
		{
			cout << "\n\nExceed Limit!"; menu();
		}

		break;

	case 3:

		cout << "\nThis machine accept bills only.\n\n";
		do
		{
			cout << "\nEnter Deposit Amount: Php ";
			cin >> dep_amount;
			s++;
			int show = s - 1;
			if ((dep_amount % 20 != 0) && (dep_amount % 50 != 0) && (dep_amount % 100 != 0) && (dep_amount % 200 != 0) && (dep_amount % 500 != 0) && (dep_amount % 1000 != 0))
			{
				cout << "\nSorry but this machine accepts BILLS ONLY!\n";
				cout << show << " out of 5 tries \n\n";
			}
			else if (dep_amount < 100)
			{
				cout << "Sorry the amount should be divisible by 100 and not lower than 100.\n";
				cout << show << " out of 5 tries \n\n";
			}
			else if (dep_amount % 100 != 0)
			{
				cout << "Sorry the amount should be divisible by 100\n";
				cout << show << " out of 5 tries \n\n";
			}
			else
			{
				balance = balance + dep_amount;
				cout << "\nTransaction Complete!\n";
				addTransact();
				break;
			}
		} while (s <= 5);

		if (s > 5)
		{
			cout << "\n\nExceed Limit!"; menu();
		}
		break;

	case 0:

		exit();
		break;

	default:
		cout << "\n-Invalid Input-\n";
		menu();
		break;

	}
}

void addTransact()
{
	char add_transaction1;
	cout << "\n\nDo you want another transaction?[y/n]\t";
	cin >> add_transaction1;
	if (add_transaction1 == 'y' || add_transaction1 == 'Y') { menu(); }
	else if (add_transaction1 == 'n' || add_transaction1 == 'N') { exit(); }
	else { cout << "\n-Invalid Input-\n"; menu(); }
}

int main() {
	int i = 0, len = 0;
	string pinNum;
	string pins[] = { "1111","2222", "3333", "4444" };
	bool pinMatched = false;


	len = pins->length() - 1;

	while (pinMatched == false && i <= 2)
	{
		cout << "\nEnter PIN number: ";
		cin >> pinNum;

		for (int x = 0; x <= len; x++)
		{
			if (pins[x] == pinNum)
			{
				pinMatched = true;
				menu();
			}
		}

		if (pinMatched == false);
		{
			cout << "\nInvalid PIN\n";
			i++;
		}
	}

	if (i > 2)
	{
		cout << "\nMaximum tries reached!\n";
		exit();
	}
	system("pause");
}
