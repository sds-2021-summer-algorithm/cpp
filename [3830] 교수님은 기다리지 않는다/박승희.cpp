#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 100001

int n, m;

int parent[MAX];
long long gram[MAX];

int find(int a) {
	// root �� ��� �׳� �ڱ� �ڽ� return
	if (parent[a] == a) return a;

	// root�� �ƴϸ�
	// �ڽ��� root ã��, ���� ���� ������
	int tmp = find(parent[a]);
	gram[a] += gram[parent[a]];
	return parent[a] = tmp; // ������ union�� ���� root ����
	//return parent[a] = find(parent[a]);
}

// b�� a���� w�׷� ���̴�(b�� a�� ���� = diff)
void unionCheck(int a, int b, long long diff) {
	int aRoot = find(a);
	int bRoot = find(b);

	// �̹� ���� �׷��̸� ������ ����
	if (aRoot == bRoot) return;

	// ����
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

			// a�� b�� ���� ���̸� ����� �� �ִٸ� == union
			if (check == '!') {
				int a, b;
				long long c;
				cin >> a >> b >> c;
				unionCheck(a, b, c);
			}
			//  b�� a���� �󸶳� ���ſ����� ��� == find
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