#include<iostream>
#include<fstream>
#include<Windows.h>
#include<vector>
using namespace std;

//파일읽어 사용하기 예제
//int main() {
//
//    ifstream is("result.txt");  // 파일 열기
//
//    // 파일이 열리지 않았을 경우 에러 메시지 출력
//    if (!is.is_open()) {
//        cout << "파일을 열 수 없습니다!" << endl;
//        return 1;  // 프로그램 종료
//    }
//
//    int num;
//    double num2;
//
//    // 파일에서 숫자 읽기
//    while (is >> num >> num2) {
//        cout << num << "시: 온도 " << num2 << "°C" << endl;
//    }
//
//    is.close();  // 파일 닫기
//    return 0;
//}


//Class 구조체를 사용한 파일읽어 사용하기 방법
class TempData {//시간, 온도정보를 가진 클래스
public:
	int hour;
	double temperature;
};

int main() {

	ifstream is{ "result.txt" };
	
	if (!is) { // ! 연산자 오버로딩
		cerr << "파일 오픈에 실패하였습니다" << endl;
		exit(1);
	}

	vector<TempData> temps; //TempData를 매개변수로 가진 백터배열 temps
	int hour;
	double temperature;
	
	while (is >> hour >> temperature) {
		temps.push_back(TempData{ hour, temperature }); //temps에다가 hour, temperature 차례대로 집어넣기
	}
	
	for (TempData t : temps) { //temps에서 차례대로 꺼내기 
		cout << t.hour << "시: 온도 " << t.temperature << endl; //꺼내어 출력
	}

	is.close();  // 파일 닫기
	return 0; 
}