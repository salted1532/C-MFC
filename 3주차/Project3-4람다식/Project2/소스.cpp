#include <iostream>

using namespace std;


int sum(int x, int y) {
    cout << "함수 입니다." << endl;
    return x + y;
}

int main() {
    auto sum = [](int x, int y) {
        cout << "람다식 입니다." << endl;
        return x + y;
    };
    
    cout << sum(10, 20) << endl; //람다식이 먼저 작동함 왜냐하면 지역변수가 먼저 작동함

    return 0;
}
