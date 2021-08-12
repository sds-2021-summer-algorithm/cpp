/*
* 높은 자리수에 많이 쓰인 알파벳을 높은 우선순위로 설정
* 해당 우선순위를 priority queue를 사용하여 구현
* => heap + 구현
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int Pair[26];
int dp[8][26];			// dp[4][1] : 5자리수에 B가 사용된 횟수
deque<string> words;

struct alpabet {
	char ch;			// 알파벳
	int digit[8];		// 해당 알파벳이 각 자리수에 쓰여진 횟수
};
struct cmp {
	bool operator()(alpabet& a, alpabet& b) {
		int a_cmp = 0; int b_cmp = 0;
		for (int i = 7; i >= 0; i--) {
			a_cmp = a_cmp * 10 + a.digit[i];
			b_cmp = b_cmp * 10 + b.digit[i];
		}
		return a_cmp < b_cmp;
	}
};
priority_queue<alpabet, vector<alpabet>, cmp> pq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(Pair, -1, sizeof(Pair));		// 숫자와 문자 쌍 배열 초기화

	cin >> n;
	for (int i = 0; i < n; i++) {		// 각 단어를 입력받는 동시에 dp배열 초기화
		string s; cin >> s;
		int len = s.size();
		for (int j = 0; j < len; j++) {
			dp[len - j - 1][s[j] - 'A']++;
		}
		words.push_back(s);
	}

	for (char c = 'A'; c <= 'Z'; c++) {	// 각 알파벳을 기준으로 dp배열을 순회하여 heap에 해당 알파벳을 추가
		alpabet now;
		now.ch = c;
		for (int i = 0; i < 8; i++) {
			now.digit[i] = dp[i][c - 'A'];
		}
		pq.push(now);
	}

	int cur = 9;
	while (!pq.empty()) {				// 우선순위가 높은 알파벳 순으로 숫자를 부여
		alpabet now = pq.top(); pq.pop();

		bool flag = false;
		for (int i = 0; i < 8; i++) {
			if (now.digit[i] != 0) {
				flag = true;
				break;
			}
		}

		if (!flag) break;

		Pair[now.ch - 'A'] = cur;
		cur--;
	}

	int ans = 0;
	while (!words.empty()) {			// Pair에 기록된 숫자 - 알파벳 쌍을 기준으로 각 단어를 계산
		int tmp = 0;
		string s = words.front(); words.pop_front();

		for (char c : s) {
			tmp = tmp * 10 + Pair[c - 'A'];
		}
		ans += tmp;
	}

	cout << ans;
}