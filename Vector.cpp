#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<sstream>
#include<exception>
#include<algorithm>

using namespace std;

int avCalc(int x, int y);
int highest(int x, int y);
int lowest(int x, int y);
void stats(float t, int a, float p, float f, int h, int l);
void welcome();
int convert(string a);
void passR(int x, int& a, int& b);

int main() {
	welcome();
	//Line 8-47 is for creating vectors needed in program
	const int group = 100;
	double numCat;
	double r;
	cout << "Enter required catergories: ";
	cin >> numCat;
	r = group / numCat;

	int range = round(r);

	vector<int> rangeStart;
	vector<int> rangeEnd;
	vector<int> counter;

	//code for range start
	int j = range;
	rangeStart.push_back(0);
	for (int i = 0; i < numCat - 1; i++) {

		if (j < 100) {
			rangeStart.push_back(j);
			j += range;
		}
	}

	//code for range ending
	j = range;
	for (int i = 0; i < numCat - 1; i++) {
		if (j < 100) {
			rangeEnd.push_back(j - 1);
			j += range;
		}
	}
	rangeEnd.push_back(100);

	//code for range counter
	for (int i = 0; i < numCat; i++) {
		counter.push_back(0);
	}

	int mark{};
	int average, pass = 0, fail = 0;
	int mTotal = 0, sTotal = 0;
	int high = 0, low = 100;

	cin.ignore(1000, '\n');


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
			for (int i = 0; i < numCat; i++) {
				if (mark >= rangeStart[i] && mark <= rangeEnd[i]) {
					counter[i]++;
					break;
				}
			}


			passR(mark, pass, fail);
			mTotal += mark; //creates running count used to calc average
			sTotal++; //incriments student coutner by 1 to recorded overall marks entered 
			high = highest(mark, high); //runs comparison function using mark and high
			low = lowest(mark, low); //runs comparion function using mark and low

		}
	} while (true);

	if (mTotal == 0) 
		cout << "Exiting program with 0 marks entered";
	
	else {
		//display
		int max = *max_element(counter.begin(), counter.end());

		cout << "\nHistogram\n_________\n\n";

		for (int height = max; height > 0; height--) {
			for (int i = 0; i < numCat; i++) {
				if (counter[i] >= height)
					cout << "  *\t";
				else
					cout << "   \t";
			}
			cout << endl;
		}

		for (int i = 0; i < numCat; i++) {
			cout << rangeStart[i] << "-" << rangeEnd[i];
			cout << "\t";
		}

		average = avCalc(mTotal, sTotal); //calculates average using mark total and student total
		stats(sTotal, average, pass, fail, high, low); //uses this data to display statistcis
	}







	return 0;
	
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

void welcome() {
	const string hash = "*****************************";
	cout << hash << "\n*";
	cout << "  Student mark calculator  ";
	cout << "*\n*  Press \"Q\" for histogram  *\n";
	cout << hash << "\n\n";
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

void stats(float t, int a, float p, float f, int h, int l) {
	cout << "\n\nStatistcs\n\_________\n\n";
	cout << "Total marks enters: " << t << "\n";
	cout << "Average mark: " << a << "\n";
	cout << "Total students passed: " << p << "\nPass rate: " << float(p / t * 100) << "%\n";
	cout << "Total students failed: " << f << "\nFail rate: " << float(f / t * 100) << "%\n";
	cout << "Highest mark: " << h << "\n";
	cout << "Lowest mark: " << l << "\n";
}

int avCalc(int x, int y) {
	int z = x / y; //average = total/entries 
	return z;
}

void passR(int x, int& a, int& b) {
	if (x >= 40)
		a++;
	else
		b++;
}
