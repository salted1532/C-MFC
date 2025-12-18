#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main() {
	int num;
	list<int>values;
	list<int>::iterator it;

	values.insert(values.begin(), 50);

	for (int i = 0; i < 5; i++) {
		cin >> num;
		values.push_back(num);
	}

	values.push_front(100); //임의로 값을 넣기 push_front 제일 앞

	cout << "-----------------------------" << endl;

	//동적 배열 상태라 순서가 없음 it (반복자) 가리키는 주소로 찾아 반복
	for (it = values.begin(); it != values.end(); it++/* 주소값이++ */ ) {
		cout << *it << " ";
	}

	cout << endl << "-----------------------------" << endl;

	for (auto p = values.begin(); p != values.end(); p++) {
		cout << *p << " ";
	}

	cout << endl << "-----------------------------" << endl;

	for (auto& n : values) {
		cout << n << " ";
	}

	return 0;
}