#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;


void main() {

	SetConsoleOutputCP(CP_UTF8);
	ifstream is;
	is.open("score.txt");

	ofstream os;
	os.open("result.txt");

	if(!is) {
		cerr << "파일 오픈실패" << endl;
		exit(1);
	}

	int number;
	char name[30];
	int score;

	for(int i = 0; i < 3; i++) {
		is >> number >> name >> score;

		cout << number << " " << name << " " << score << endl;

		os << number << " " << name << " " << score << endl;
	}
	is.close();
	os.close();
}