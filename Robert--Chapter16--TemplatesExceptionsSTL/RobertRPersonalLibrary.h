#pragma once

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <Windows.h>

using namespace std;;

int endProgram() {
	cout << "\n\nPress enter to exit.\n";
	cin.ignore(100, '\n');
	cin.get();
	return 0;
}

int validateInt(string prompt) {
	int variable = 0;
	cout << prompt;
	while (!(cin >> variable) || cin.fail()) {
		cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

string getLine(string prompt) {
	string variable = " ";
	cout << prompt;
	while (!(getline(cin, variable)) || cin.fail()) {
		cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

int validateIntRange(string prompt, int min, int max) {
	float variable = 0;
	cout << prompt;
	while (!(cin >> variable) || cin.fail() || variable < min || variable > max) {
		cout << "\nAn error has occured: The input was invalid or not in range. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

int validateIntRangeWithExceptions(string prompt, int min, int max, int exception1, int exception2 = INT32_MAX, int exception3 = INT32_MAX) {
	float variable = 0;
	bool nbrValid = false;;
	cout << prompt;
	
	do {
		if (!(cin >> variable) || cin.fail()) {
			nbrValid = false;
		}
		else {
			if (exception2 == INT32_MAX)
				exception2 = variable + 1;
			else if (exception3 == INT32_MAX) //If optional exceptions arent used, ensure they don't affect later comparisons!
				exception3 = variable + 1;
		}
		
		if ((variable != exception1 && variable != exception2 && variable != exception3) && (variable < min || variable > max)) {
			nbrValid = false;
		}
		else
			nbrValid = true;

		if (!nbrValid) {
			cout << "\nAn error has occured: The input was invalid, not an exception, or not in range. Please retry.\n\n";
			cin.clear();
			cin.sync();
			cin.ignore(100, '\n');
		}
	} while (!nbrValid);
	
	return variable;
}

float validateFloat(string prompt) {
	float variable = 0;
	cout << prompt;
	while (!(cin >> variable) || cin.fail()) {
		cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

float validateFloatRange(string prompt, float min, float max) {
	float variable = 0;
	cout << prompt;
	while (!(cin >> variable) || cin.fail() || variable < min || variable > max) {
		cout << "\nAn error has occured: The input was invalid or not in range. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

double validateDouble(string prompt) {
	double variable = 0;
	cout << prompt;
	while (!(cin >> variable) || cin.fail()) {
		cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

long validateLong(string prompt) {
	long variable = 0;
	cout << prompt;
	while (!(cin >> variable) || cin.fail()) {
		cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

int validateChar(string prompt) {
	char variable = ' ';
	cout << prompt;
	while (!(cin >> variable) || cin.fail()) {
		cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return variable;
}

int validateCharSet(string prompt, char character1, char character2, char character3 = ' ', char character4 = ' ', char character5 = ' ') {
	char variable = ' ';
	bool inputAgain = false;
	cout << prompt;
	do {
		while (!(cin >> variable) || cin.fail()) {
			cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
			cin.clear();
			cin.sync();
			cin.ignore(100, '\n');
		}

		variable = toupper(variable);

		if (variable != character1 && variable != character2 && (character3 == ' ' || variable != toupper(character3)) && (character4 == ' ' || variable != toupper(character4)) && (character5 == ' ' || variable != toupper(character5))) {
			cout << "\nThis input does not match the range of valid values. Please retry.\n\n";
			cin.clear();
			cin.sync();
			cin.ignore(100, '\n');
			inputAgain = true;
		}
		else
			inputAgain = false;
	} while (inputAgain == true);
	return variable;
}
char repeatProgram() {
	cout << "\nWould you like to repeat this program (Y or N)?\n\n";
	char variable = ' ';
	while (!(cin >> variable) || variable != 'Y' && variable != 'N' && variable != 'n' && variable != 'y') {
	cout << "\nAn error has occured: Your input must be \"Y\" or \"N,\" please retry.\n\n";
	cin.clear();
	cin.sync();
	cin.ignore(100, '\n');
	}
	variable = toupper(variable);

	return variable;
}

int getRandom(int range_from, int range_to) {
	int randomNum = 0;
	srand(time(NULL));
	if (range_from == 0) //Using modulus by 0 creates a critical exception, this "if" prevents that.
		randomNum = rand() % (range_to + 1);
	else
		randomNum = rand() % range_from + range_to;
	return randomNum;
}

char yesOrNo(string prompt) {
	char variable = ' ';
	bool inputAgain = false;
	cout << prompt << "\n\n";
	do {
		while (!(cin >> variable) || cin.fail()) {
			cout << "\nAn error has occured: The input was invalid. Please retry.\n\n";
			cin.clear();
			cin.sync();
			cin.ignore(100, '\n');
		}

		variable = toupper(variable);

		if (variable != 'Y' && variable != 'N'){
			cout << "\nPlease enter Y or N, retry.\n\n";
			cin.clear();
			cin.sync();
			cin.ignore(100, '\n');
			inputAgain = true;
		}
		else
			inputAgain = false;
	} while (inputAgain == true);
	return variable;
}

int basicMenu(int amtOfOptions, string option1, string option2, string option3 = "", string option4 = "", string option5 = "", string option6 = "", string option7 = "", string option8 = "", string option9 = "") {
	string optionArray[9] = { option1, option2, option3, option4, option5, option6, option7, option8, option9 };

	for (int i = 0; i < amtOfOptions; i++) {
		cout << optionArray[i] << "\n";
	}
	cout << "Input 0 to exit the menu.\n\n";
	int userNbr = validateIntRange("", 0, amtOfOptions);
	return userNbr;
}

string getDirectory() {
	string directoryName = " ";

	cout << "\n\nWhat is directory in which your file is located?\n\n";
	
	getline(cin, directoryName);
	cin.sync();

	return directoryName;
}

string getFileName() {
	string fileName = " ";

	cout << "\n\nWhat is the name of the file you are attempting to access?\n\n";
	
	getline(cin, fileName);
	cin.sync();

	return fileName;
}


string validateFile() {
	ifstream fileToTest;
	bool runAgain = false;
	string fullFileName = " ";

	do {
		runAgain = false;
		string directoryName;
		cout << "\n\nWhat is the directory in which your file is located?\n\n";
		getline(cin, directoryName);
		cin.sync();

		string fileName;
		cout << "\n\nWhat is the name of the file you are attempting to access?\n\n";
		getline(cin, fileName);
		cin.sync();

		fullFileName = directoryName + "\\" + fileName;

		fileToTest.open(fullFileName);
		cout << "\n\nVerifying file location...";
		Sleep(350);

		if (fileToTest.is_open()) {
			cout << "\n\nFile verified.\n\n";
		}
		else {
			cout << "\n\nERROR: Unable to verify file location. Ensure file directory and file name are exact.";
			runAgain = repeatProgram();
			cin.ignore(100, '\n');
		}
	} while (runAgain == true);

	return fullFileName;
}

string findOutputFile() {
	ofstream fileToTest;
	bool runAgain = false;
	string fullFileName = " ";


	string directoryName;
	cout << "\n\nWhat is the directory in which your file is located?\n\n";
	getline(cin, directoryName);
	cin.sync();

	string fileName;
	cout << "\n\nWhat is the name of the file you are attempting to write to? (WILL CREATE A FILE IF NAME DOES NOT MATCH)\n\n";
	getline(cin, fileName);
	cin.sync();

	fullFileName = directoryName + "\\" + fileName;

	fileToTest.open(fullFileName);
	cout << "\n\nVerifying file location...";
	Sleep(350);

	cout << "\n\nOpening file: \n\n\"" << fullFileName << "\"...\n\n";
	

	return fullFileName;
}

int getNbrLinesFromFile(string fullFileName) {
	int nbrOfLines = 0;
	ifstream fileToReadLinesFrom;
	string lines = " ";
	string directory = " ";

	fileToReadLinesFrom.open(fullFileName);

	while (!fileToReadLinesFrom.is_open()) {
		cout << "ERROR: The file you wish to open cannot be found. Please reinput your file name with its full directory location.";
		directory = validateFile();
		fileToReadLinesFrom.open(directory);
	}

	while (getline(fileToReadLinesFrom, lines)) {
		nbrOfLines++;
	}

	return nbrOfLines;
}

