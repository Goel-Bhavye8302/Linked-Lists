#include<iostream>
#include<conio.h>
#include"List.hpp"
#include"Double list.h"
#include"Menu.hpp"

int input;

int main() {

	char type;

	Menu myMenu;
	
	
	std::cout << "Type 'L' for simple list.\n";
	std::cout << "Type 'D' for double list.\n";
	std::cin >> type;

	if (type != 'l' && type != 'd') return 0;

	myMenu.printInstructions(type);

		while (true) {
			std::cout << "Enter the operation \n";
			std::cin >> input;
			myMenu.function(input, type);
		}
	return 0;
}