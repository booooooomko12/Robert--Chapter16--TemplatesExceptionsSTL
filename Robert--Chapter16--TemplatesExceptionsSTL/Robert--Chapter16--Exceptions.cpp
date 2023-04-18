#include "RobertRPersonalLibrary.h"

char character(char, int);

int main() {
	try {
		Sleep(100);
		cout << character('B', 1) << '\n';
		Sleep(100);
		cout << character('R', 100) << '\n'; //Comment out once exception is thrown
		Sleep(100);
		cout << character('O', -1) << '\n';
		Sleep(100);
		cout << character('?', 1) << '\n'; //Comment out once exception is thrown
		Sleep(100);
	}
	catch (string exception) {
		cout << exception;
		endProgram();
	}

}

char character(char c, int off) {
	if (!isalpha(c)) {
		string invalidCharacterException = "Error: Character is not alphabetical.\n";
		throw invalidCharacterException;
	}
	else if (!isalpha(c + off) || (isupper(c) && islower(c + off)) || (islower(c) && isupper(c+off))) {
		string invalidRangeException = "Error: Targeted character is not alphabetical or returns an opposite case letter.\n";
		throw invalidRangeException;
	}
	else {
		return c + off;
	}
}