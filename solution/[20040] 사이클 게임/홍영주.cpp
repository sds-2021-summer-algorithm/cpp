#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int Find(int i) {
	if (parent[i] == i) return i;
	else {
		return parent[i] = Find(parent[i]);
	}
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M;

	cin >> N >> M;

	parent = vector<int>(N);

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	int index = 0;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;

		if (Find(a) == Find(b)) {
			index = i;
			break;
		}
		Union(a, b);
	}

	cout << index << "\n";

	return 0;
}