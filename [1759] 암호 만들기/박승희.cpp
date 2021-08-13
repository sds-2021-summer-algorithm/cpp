// * prev_permutation ��� (���� ������ 15�� �����̱� ������ ��� ������)
// * n���� ���� �߿��� k�� ���� �� �ִ� ����� �� ���ϱ�

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

// �ּ� �� ���� ����(a, e, i, o, u)�� �ּ� �� ���� �������� �����Ǿ� �ִ��� Ȯ��
bool check(string str) {
	int cnt1 = 0, cnt2 = 0; // ���� ���� Ȯ��
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

	// ��ȣ �����
	make_lockNumber();

	// ����, ���� ���� Ȯ��
	for (int i = 0; i < result.size(); ++i) {
		if (check(result[i])) { answer.push_back(result[i]); }
	}

	// ���� �� ����
	sort(answer.begin(), answer.end(), comp);

	for (auto a : answer) cout << a << '\n';

	return 0;
}