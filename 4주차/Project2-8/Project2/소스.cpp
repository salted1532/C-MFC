#include <iostream>
using namespace std;

//new로 배열 할당
//int main() {
//	int size = 5;
//	int* num = new int[size];
//
//	for (int i = 0; i < size; i++) {
//		cin >> num[i];
//	}
//	for (int i = 0; i < size; i++) {
//		cout << i << " : " << num[i] << endl;
//	}
//
//	delete[] num;
//	return 0;
//}

//2차원 배열 할당
int main() {
	int row = 5;
	int col = 3;
	int** num = new int*[row];

	for (int i = 0; i < row; i++) {
		num[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			num[i][j] = i + j;
			cout << num[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < row; i++) {
		delete[] num[i];
	}

	delete[] num;

	return 0;
}