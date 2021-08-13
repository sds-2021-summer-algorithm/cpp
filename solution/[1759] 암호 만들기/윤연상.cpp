#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int l, c;				// l : 암호 길이, c : 후보 문자 개수
bool visited[15];		// dfs용 visit 배열
char candidate[15];		// 후보 문자 
vector<string> ans;		// 가능한 암호 저장

// 해당 문자열이 암호가 가능한 지 여부
bool check(string s) {
	int a = 0; int b = 0;
	for (char c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			a++;
		}
		else {
			b++;
		}
	}
	if (a >= 1 && b >= 2) {
		return true;
	}
	else {
		return false;
	}
}
// 암호 생성 dfs
void dfs(int cnt, int idx, string s) {
	if (cnt == l) {
		if (check(s)) {
			ans.push_back(s);
		}
		return;
	}
	for (int i = idx; i < c; i++) {
		if (visited[i])
			continue;
		visited[i] = 1;
		s.push_back(candidate[i]);
		dfs(cnt + 1, i, s);
		s.pop_back();
		visited[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char ch; cin >> ch;
		candidate[i] = ch;
	}
	sort(candidate, candidate + c);		// 미리 후보군을 정렬하여 dfs 결과 값이 정렬된 결과로 유도
	memset(visited, false, sizeof(visited));

	dfs(0, 0, "");

	for (string s : ans) {
		cout << s << '\n';
	}
}