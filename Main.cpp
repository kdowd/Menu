#include <iostream>
#include <string>

#include <windows.h>

using namespace std;

#undef max;

void clearScreen() {
	system("cls");
}

int getChoiceByNumber();
void showMainMenu();

int getUserNumberInput(int min, int max) {
	int n;

	while (true) {

		cin >> n;

		if (cin.good() && n >= min && n <= max) {
			cout << "Nice:\n";
			cout << "Number is: " << n << "\n";
			return n;
		}
		else {
			cout << "Please try again:\n";

			while (cin.fail())
			{
				cout << "XXX" << "\n";
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}

	}

	return 0;
}



int main()
{
	getUserNumberInput(1, 3);

	std::cout << "Bye!\n";



}

void showMainMenu() {

	cout << "Choose Action\n";
	cout << "1: Login\n";
	cout << "2: Register\n";
	cout << "3: Exit\n";

	int userChoice = getChoiceByNumber();

	switch (userChoice) {
	case 1:
		//Login();
		break;
	case 2:
		//Register();
		break;
	case 3:
		cout << "EXIT" << endl;
		exit(0);

	}
}

int getChoiceByNumber() {
	string s;
	bool showMessage = false;

	while (true) {
		if (showMessage) {
			cout << "Please try again:\n";
		}
		showMessage = true;

		cin >> s;

		char theChar = static_cast<char>(s.front());
		if (cin.good() && isdigit(theChar)) {
			// convert to int
			return theChar - '0';
		}


	}

	return 0;
}
