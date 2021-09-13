#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, indegree[32001];
vector<vector<int>> target(32001);
vector<int> ans;
queue<int> q;

void DAG() {
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int index = q.front();
			ans.push_back(index);
			q.pop();
			int s = target[index].size();
			for (int j = 0; j < s; j++) {
				int b = target[index][j];
				if (--indegree[b] == 0) {
					q.push(b);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		indegree[b]++;
		target[a].push_back(b);
	}
	for(int i = 1; i <= N; i++){
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	DAG();
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}
