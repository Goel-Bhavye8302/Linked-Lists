#include"Menu.hpp"
#include"List.hpp"
#include"Double list.h"
#include<iostream>
#include<sstream>

using namespace std;

int value , value2;

List myList;
DoubleList myList2;

void Menu::printInstructions(char type)
{
	if (type == 'l') myList.showType();
	if (type == 'd') myList2.showType();
	cout << "Enter 1 to Insert an element in the end of thelist \n";
	cout << "Enter 2 to Insert an element in front of the list\n";
	cout << "Enter 3 to remove the last elemnt of the list\n";
	cout << "Enter 4 to remove the first element of the list\n";
	cout << "Enter 5 to find the index of an element\n";
	cout << "Enter 6 to know the element at a given index\n";
	cout << "Enter 7 to know the first element of the list\n";
	cout << "Enter 8 to know the last element of the list\n";
	cout << "Enter 9 to know the size of the list\n";
	cout << "Enter 10 to insert an element at a given index\n";
	cout << "Enter 11 to clear the list\n";
	cout << "Enter 12 to remove an element of the list\n";
	cout << "Enter 13 to reverse the list\n";
}

void Menu::function(int input, char type)
{
	if (input == 1) {
		cout << "Enter the value: "; cin >> value;
		if (type == 'l') {
			myList.push_back(value);
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			myList2.push_back(value);
			cout << myList2.asString() << endl;
		}
	}

	else if (input == 2) {
		cout << "Enter the value: "; cin >> value;
		if (type == 'l') {
			myList.push_front(value);
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			myList2.push_front(value);
			cout << myList2.asString() << endl;
		}
	}

	else if (input == 3) {
		if (type == 'l') {
			myList.pop_back();
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			myList2.pop_back();
			cout << myList2.asString() << endl;
		}
	}

	else if (input == 4) {
		if (type == 'l') {
			myList.pop_front();
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			myList2.pop_front();
			cout << myList2.asString() << endl;
		}
		
	}

	else if (input == 5) {
		
		cout << "Enter the value: "; cin >> value;
		if (type == 'l'){
			cout << "index is : " << myList.find(value) << endl;
			cout << myList.asString() << endl;
		}
	
		else if (type == 'd') {
			cout << "index is : " << myList2.find(value) << endl;
			cout << myList2.asString() << endl;
		}
	}
		

	else if (input == 6) {
		
		cout << "Enter the index: "; cin >> value;
		if (type == 'l') {
			if (myList.at(value) != -1)cout << "The data at this index is: " << myList.at(value) << endl;
			else cout << "No data found" << endl;
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			if (myList2.at(value) != -1)cout << "The data at this index is: " << myList2.at(value) << endl;
			else cout << "No data found" << endl;
			cout << myList2.asString() << endl;
		}
		
	}

	else if (input == 7) {
		if (type == 'l') {
			cout << myList.front() << endl;
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			cout << myList2.front() << endl;
			cout << myList2.asString() << endl;
		}
		
	}

	else if (input == 8) {
		if (type == 'l') {
			cout << myList.back() << endl;
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			cout << myList2.back() << endl;
			cout << myList2.asString() << endl;
		}
		
	}

	else if (input == 9) {
		if (type == 'l') {
			cout << myList.size() << endl;
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			cout << myList2.size() << endl;
			cout << myList2.asString() << endl;
		}
	}

	else if (input == 10) {
		
		cout << "Enter the index: "; cin >> value; cout << endl;
		cout << "Enter the data: "; cin >> value2;
		if (type == 'l') {
			myList.insert(value, value2);
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			myList2.insert(value, value2);
			cout << myList2.asString() << endl;
		}
		
	}

	else if (input == 11) {
		if (type == 'l') myList.empty();
		else if (type == 'd') myList2.empty();
		
	}

	else if (input == 12) {
		cout << "Enter the index: "; cin >> value;
		if (type == 'l') {
			myList.erase(value);
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			myList2.erase(value);
			cout << myList2.asString() << endl;
		}
	}

	else if (input == 13) {
		if (type == 'l') {
			myList.reverse();
			cout << myList.asString() << endl;
		}
		else if (type == 'd') {
			myList2.reverse();
			cout << myList2.asString() << endl;
		}

	}

	else cout << "Wrong input";

}




