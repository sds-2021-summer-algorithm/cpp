#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int N, K;
vector<string> cards;
set<string> s;

void SetCard(vector<string> v) {   //해당 조합에 대한 모든 순열 구하기
    sort(v.begin(), v.end());
    do {
        string str = "";
        for (auto iter = v.begin(); iter != v.end(); iter++)
            str += *iter;
        s.insert(str);
    } while (next_permutation(v.begin(), v.end()));

}

void PickCard(int idx, vector<string> v) { //모든 카드의 조합
    if (idx >= N) {
        if (v.size() == K)
            SetCard(v);
        return;
    }
    PickCard(idx + 1, v);
    v.push_back(cards[idx]);
    PickCard(idx + 1, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string card;
        cin >> card;
        cards.push_back(card);
    }
    vector<string> v;
    PickCard(0, v);
    cout << s.size() << "\n";
}
