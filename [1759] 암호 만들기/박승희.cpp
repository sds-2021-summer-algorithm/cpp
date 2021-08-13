// * prev_permutation 사용 (조합 개수가 15개 이하이기 때문에 사용 가능함)
// * n개의 문자 중에서 k개 뽑을 수 있는 경우의 수 구하기

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int l, c;
vector<int> vec;
vector<char> alpha;

vector<string> result;
vector<string> answer;

bool comp(string a, string b) { return a < b; }

// 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있는지 확인
bool check(string str) {
	int cnt1 = 0, cnt2 = 0; // 모음 자음 확인
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
			|| str[i] == 'o' || str[i] == 'u') cnt1++;
		else cnt2++;
	}

	if (cnt1 >= 1 && cnt2 >= 2) return true;
	else return false;
}

// ******** https://dev-mystory.tistory.com/302
void make_lockNumber() {
	for (int i = 0; i < l; i++) vec.push_back(1);
	for (int i = 0; i < c - l; i++) vec.push_back(0);

	do {
		string tmp = "";
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == 1) tmp += alpha[i];
		}
		result.push_back(tmp);

	} while (prev_permutation(vec.begin(), vec.end()));
	// ******** https://twpower.github.io/82-next_permutation-and-prev_permutation
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; ++i) {
		char a; cin >> a;
		alpha.push_back(a);
	}
	sort(alpha.begin(), alpha.end());

	// 암호 만들기
	make_lockNumber();

	// 자음, 모음 개수 확인
	for (int i = 0; i < result.size(); ++i) {
		if (check(result[i])) { answer.push_back(result[i]); }
	}

	// 사전 순 정렬
	sort(answer.begin(), answer.end(), comp);

	for (auto a : answer) cout << a << '\n';

	return 0;
}