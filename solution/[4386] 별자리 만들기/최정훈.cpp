#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Pos {
    int id; 
    float x, y;
    
    Pos() { }
    Pos(int id, float x, float y) {
        this->id = id; 
        this->x = x;
        this->y = y;
    }
};

struct Edge {
    Pos* src; Pos* dst; 
    double dist;

    Edge() { }
    Edge(Pos* a, Pos* b, double d) {
        src = a; dst = b; dist = d;
    }
};

struct Compare {
    bool operator() (Edge a, Edge b) {
        return a.dist > b.dist;
    }
};

double pos_distance(Pos* a, Pos* b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

int N, edgeCount, edgeLimit;
double totalDist;

int* parent;
Pos* posList;
priority_queue<Edge, vector<Edge>, Compare> edgeList;

int _find(int a);
void _union(int a, int b);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    posList = new Pos[N];
    parent = new int[N];

    float x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        posList[i] = Pos(i, x, y);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            Pos* a = &posList[i];
            Pos* b = &posList[j];
            double dist = pos_distance(a, b);
            edgeList.push(Edge(a, b, dist));
            edgeList.push(Edge(b, a, dist));
        }
        parent[i] = i;
    }

    totalDist = 0;
    edgeCount = 0;
    edgeLimit = N - 1;
    while (!edgeList.empty()) {
        if (edgeCount == edgeLimit) break;

        Edge edge = edgeList.top(); edgeList.pop();

        if (_find(edge.src->id) != _find(edge.dst->id)) {
            _union(edge.src->id, edge.dst->id);
            totalDist += edge.dist;
            edgeCount++;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << totalDist << endl;

    return 0;
}

int _find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = _find(parent[a]);
}

void _union(int a, int b) {
    int rootA = _find(a);
    int rootB = _find(b);

    parent[rootB] = rootA;
}