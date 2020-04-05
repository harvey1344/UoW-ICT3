#include <iostream>
#include <set>
#include <string>

using namespace std;

string rooms[10];
int i;

void menu();
void add();
void view();
void reset();
void empty();
void menu();
void remove();
void find();
void store();
void load();
void order();



int main() {
	menu();
	return 0;
}
//complete
void add() { //a
	bool loop;
	do {

		char option;
		int roomNo;
		string name;
		cout << "\nPlease enter the room number for guest: ";
		cin >> roomNo;
		cout << "\nPlease enter the guest full name: ";
		cin >> name;

		for (i = 0; i < 10; i++) {
			if (roomNo - 1 == i) {
				rooms[i] = name;

			}
		}

		cout << "\nAdd another guest?\nY for Yes\nN to return\n";
		do {
			cin >> option;
			option = toupper(option);
			if (option == 'Y') {
				loop = 1;
				break;
			}
			else if (option == 'N') {
				loop = 0;
				break;
				
				
			}
			else
				cout << "Invalid option...\nEnter Y or N\n";

		} while (true);


	} while (loop ==true);





}
//complete
void view() {//v
	int x(1);
	cout << endl;
	for (i = 0; i < 10; i++) {
		cout << "Room " << x << ":" << rooms[i] << endl;
		x++;
	}
	
}
//complete
void reset() { //i
	bool loop;
	char option;
	cout << "\nAre you sure you want to set all rooms to empty?";
	do{
		cout << "\nPress Y to confirm\nOr N to return to menu\n";
		cin >> option;
		option = toupper(option);
		switch (option) {
		case 'Y':
			for (i = 0; i < 10; i++) {
				rooms[i] = "empty";
			}
			cout << "Successfully cleared all rooms\n";
			loop = false;
			break;
		case 'N':
			loop = false;
			break;
		default:
			cout << "Invalid option...";
			loop = true;
		}

	} while (loop == true);

}
//complete
void empty() {
	int h=0;
	cout << endl;
	for (i = 0; i < 10; i++) {
		if (rooms[i] == "empty") {
			cout << "Room " << i + 1 << endl;
			h++;
		}
	}
	if (h == 0)
		cout << "Rooms not initalised or no empty rooms found!\n";
}
//complete
void remove() {
	bool loop;
	do{
		
		char option;
		int room;

		cout << "Please enter the room to empty: ";
		cin >> room;
		if (rooms[room-1] == "empty")
			cout << "This room is already empty\n";
		else {
			rooms[room-1] = "empty";
			cout << "Room " << room << " now emptied\n";
		}

		cout << "Empty another room?\nY for Yes\nN for No\n";
		do {
			cin >> option;
			option = toupper(option);
			if (option == 'Y') {
				loop = 1;
				break;
			}
			else if (option == 'N') {
				loop = 0;
				break;
				
			}
			else
				cout << "Invalid option...\nEnter Y or N\n";

		} while (true);

		


	} while (loop == true);
}

void menu() {
	while (true) {
		char option;
		cout << "\nMenu...";
		cout << "\nI- Initialise all rooms to empty\n";
		cout << "A- Add guest to a room\n";
		cout << "V- View all rooms\n";
		cout << "Q- Quit program\n";
		cout << "E- Display empty rooms\n";
		cout << "D- Delete guest from room\n";
		cin >> option;
		option = toupper(option);

		switch (option) {
		case 'A':
			add();
			break;
		case 'V':
			view();
			break;
		case 'I':
			reset();
			break;
		case 'E':
			empty();
			break;
		case 'D':
			remove();
			break;
		case 'Q':
			exit(0);
		default:
			cout << "Invalid option...\n\n";

		}
	}
}

void find() {
	string search;
	cout << "Please enter the guests last name: ";
	cin >> search;

	if (rooms[1].find(search) != string::npos) {
		cout << "found";
	}
}