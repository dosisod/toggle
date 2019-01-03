#include <functional>
#include <iostream>
#include <string>
#include "toggle.cpp"

//toggle example
void run1(std::string s) { std::cout << s << std::endl; }
void run2(std::string s) { std::cout << s+s << std::endl; }
void run3(std::string s) { std::cout << s+s+s << std::endl; }

//toggle2 example
void move_arm(bool open) { std::cout << "arm " << (open?"opened":"closed") << std::endl; }

int main() { //exmaple use for toggler class/classes

	toggle2<bool>* arm=new toggle2<bool>(
		move_arm, //run the command
		move_arm,
		std::vector<bool>{true,false} //but invert the params
	);

	toggle<std::string>* other=new toggle<std::string>( //toggle between 3 (or more) functions
		std::vector<std::function<void(std::string)>>{run1, run2, run3},
		std::vector<std::string>{"hello", "hey", "hi"}
	);
	
	std::string input="";
	std::cout << "2 toggles \"toggle2\", 3 toggles \"toggle\"" << std::endl;
	for (;;) {
		std::cout << ">";
		std::getline(std::cin, input);
		
		//toggler checks if condition is good, then runs the next function
		arm->toggleIf(input=="2");
		other->toggleIf(input=="3");
	}
	return 0;
}