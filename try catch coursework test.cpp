#include <iostream>
#include <string>
#include <exception>
#include<sstream>
#include<algorithm>
using namespace std;

int convert(string a);
int main() {
	int mark;
	do {
		string input;
		cout << "Enter a mark (0-100): ";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		cout << input << endl;
		try {
			if (input == "Q")
				break;
			else {
				mark = convert(input);
			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}

	} while (true);

	return 0;
}

int convert(string a) {
	int x;
	if (isdigit(a[0])) {
		stringstream ahh(a);
		ahh >> x;
		if (x < 0 || x>100)
			throw "Enter a mark in range";
	}
	else
		throw "That was not a number...";
	return x;
}