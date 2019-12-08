#include <iostream>
#include <string>
#include <exception>
#include<algorithm>
#include <sstream>
using namespace std;

//Declaration of functions used in code 
int avCalc(int x, int y);
int rate(int x, int y);
void display(int m1, int m2, int m3, int m4);
int highest(int x, int y);
int lowest(int x, int y);
void stats(float t, int a, float p, float f, int h, int l);
void welcome();
int convert(string a);

//main program
int main() {
	welcome(); //prints welcome message
	int count[4] = { 0,0,0,0 }; //stores value of each counter for mark in set catergory
	string input;
	int mark{};
	int average, pass, fail;
	int mTotal = 0, sTotal = 0;//declaration of total mark and total students
	int high = 0, low = 100;//default values for comuting highest/lowest values
	int range1[5] = { 0,30,40,70}; //stores first value for each range
	int range2[5] = { 29,39,69,100 }; //stores last value for each range
	const int cats = 4;


	do {
		bool okToGo = true; //checks whether mark is valid for operations- true by defualt
		string input;
		cout << "Enter student mark: ";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::toupper); //converts string to all uppercase 
		//tests to make sure value entered is a valid input
		try {
			//if q is entered loop breaks
			if (input == "Q") {
				break;
			}
			//otherwise string converted to interger value
			else {
				mark = convert(input); //conversion function
			}
		}
		//otherwise error message printed 
		catch (const char* msg) {
			cerr << msg << endl;
			okToGo = false; //value stored in mark is invalid and loop restarts

		}

		//this code is only exectued if previous condition is met so no erros occur
		if (okToGo == true) {
			//loop tests if mark inputted is in first catergory range
			//if not, next range tested untill range is found
			//range counter incrimented by 1
			for (int i = 0; i < cats; i++) {
				if (mark >= range1[i] && mark <= range2[i]) {
					count[i]++;
					break;
				}

				
			}
			mTotal += mark; //creates running count used to calc average
			sTotal++; //incriments student coutner by 1 to recorded overall marks entered 
			high = highest(mark, high); //runs comparison function using mark and high
			low = lowest(mark, low); //runs comparion function using mark and low

		}
	} while (true);

	if (mTotal == 0) //if no valid marks entered quits program
		cout << "Exiting program with no marks entered...\n";

	else {
		display(count[0], count[1], count[2], count[3]); //display histogram function
		average = avCalc(mTotal, sTotal); //calculates average using mark total and student total
		pass = rate(count[2], count[3]); //calcs pass amount using counters from cat3[2]/cat4[3] (marks over 40)
		fail = rate(count[0], count[1]); //calcs fail amount using counters cat1[0] and cat2[1] (marks under 40)
		stats(sTotal, average, pass, fail, high, low); //uses this data to display statistcis


	}
	return 0;


}

//histogram function
void display(int m1, int m2, int m3, int m4) {
	int max, height;
	int m[4] = { m1,m2,m3,m4 };
	const string t1 = "0-29", t2 = "30-39", t3 = "40-69", t4 = "70-100";
	const string bar = "-------------------------------";

	//This block of codes compares each cat count to work out max height
	if (m[0] > m[1]) max = m[0];
	else max = m[1];
	if (max < m[2]) max = m[2];
	if (max < m[3]) max = m[3];

	cout << "\t" << bar << "\n\n";
	//goes through line by line displaying histogram
	//height decremented by 1 each loop
	//prints * if mVal is greater than or equal to current height
	//prints space otherwise
	//takes new line after m4 is compared 
	for (height = max; height > 0; height--) {
		for (int i = 0; i < 4; i++) {
			if (m[i] >= height)
				cout << "\t  *";
			else
				cout << "\t   ";
		}
		cout << endl;

	}
	cout << "\t " << t1 << "   " << t2 << "   " << t3 << "   " << t4 << "\n\n\t" << bar;


}

int avCalc(int x, int y) {
	int z = x / y; //average = total/entries 
	return z;
}

int rate(int x, int y) {
	int z = x + y; //basic additon for pass/fail
	return z;
}

int highest(int x, int y) {
	if (x > y) //compares mark (x) to high value (y)
		y = x; //if x > y, new highest becomes mark enterd in that loop
	return y;
}

int lowest(int x, int y) {
	if (x < y) //compares mark (x) to low value (y)
		y = x; //if x<y, new lowest becomes mark entered in that loop
	return y;
}

//diplays stats
void stats(float t, int a, float p, float f, int h, int l) {
	cout << "\n\n\t\tStatistcs\n\t\t_________\n\n";
	cout << "\tTotal marks enters: " << t << "\n";
	cout << "\tAverage mark: " << a << "\n";
	cout << "\tTotal students passed: " << p << "\n\tPass rate: " << float(p / t * 100) << "%\n";
	cout << "\tTotal students failed: " << f << "\n\tFail rate: " << float(f / t * 100) << "%\n";
	cout << "\tHighest mark: " << h << "\n";
	cout << "\tLowest mark: " << l << "\n";
}

//welcome message
void welcome() {
	const string hash = "*****************************";
	cout << hash << "\n*";
	cout << "  Student mark calculator  ";
	cout << "*\n*  Press \"Q\" for histogram  *\n";
	cout << hash << "\n\n";
}

int convert(string a) {
	int x;
	if (a.length() < 1)
		throw "No input taken...";
	if (a.length() < 2) {
		if (!isdigit(a[0]))
			throw "That isnt a valid number...";
	}
	else if (a.length() < 3) { //2 digit number check for letters
		if (!isdigit(a[1]))
			throw "That isnt a valid number...";
	}
	else if (a.length() >= 3) { //3 digit number check for letters eg 1w2
		if (!isdigit(a[2]) || !isdigit(a[1]))
			throw "That isnt a valid number...";
	}
	else if (a.length() > 3) { //4 digit check eg wont accept 1w22 or 100w
		if (!isdigit(a[3]) || !isdigit(a[2]) || !isdigit(a[1]))
			throw "That isnt a valid number...";
	}


	if (isdigit(a[0])) { //if first char in string is digit converts to int
		stringstream ahh(a);
		ahh >> x;
		if (x < 0 || x>100) { //if int is out of range throw error
			throw "Enter a mark in range";
		}

	}
	else { //if anything other than digit enters then throw error
		throw "That was not a number...";


	}


	return x;

}