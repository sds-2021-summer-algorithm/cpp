#include <bits/stdc++.h>

using namespace std;

int v, e; int cnt = 0;
int order[100001];
vector<vector<int>> adjlist;

struct edge {
	int start, end;
	edge(int _s, int _e) : start(_s), end(_e) {};
};
struct compare {
	bool operator() (edge &a, edge &b){
		if (a.start > b.start) return true;
		else if (a.start < b.start) return false;
		else {
			if (a.end > b.end)return true;
			else return false;
		}
	}
};
priority_queue<edge, vector<edge>, compare> ans;


int dfs(int node, int parent);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 입력 및 초기화
	cin >> v >> e;
	for (int i = 0; i <= v; i++) {
		vector<int> tmp;
		adjlist.push_back(tmp);
	}
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (order[i] == 0)
			dfs(i, 0);
	}

	cout << ans.size() << endl;
	while (!ans.empty()) {
		edge now = ans.top(); ans.pop();
		cout << now.start << ' ' << now.end << '\n';
	}
}

int dfs(int node, int parent) {
	order[node] = ++cnt;
	int retval = order[node];

	for (int i = 0; i < adjlist[node].size(); i++) {
		int next = adjlist[node][i];
		if (order[next] == 0) {
			int low = dfs(next, node);
			if (low > order[node])
				ans.push(edge(min(node, next), max(node, next)));
			retval = min(retval, low);
		}
		else if (next != parent) {
			retval = min(retval, order[next]);
		}
	}

	return retval;
}