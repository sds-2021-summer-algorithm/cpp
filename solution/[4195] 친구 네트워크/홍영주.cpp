#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> parent;
vector<int> numbers;

int Find(int i) {
	if (parent[i] == i) return i;
	else {
		int root = Find(parent[i]);
		numbers[i] = numbers[root];
		return parent[i] = root;
	}
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	// ������ ������ �ʿ䰡 ����
	if (pa == pb) {
		return;
	}
	else {
		int sum = numbers[pb] + numbers[pa];
		numbers[pb] = sum;
		numbers[pa] = sum;
		parent[pb] = pa;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	int F;

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> F;
		int cnt = 1;

		unordered_map<string, int> m;
		parent = vector<int>();
		numbers = vector<int>();
		// parent �� 0�� �׳� dump ��
		parent.push_back(0);
		numbers.push_back(0);
		for (int i = 0; i < F; i++) {
			string str1, str2;

			cin >> str1 >> str2;
			int a, b;
			// ��ã�Ҵٸ�
			if (m.find(str1) == m.end()) {
				m.insert(make_pair(str1, cnt));
				parent.push_back(cnt);
				numbers.push_back(1);
				cnt++;
			}

			if (m.find(str2) == m.end()) {
				m.insert(make_pair(str2, cnt));
				parent.push_back(cnt);
				numbers.push_back(1);
				cnt++;
			}

			a = m[str1];
			b = m[str2];

			// Union �ϱ�
			Union(a, b);
			// �׸��� �θ� ����� ���� ����.

			cout << numbers[Find(a)] << "\n";
		}
	}

}