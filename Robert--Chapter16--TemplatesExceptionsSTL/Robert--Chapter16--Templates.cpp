#include "RobertRPersonalLibrary.h"

template <typename t>
t half(t num) {
	double temp = (double)num;
	if ((num / 2) == (temp / 2)) { //int check :)
		return num / 2;
	}
	else {

		return round(static_cast<float>(num) / 2);
	}
}

int main() {
	double a = 9;
	float b = 99;
	int c = 999;

	cout << half(a) << "\n";
	cout << half(b) << "\n";
	cout << half(c) << "\n";

	endProgram();
}