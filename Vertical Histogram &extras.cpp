#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Initialises functions used in program
int avCalc(int x, int y);
int rate(int x, int y);
void display(int m1, int m2, int m3, int m4);
int highest(int x,int y);
int lowest(int x, int y);
void stats(float t, int a, float p, float f, int h, int l);

//main program
int main() {

	int count[4] = { 0,0,0,0 };
	int mark;
	int average, pass, fail;
	int mTotal = 0, sTotal = 0;
	int high=0, low=100;


	do {
		cout << "Please enter student mark: ";
		cin >> mark;
		
		if (cin.fail()) {
			cin.clear();
			cout << "That wasnt a mark...\n";
			break;
		}

		if (mark >= 0 && mark <= 29)
			count[0]++;

		else if (mark >= 30 && mark <= 39)
			count[1]++;

		else if (mark >= 40 && mark <= 69)
			count[2]++;

		else if (mark >= 70 && mark <= 100)
			count[3]++;

		else break;

		if (mark > 0 && mark <= 100) {
			mTotal += mark;
			sTotal++;
		}

		high = highest(mark, high);
		low = lowest(mark, low);

	} while (mark <= 100);
	display(count[0], count[1], count[2], count[3]);
	average = avCalc(mTotal, sTotal);
	pass = rate(count[2], count[3]);
	fail = rate(count[0], count[1]);
	stats(sTotal, average, pass, fail, high, low);

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

	cout <<"\t"<< bar << "\n\n";
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
	if (x> y)
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