#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
//완전 탐색

using namespace std;

set<int> tree[101];
bool visited[101];

int GetSize(int start) {   //송전탑 사이즈 반환
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int tree_size = 1;
    while (!q.empty()) {    //반드시 pop / visited = true 해주기!! 안 그러면 무한 반복 발생
        int now = q.front();
        q.pop();
        for (auto node : tree[now]) {
            if (!visited[node]) {
                q.push(node);
                visited[node] = true;
                tree_size++;
            }
        }
    }
    return tree_size;
}

int solution(int n, vector<vector<int>> wires) {    //개수의 차이 return
    int answer = 101;
    for (auto wire : wires) {
        tree[wire[0]].insert(wire[1]);
        tree[wire[1]].insert(wire[0]);
    }
    for (auto wire : wires) {
        //방문 배열 초기화
        memset(visited, false, sizeof(visited));
        //edge 끊기
        int node1 = wire[0], node2 = wire[1];
        tree[node1].erase(node2);
        tree[node2].erase(node1);

        //최솟값 갱신
        answer = min(abs(GetSize(wire[0]) - GetSize(wire[1])), answer);

        //edge 다시 연결
        tree[node1].insert(node2);
        tree[node2].insert(node1);
    }

    return answer;
}
