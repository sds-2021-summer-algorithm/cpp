#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Pmax 14

using namespace std;

/*
* <idea>
* 1. 거슬러 올라가서 root 찾기
* 2. 두 정점간의 LCA 구하기
* <difficulty>
* 1. 갱신 잘 해줘야됨
* 2. LCA 흐름 && 조건 정확히 기억하기
*/

int T, N, root;
int depth[10001];
int child[10001];
int parent[10001][Pmax];
vector<int> tree[10001];

int GetRoot(int node) { //거슬러 올라가서 root 찾기
    if (child[node] > 0)
        node = GetRoot(child[node]);
    return node;
}

void SetDepth(int node) {
    for (int i = 0; i < tree[node].size(); i++) {
        int now = tree[node][i];
        parent[now][0] = node;
        if (depth[now] == 0) {
            depth[now] = depth[node] + 1;
            SetDepth(now);
        }
    }
}

void SetParent() {
    for (int i = 1; (1 << i) <= N; i++) { //아무리 커도 N번째 부모
        for (int j = 1; j <= N; j++) {    //모든 node에 대해
            parent[j][i] = parent[parent[j][i - 1]][i - 1]; //j의 i번째 부모 = j의 (i - 1)번째 부모의 (i - 1)번째 부모
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) //항상 a가 더 낮은 위치에
        swap(a, b);

    if (depth[a] != depth[b]) {   //a와 b의 깊이가 다르다면 맞춰주기
        for (int i = Pmax; i >= 0; i--) {   //2진수로 맞춰주기
            if (depth[a] - (1 << i) >= depth[b])
                a = parent[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = Pmax; i >= 0; i--) { //마찬가지로 2진수로 맞춰주기 - 단 동일한 노드에 도달하기 직전에 멈춰야됨
        if (depth[a] - (1 << i) > 0 && parent[a][i] != parent[b][i]) {  //갱신될 node의 depth는 최소 1 (왜냐면 root의 depth가 1)
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        memset(depth, 0, sizeof(depth));
        memset(parent, 0, sizeof(parent));
        memset(child, 0, sizeof(child));
        root = 0;
        for (int i = 1; i <= N; i++)
            tree[i].clear();
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            child[b] = a;
            if (root == 0)
                root = a;
        }
        root = GetRoot(root);
        depth[root] = 1;
        SetDepth(root);
        SetParent();
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}
