#include<iostream>
#include<string>

using namespace std;

int main() {
	int mark;
	string catOne = "0-29", catTwo = "30-39", catThree = "40-69", catFour = "70-100";
	int cat1 = 0, cat2 = 0, cat3 = 0, cat4 = 0;
	do {
		
		cout << "Enter student mark: ";
		cin >> mark;
		//checks what if mark is between values and adds up counter
		if (mark >= 0 && mark <= 29)cat1++;
		else if (mark >= 30 && mark <= 39)cat2++;
		else if (mark >= 40 && mark <= 69)cat3++;
		else if (mark >= 70 && mark <= 100)cat4++;
		
		if (cin.fail()) {
			cin.clear();
			exit(0);
		}

	} while (mark <101);
	int students = cat1 + cat2 + cat3 + cat4;
		
	//histogram
	cout << "\n\t*************" << endl;
	cout <<"\n\t"<< catOne<<"     ";
	for (int x = 1; x <= cat1; x++)cout << "*";
	cout << "\n\t" << catTwo << "    ";
	for (int x = 1; x <= cat2; x++)cout << "*";
	cout << "\n\t" << catThree << "    ";
	for (int x = 1; x <= cat3; x++)cout << "*";
	cout << "\n\t" << catFour << "   ";
	for (int x = 1; x <= cat2; x++)cout << "*";
	cout << "\n\t*************" << endl;

	cout << "\n" << students << " students in total" << endl;

	return 0;
}