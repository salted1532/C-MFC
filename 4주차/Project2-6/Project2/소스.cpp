#include <iostream>
using namespace std;

//int fun() {
//	int a = 2;
//	return a;
//}
//
//int main() {
//	int b = fun();
//	cout << b << endl;
//	return 0;
//}

//참조자 함수
int fun(int &n) {
	int n = 2;
	return n;
}

int main() {
	int num = 10;
	int num2 = fun(num);
	cout << num2 << endl;
	return 0;
}

