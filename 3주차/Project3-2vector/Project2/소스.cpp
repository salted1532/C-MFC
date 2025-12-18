#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string num;
    vector<string> values = { "apple", "mango", "banana", "grape", "fruit"};
    vector<string>::iterator it;

    //values.insert(3, 50);

    for (int i = 0; i < 5; i++) {
        cin >> num;
        values.push_back(num);
    }

    values[3] = "peach";
    values.insert(values.begin() + 3, "abcd"); // 제일 앞에 100 삽입

    cout << "-----------------------------" << endl;

    for (it = values.begin(); it != values.end(); it++) {
        cout << *it << " ";
    }

    cout << endl << "-----------------------------" << endl;

    // p != values.end() -2 를 통해 마지막 2개는 출력을 안함
    for (auto p = values.begin(); p != values.end()-2; p++) {
        cout << *p << " ";
    }

    cout << endl << "-----------------------------" << endl;

    for (auto& n : values) {
        cout << n << " ";
    }

    return 0;
}
