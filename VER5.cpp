#include <iostream>
#include <string>
#include <exception>
#include<algorithm>
#include <sstream>
using namespace std;

//Initialises functions used in program
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
	welcome();
	
	int count[4] = { 0,0,0,0 };
	string input;
	int mark{};
	int average, pass, fail;
	int mTotal = 0, sTotal = 0;
	int high = 0, low = 100;
	int range1[4] = { 0,30,40,70 };
	int range2[4] = { 29,39,69,100 };


	do {
		string input;
		cout << "Enter student mark: ";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		try {
			if (input == "Q") 
				break;
			else {
				mark = convert(input);
				cout << mark;
			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
			count[0]--;
		}

		for (int i = 0, j = 0; i < numOfCats; i++, j++) {
			if (mark >= range1[i] && mark <= range2[i])
				count[j]++;

			if (mark > 0 && mark <= 100) {
				mTotal += mark;
				sTotal++;
			}

			high = highest(mark, high);
			low = lowest(mark, low);
	}while (true);
		
	if (mTotal == 0)
		cout << "Exiting program with no marks entered...\n";
		
	else {
		display(count[0], count[1], count[2], count[3]);
		average = avCalc(mTotal, sTotal);
		pass = rate(count[2], count[3]);
		fail = rate(count[0], count[1]);
		stats(sTotal, average, pass, fail, high, low);

	}
		


	return 0;


}

void display(int m1, int m2, int m3, int m4) {
	int max, height;
	const string t1 = "0-29", t2 = "30-39", t3 = "40-69", t4 = "70-100";
	const string bar = "-------------------------------";

	//This block of codes compares each catergory count to tget the max heigh value
	if (m1 > m2) max = m1;
	else max = m2;
	if (max < m3) max = m3;
	if (max < m4) max = m4;

	cout << "\t" << bar << "\n\n";
	for (height = max; height > 0; height--) {

		if (m1 >= height)
			cout << "\t  *\t";
		else
			cout << "\t   \t";

		if (m2 >= height)
			cout << "  *\t";
		else
			cout << "   \t";

		if (m3 >= height)
			cout << "  *\t";
		else
			cout << "   \t";

		if (m4 >= height)
			cout << "  *\n";
		else
			cout << "   \n";

	}
	cout << "\t " << t1 << "   " << t2 << "   " << t3 << "   " << t4 << "\n\n\t" << bar;


}

int avCalc(int x, int y) {
	int z = x / y;
	return z;
}

int rate(int x, int y) {
	int z = x + y;
	return z;
}

int highest(int x, int y) {
	if (x > y)
		y = x;
	return y;
}

int lowest(int x, int y) {
	if (x < y)
		y = x;
	return y;
}

void stats(float t, int a, float p, float f, int h, int l) {
	cout << "\n\n\t\tStatistcs\n\t\t_________\n\n";
	cout << "\tTotal marks enters: " << t << "\n";
	cout << "\tAverage mark: " << a << "\n";
	cout << "\tTotal students passed: " << p << "\n\tPass rate: " << float(p / t * 100) << "%\n";
	cout << "\tTotal students failed: " << f << "\n\tFail rate: " << float(f / t * 100) << "%\n";
	cout << "\tHighest mark: " << h << "\n";
	cout << "\tLowest mark: " << l << "\n";
}

void welcome() {
	const string hash = "*****************************";
	cout << hash << "\n*";
	cout << "  Student mark calculator  ";
	cout << "*\n*  Press \"Q\" for histogram  *\n";
	cout << hash << "\n\n";
}

int convert(string a) {
	int x;
	if (isdigit(a[0])) {
		stringstream ahh(a);
		ahh >> x;
		if (x < 0 || x>100) {
			throw "Enter a mark in range";
		}

	}
	else  {
		throw "That was not a number...";
	
	}
	return x;

}

	
