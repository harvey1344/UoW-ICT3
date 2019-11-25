#include <iostream>
using namespace std;

int main() {
	//initalise varibles for counting marks in each category
	int cat1Count = 0, cat2Count = 0, cat3Count = 0, cat4Count = 0, ovCount, mark, pass=0,i;
	//creates array for storing each mark
	int foo[4][5];

	//This block of codes allows user to input marks untill mark is above 100
	//Each if statements measures if mark is in the set category and stores it in the array
	//Each time a mark is entered, the counter for that caterogy is incrimented 
	do {
		cout << "Please enter student mark: ";
		cin >> mark;
		if (mark >= 0 && mark <= 29) {
			foo[0][cat1Count] = mark;
			cat1Count++;
		}
		else if (mark >= 30 && mark <= 39) {
			foo[1][cat2Count] = mark;
			cat2Count++;
		}
		else if (mark >= 40 && mark <= 69) {
			foo[2][cat3Count] = mark;
			cat3Count++;
		}
		else if (mark >= 70 && mark <= 100) {
			foo[3][cat4Count] = mark;
			cat4Count++;
		}
		//breaks loop incase negative number is inputted
		else break;

		if (mark >= 40) pass++;
		//temp code
		//if inputs fails set each value to 0 and display error
		if (cin.fail()) {
			cin.clear();
			cat1Count -= 1;//some reason cat1Count is getting incrimented when this block is executed 
			cout << "Input error";
			break;
			
		}

	} while (mark <= 100);

	
	ovCount = cat1Count + cat2Count + cat3Count + cat4Count; //adds each count for overal marks inputted

	//This block of codes creates a histogram using for loops to print an asterisk for how many times a mark in catergory is entered 
	cout << "\n-----------------------------------\n" << endl;
	cout << "\t0-29\t";
	for (i = 0; i < cat1Count; i++)cout << "*";
	cout << "\n\t30-39\t";
	for (i = 0; i < cat2Count; i++)cout << "*";
	cout << "\n\t40-69\t";
	for (i = 0; i < cat3Count; i++)cout << "*";
	cout << "\n\t30-39\t";
	for (i = 0; i < cat4Count; i++)cout << "*";
	cout << "\n\n-----------------------------------" << endl;
	
	//This code block uses a for loop to add the values stored in the array untill the counter reaches the max value
	//It uses a running counter to add up every mark in each row of the array
	//Then divides by overall counter to caluclate average mark
	//If statements make sure average value doesnt error
	double runCount = 0;
	double average;
	if (cat1Count>0) for (i = 0; i < cat1Count; i++) runCount += foo[0][i];
	if (cat2Count > 0) for (i = 0; i < cat2Count; i++) runCount += foo[1][i];
	if (cat3Count > 0) for (i = 0; i < cat2Count; i++) runCount += foo[2][i];
	if (cat4Count > 0) for (i = 0; i < cat2Count; i++) runCount += foo[3][i];
	average = runCount / ovCount;

	//This block of code displays statistics eg. marks entered, pass rate, average etv
	cout << "\nTotal marks counted: " << ovCount << endl; //marks entered
	cout << "The amount of students that passed (40% or above): " << pass << endl; //amount passed
	cout << "The average mark was " << average << endl; //average mark

	
	



}