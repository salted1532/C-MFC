#include <iostream>
using namespace std;

//기본 적으로 주소값을 넘겨주기
//void add(int *n1, int *n2) {
//	int sum = *n1 + *n2;
//	cout << "sum = " << sum << endl;
//}
//
//int main()
//{
//	int num1 = 100, num2 = 200;
//	add(&num1, &num2);
//
//	cout << num1 << " : " << num2 << endl;
//
//	return 0;
//}

//그냥 값 넘겨주기
//void add(int n1, int n2) {
//	cout << n1 << " : " << n2 << endl;
//	int temp;
//	temp = n1;
//	n1 = n2;
//	n2 = temp;
//	cout << n1 << " : " << n2 << endl;
//}
//
//int main()
//{
//	int num1 = 100, num2 = 200;
//
//	cout << num1 << " : " << num2 << endl;
//
//	add(num1, num2);
//
//  cout << num1 << " : " << num2 << endl;
// 
//	return 0;
//}

//주소값을 넘겨주어 원래값에 영향을 줌
void add(int* n1, int* n2) {
	cout << *n1 << " : " << *n2 << endl;
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
	cout << *n1 << " : " << *n2 << endl;
}

int main()
{
	int num1 = 100, num2 = 200;

	cout << num1 << " : " << num2 << endl;

	add(&num1, &num2);

	cout << num1 << " : " << num2 << endl;

	return 0;
}