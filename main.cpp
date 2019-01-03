#include <iostream>
#include <string>
#include "toggle2.cpp"

void run1() { std::cout << "ran 1"; } //functions to execute
void run2() { std::cout << "ran 2"; }

int main() { //exmaple use for toggler class/classes
	toggle2* test=new toggle2(run1, run2);
	std::string input="";
	for (;;) {
		std::cout << "press a key:";
		std::getline(std::cin, input);
		//toggler checks if condition is good, then runs the next function
		test->run(input=="123");
	}
	return 0;
}