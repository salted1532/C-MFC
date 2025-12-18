#include <iostream>
using namespace std;

//참조자 응용 및 배열 참조자
void change(int& p) {
	p = 100;
}
int main() {
	int num = 5;
	cout << num << endl;
	change(num);
	cout << num << endl;

	int arr[3] = { 1, 2, 3 };
	int(&ref)[3] = arr;
	ref[0] = 100;
	cout << arr[0] << arr[1] << arr[2] << endl;

	return 0;
}
