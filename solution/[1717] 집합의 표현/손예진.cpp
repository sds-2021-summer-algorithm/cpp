#include <iostream>

using namespace std;

int N, M, parent[1000001];

int Find(int a) { //부모 찾기
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {  //집합 합치기
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb)
		return;
	parent[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
  //initialize parent
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> c >> a >> b;

		if (c == 0) {	//합집합 연산
			Union(a, b);
		}
		else {	//같은 집합에 포함되어있는지 확인
			if (Find(a) == Find(b)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}
}
