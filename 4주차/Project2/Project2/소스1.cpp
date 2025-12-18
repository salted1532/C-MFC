#include <iostream>
using namespace std;

int main() {

	int num[5] = { 10, 20, 30, 40, 50 };
	int* p;

	p = num; 

	cout << num << endl;
	cout << &num[0] << endl;

	return 0;
}