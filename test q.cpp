#include <iostream>
#include <string>
using namespace std;

int main() {

	string input;
	int mark{}, total = 0;
	cout << "Keep entering marks\nUse \"Q\" to exit\n";
	do {
		cout << "Enter a mark: ";
		cin >> input;

		if (input == "Q")
			break;
		else {
			int mark = atoi(input.c_str());
			cout << mark << endl;
				total +=mark;
		}

	} while (true);
	cout << total << endl;
	cout << "Exit program";
	
}