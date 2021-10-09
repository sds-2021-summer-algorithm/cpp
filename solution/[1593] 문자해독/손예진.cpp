#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

/*
* <difficulty>
* 문제 잘못 이해..
* -> "모든 경우의 수"를 동일한 문자 조합은 한 가지로 취급한다는 뜻으로 이해했음 (그래서 set 사용)
*/

int g, s;
string W, S;
int check[130], isChecked[130];
set<string> ans;
vector<string> answer;

void SlidingWindow() {
    int right = 0, left = 0, num = 0;
    string tmp = "";
    while (true) {
        if (num == g) {   //정답 목록에 추가
            answer.push_back(tmp);
            isChecked[tmp[0]]--;
            num--;
            tmp = tmp.substr(1, tmp.length());
        }
        if (right >= s)
            break;
        char c = S[right];
        if (isChecked[c] < check[c]) {   //W에 해당
            isChecked[c]++;
            num++;
            tmp.push_back(c);
            right++;
        }
        else{   //가능성 있음
            if (check[c]) { //맨 왼쪽 문자 버리고 (1번째 ~ 오른쪽 문자)를 취함
                num--;
                isChecked[tmp[0]]--;
                tmp = tmp.substr(1, tmp.length());
            }
            else {  //현재 문자까지 모두 아예 불가능한 조합
                memset(isChecked, 0, sizeof(isChecked));
                num = 0;
                tmp = "";
                right++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> g >> s >> W >> S;
    for (int i = 0; i < W.length(); i++) {
        check[W[i]]++;
    }
    SlidingWindow();
    cout << answer.size() << "\n";
}
