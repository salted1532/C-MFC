#include <iostream>
using namespace std;

int main() {

	int num[5] = { 10, 20, 30, 40, 50 }; //배열은 자체가 주소
	int* p;

	p = num; // 그냥 변수는 p = &num, 배열은 자체가 주소

	cout << num << endl;
	cout << &num[0] << endl;
	cout << &num[1] << endl;
	cout << p << endl;
	cout << *p << endl;
	cout << &p << endl;
	cout << *(num)+1 << endl;
	cout << *(num+1) << endl;
	cout << *(p)+1 << endl;
	cout << *(p + 1) << endl;
	cout << p[3] << endl;



	return 0;
}