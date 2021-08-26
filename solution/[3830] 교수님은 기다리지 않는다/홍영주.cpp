#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> values;

int Find(int i) {
	if (parent[i] == i) return i;
	else {
		int pa = Find(parent[i]);
		values[i] += values[parent[i]];
		return parent[i] = pa;
	}
}

void Union(int a, int b, int weight) {
	int pa = Find(a);
	int pb = Find(b);

	// �̹� ���� ���� �ִٸ� ���� ���ʿ�
	if (pa == pb) return;

	values[pb] = weight + values[a] - values[b];
	parent[pb] = pa;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (true) {
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0) break;

		parent = vector<int>(N + 1);
		values = vector<int>(N + 1, 0);

		for (int i = 0; i <= N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < M; i++) {
			char ch;
			cin >> ch;

			if (ch == '!') {
				int a, b, w;
				cin >> a >> b >> w;
				Union(a, b, w);
			}
			else if (ch == '?') {
				int a, b; 
				cin >> a >> b;
				// ���� ���տ� ���� ������ �� ������.
				if (Find(a) == Find(b)) { 
					cout << values[b] - values[a]<< "\n";
				}
				else {
					// ���� ���տ� ������ ���� ������ �� �� ����.

					cout << "UNKNOWN" << "\n";
				}
			}
		}
	}
}
