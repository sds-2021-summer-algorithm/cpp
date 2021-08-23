#include <iostream>
#include <unordered_set>
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

	if (pb > pa) {
		parent[pb] = pa;
	}
	else {
		parent[pa] = pb;
	}
}

void print() {
	for (int i = 0; i < parent.size(); i++) {
		cout << parent[i] << " ";
	}

	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int G, P;

	cin >> G >> P;

	parent = vector<int>(G + 1);

	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}

	int cnt = 0;
	for (int i = 0; i < P; i++) {
		int a;
		cin >> a;

		if (a > G || a <= 0) continue;

		
		// parent가 0을 가리키고 있으면 비행기가 더 이상 들어올 수가 없음.
		int index = Find(a);
		if (index == 0) {
			break;
		}

		// 아직 도킹이 되지 않은 곳.
		cnt++;
		Union(index, index - 1);

		//print();
	}

	cout << cnt << "\n";

	return 0;
}