#include <iostream>
#include <MathLibrary.h>
using namespace std;

void main() {
	int x = 20, y = 10;
	int sum = 0;

	sum = add(x, y);
	cout << sum << endl;
	sum = sub(x, y);
	cout << sum << endl;
}