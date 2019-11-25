#include <iostream>
#include <string>
using namespace std;

int main() {
	int r1 = 5, r2 = 12, r3 = 7, r4 = 6, maxVal;
	if (r1 > r2)maxVal = r1;
	else maxVal = r2;
	if (maxVal < r3)maxVal = r3;
	if (maxVal < r4) maxVal = r4;

	for (int i = maxVal; i > 0;i--) {
		if (r1 >= i) { 
			cout << "*\t";
		}
		else cout << " \t";
		if (r2 >= i) {
			cout << "*\t";
		}
		else cout << " \t";
		if (r3 >= i) {
			cout << "*\t";
		}
		else cout << " \t";
		if (r4 >= i) {
			cout << "*\n";
		}
		else cout << " \n";
	}
	cout << "1\t2\t3\t4" << endl;
}