#include <iostream>
using namespace std;

int main() {
	//initalise varibles for counting marks in each category
	int cat1Count=0, cat2Count=0, cat3Count=0, cat4Count=0,ovCount ,mark ;
	//creates array for storing each mark
	int foo[4][5];

	//loop that allows user to keep inputting mark untill sential is inputted (>100)
	do {
		cout << "Please enter student mark: ";
		cin >> mark;
		//if mark in this range stores in first row of array
		//incriments counter by one for every mark in range inputteed
		if (mark >= 0 && mark <= 29) {
			foo[0][cat1Count] = mark;
			cat1Count++;
		}
		//if mark in this range stores in second row of array
		//incriments counter by one for every mark in range inputteed
		else if (mark >= 30 && mark <= 39) {
			foo[1][cat2Count] = mark;
			cat2Count++;
		}
		//if mark in this range stores in third row of array
		//incriments counter by one for every mark in range inputteed
		else if (mark >= 40 && mark <= 69) {
			foo[2][cat3Count] = mark;
			cat3Count++;
		}
		//if mark in this range stores in fourth row of array
		//incriments counter by one for every mark in range inputteed
		else if (mark >= 70 && mark <= 100) {
			foo[3][cat4Count] = mark;
			cat4Count++;
		}
		//breaks loop incase negative number is inputted
		else break;

		//temp code
		//if inputs fails set each value to 0 and display error
		if (cin.fail()) {
			cin.clear();
			cout << "Input error";
			cat1Count = 0, cat2Count = 0, cat3Count = 0, cat4Count = 0;
			break;
		}

	} while (mark <= 100);
	//adds each count for overal marks inputted
	ovCount = cat1Count + cat1Count + cat3Count + cat4Count;
	//display only
	cout << "\n-----------------------------------\n" << endl;
	//loops that prints "*" to the screen for how many times the count value
	cout << "\t0-29\t";
	for (int i = 0; i < cat1Count; i++)cout << "*";
	//loops that prints "*" to the screen for how many times the count value
	cout << "\n\t30-39\t";
	for (int i = 0; i < cat2Count; i++)cout << "*";
	//loops that prints "*" to the screen for how many times the count value
	cout << "\n\t40-69\t";
	for (int i = 0; i < cat3Count; i++)cout << "*";
	//loops that prints "*" to the screen for how many times the count value
	cout << "\n\t30-39\t";
	for (int i = 0; i < cat4Count; i++)cout << "*";
	//display only
	cout << "\n\n-----------------------------------" << endl;
	//prints how mnay student marks entered 
	cout << "\nTotal marks counted: " << ovCount << endl;





}