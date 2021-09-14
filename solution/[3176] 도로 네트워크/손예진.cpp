#include <iostream>
#include <vector>
#include <algorithm>
#define Pmax 17

using namespace std;

int N, K, root;
int indegree[100001], depth[100001], parent[100001][Pmax + 1], Min[100001][Pmax + 1], Max[100001][Pmax + 1];
vector<pair<int, int>> graph[100001];

void SetDepth(int d, int p, int idx) {
	parent[idx][0] = p;
	depth[idx] = d;
	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i].first, len = graph[idx][i].second;
		if (next == p)
			continue;
		Min[next][0] = Max[next][0] = len;
		SetDepth(d + 1, idx, next);
	}
}

void SetParent() {
	for (int i = 1; (1 << i) <= N; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			Min[j][i] = min(Min[parent[j][i - 1]][i - 1], Min[j][i - 1]);
			Max[j][i] = max(Max[parent[j][i - 1]][i - 1], Max[j][i - 1]);
		}
	}
}

vector<int> LCA(int a, int b) {
	vector<int> ans;
	int ans_min = 1000001, ans_max = 0;
	//항상 a의 depth가 b의 depth보다 크도록 유지
	if (depth[a] < depth[b])
		swap(a, b);
	if (depth[a] != depth[b]) {
		for (int i = Pmax; i >= 0; i--) {
			if (depth[a] - (1 << i) >= depth[b]) {
				ans_min = min(ans_min, Min[a][i]);
				ans_max = max(ans_max, Max[a][i]);
				a = parent[a][i];
			}
		}
	}
	if (a != b) {
		for (int i = Pmax; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				ans_min = min(ans_min, min(Min[a][i], Min[b][i]));
				ans_max = max(ans_max, max(Max[a][i], Max[b][i]));
				a = parent[a][i]; b = parent[b][i];
			}
		}
		ans_min = min(ans_min, min(Min[a][0], Min[b][0]));
		ans_max = max(ans_max, max(Max[a][0], Max[b][0]));
	}

	ans.push_back(ans_min); ans.push_back(ans_max);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
		indegree[a]++; indegree[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 2) {
			root = i;
			break;
		}
	}

	SetDepth(0, 0, root);
	SetParent();

	cin >> K;
	for (int i = 0; i < K; i++) {
		int d, e;
		cin >> d >> e;
		vector<int> ans = LCA(d, e);
		cout << ans[0] << " " << ans[1] << "\n";
	}
}
