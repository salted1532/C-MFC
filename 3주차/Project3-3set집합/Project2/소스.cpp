#include <iostream>
#include <set>

using namespace std;

int main() {
    int num;
    //set<int> values; //중복 허용 안함
    multiset<int> values; //중복 허용함

    values.insert(10);
    values.insert(20);
    values.insert(30);
    values.insert(40);
    values.insert(50);

    values.insert(30);

    cout << endl << "-----------------------------" << endl;

    auto po = values.find(30);
    if (po != values.end()) {
        cout << "values = " << *po << " 발견하였다" << endl;
    }
    else {
        cout <<  "values 값을 찾지 못했습니다." << endl;
    }


    for (auto p = values.begin(); p != values.end(); p++) {
        cout << *p << " ";
    }

    return 0;
}
