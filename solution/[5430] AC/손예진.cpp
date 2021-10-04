#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

/*
* <idea>
* 1. split 함수 구현해서 ',' 떼고 각 원소를 string으로 deque에 저장
* 2. flag 변수로 배열 뒤집힘 여부 표시
* 3. error일 때는 op 함수에서 "error" 출력하고 다음 테스트 케이스 받기, 그 외에는 PrintAnswer 함수에서 정답 출력
* 
* <difficulty>
* 1. 각 숫자를 vector에 저장하고 매번 reverse했더니 시간초과 발생
* 2. main에서 op 함수에서 반환된 vector로 답 출력함 
* -> error일 때, empty일 때 모두 vector가 비어있어서 "[]" 출력해야되는데 "error" 출력함
*/

using namespace std;

int T;

void PrintAnswer(deque<string> num, bool rev) {
    cout << "[";
    if (rev) {
        while (!num.empty()) {
            cout << num.back();
            num.pop_back();
            if (!num.empty())
                cout << ",";
        }
    }
    else {
        while (!num.empty()) {
            cout << num.front();
            num.pop_front(); 
            if (!num.empty())
                cout << ",";
        }
    }
    cout << "]\n";
}

void op(deque<string> num, string cmd) {
    bool rev = false;
    for (int i = 0; i < cmd.length(); i++) {
        switch (cmd[i]) {
        case 'R':
            if (rev)
                rev = false;
            else
                rev = true;
            break;
        case 'D':
            if (num.size() == 0) {
                cout << "error\n";
                return;
            }
            if (rev)
                num.pop_back();
            else
                num.pop_front();
            break;
        }
    }
    PrintAnswer(num, rev);
}

deque<string> Split(string arr, char delimeter) {
    deque <string> num;
    stringstream ss(arr);
    string tmp;

    while (getline(ss, tmp, delimeter)) {
        num.push_back(tmp);
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        string cmd, arr;
        int n;
        cin >> cmd >> n >> arr;
        arr.erase(0, 1);
        arr.pop_back();
        deque<string> num = Split(arr, ',');
        op(num, cmd);
    }
}
