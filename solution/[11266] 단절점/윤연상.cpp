#include <bits/stdc++.h>

using namespace std;

int v, e; 
int cnt = 0;
int order[10001];
bool isAns[10001];
vector<vector<int>> adjlist;

int dfs(int node, bool isRoot);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 0; i <= v; i++) {
		vector<int> v;
		adjlist.push_back(v);
		isAns[i] = false;
	}
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (order[i] == 0)
			dfs(i, true);
	}

	int ans = 0;
	for (int i = 1; i <= v; i++) {
		if (isAns[i]) ans++;
	}
	cout << ans << endl;
	for (int i = 1; i <= v; i++) {
		if (isAns[i]) cout << i << ' ';
	}
}

int dfs(int node, bool isRoot) {
	order[node] = ++cnt;
	int retval = order[node];

	int child = 0;
	for (int i = 0; i < adjlist[node].size(); i++) {
		int next = adjlist[node][i];
		if (order[next] == 0) {
			child++;
			int low = dfs(next, false);
			if (!isRoot && low >= order[node])
				isAns[node] = true;
			retval = min(low, retval);
		}
		else {
			retval = min(retval, order[next]);
		}
	}

	if (isRoot && child > 1)
		isAns[node] = true;

	return retval;
}