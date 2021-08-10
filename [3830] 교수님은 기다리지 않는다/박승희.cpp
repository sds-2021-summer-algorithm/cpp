#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 100001

int n, m;

int parent[MAX];
long long gram[MAX];

int find(int a) {
	// root 인 경우 그냥 자기 자신 return
	if (parent[a] == a) return a;

	// root가 아니면
	// 자신의 root 찾고, 무게 차이 구하자
	int tmp = find(parent[a]);
	gram[a] += gram[parent[a]];
	return parent[a] = tmp; // 기존의 union과 같이 root 갱신
	//return parent[a] = find(parent[a]);
}

// b가 a보다 w그램 무겁다(b와 a의 차이 = diff)
void unionCheck(int a, int b, long long diff) {
	int aRoot = find(a);
	int bRoot = find(b);

	// 이미 같은 그룹이면 같으면 종료
	if (aRoot == bRoot) return;

	// 갱신
	gram[bRoot] = (gram[a] - gram[b]) + diff;
	parent[bRoot] = aRoot;

	return;
}


int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		memset(parent, 0, sizeof(parent));
		memset(gram, 0, sizeof(gram));

		for (int i = 1; i <= n; ++i) parent[i] = i;

		for (int i = 0; i < m; ++i) {
			char check; cin >> check;

			// a와 b의 무게 차이를 계산할 수 있다면 == union
			if (check == '!') {
				int a, b;
				long long c;
				cin >> a >> b >> c;
				unionCheck(a, b, c);
			}
			//  b가 a보다 얼마나 무거운지를 출력 == find
			else if (check == '?') {
				int a, b;
				cin >> a >> b;
				if (find(a) == find(b)) cout << (gram[b] - gram[a]) << '\n';
				else cout << "UNKNOWN" << '\n';
			}
		}
	}

	return 0;
}