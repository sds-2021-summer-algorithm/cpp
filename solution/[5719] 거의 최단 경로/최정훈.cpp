/*
 test input에서는 오류가 발생하지 않으나,
 백준 채점 시 '틀렸습니다'가 나옴.
*/

#include <iostream>
#include <vector>
#include <queue>
#define INFI 2147000000

using namespace std;

struct Edge {
    int id, cost;
    
    Edge() { id = 0; cost = 0; }
    Edge(int v, int p) { id = v; cost = p; }
};

struct Comparator {
    bool operator() (Edge &a, Edge &b) {
        return a.cost > b.cost;
    }
};

int N, M, S, D;
vector<vector<Edge>> adjList;
vector<vector<int>> parent;

int* dist;
bool** isShortest;

void dijkstra(int src);
void track_shortest_paths(int now, int end);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        cin >> S >> D;

        adjList = vector<vector<Edge>>(N);
        for (int i = 0; i < M; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            adjList[u].push_back(Edge(v, p));
        }
        
        parent = vector<vector<int>>(N);
        isShortest = new bool*[N];
        for (int i = 0; i < N; i++) {
            isShortest[i] = new bool[N];
        }
        
        dijkstra(S);
        track_shortest_paths(D, S);
        dijkstra(S);

        if (dist[D] == INFI) {
            cout << -1 << '\n';
        }
        else {
            cout << dist[D] << '\n';
        }
    }

    return 0;
}

void dijkstra(int src) {
    dist = new int[N];
    for (int i = 0; i < N; i++) {
        dist[i] = INFI;
    }

    priority_queue<Edge, vector<Edge>, Comparator> pq;
    pq.push(Edge(src, 0));
    dist[src] = 0;

    while (!pq.empty()) {
        Edge now = pq.top(); pq.pop();

        //if (now.cost > dist[now.id]) continue;

        for (Edge next : adjList[now.id]) {
            if (isShortest[now.id][next.id]) continue;

            int distNew = dist[now.id] + next.cost;

            if (dist[next.id] > distNew) {
                dist[next.id] = distNew;
                pq.push(Edge(next.id, dist[next.id]));

                parent[next.id].clear();
                parent[next.id].push_back(now.id);
            }
            else if (dist[next.id] == distNew) {
                parent[next.id].push_back(now.id);
            }
        }
    }
}

void track_shortest_paths(int now, int end) {
    if (now == end) return;

    for (int par : parent[now]) {
        isShortest[par][now] = true;
        track_shortest_paths(par, end);
    }
}