#include <iostream>

using namespace std;

struct Node {
    int parent;
    double dist;

    Node() {
        this->parent = 0;
        this->dist = 0;
    }

    Node(int parent, double dist) {
        this->parent = parent;
        this->dist = dist;
    }
};

Node* tree;

int _find(int id);
void _union(int a, int b, int diff);
void set_weight(int src, int dst, int wgt);
void get_weight(int src, int dst);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    while (N != 0 && M != 0) {
        tree = new Node[N + 1];
        
        for (int i = 1; i <= N; i++) {
            tree[i].parent = i;
        }

        char cmd;
        int src, dst, wgt;
        for (int i = 1; i <= M; i++) {
            cin >> cmd;

            if (cmd == '!') {
                cin >> src >> dst >> wgt;
                set_weight(src, dst, wgt);
            }
            else {
                cin >> src >> dst;
                get_weight(src, dst);
            }
        }

        cin >> N >> M;
    }

    return 0;
}

int _find(int id) {
    if (tree[id].parent == id) {
        return id;
    }

    int rootId = _find(tree[id].parent);
    tree[id].dist += tree[tree[id].parent].dist; // root로부터 거리 누적합

    return tree[id].parent = rootId;
}

void _union(int a, int b, int diff) {
    int rootA = _find(a);
    int rootB = _find(b);

    if (rootA == rootB) return;

    // rootA + distA = A, A + diff = B = rootB + distB
    // rootB = B - distB = A + diff - distB
    tree[rootB].dist = tree[a].dist - tree[b].dist + diff;
    tree[rootB].parent = rootA;

    return;
}

void set_weight(int src, int dst, int wgt) {
    _union(src, dst, wgt);
}

void get_weight(int src, int dst) {
    if (_find(src) != _find(dst)) {
        cout << "UNKNOWN" << '\n';
    }
    else {
        cout << tree[dst].dist - tree[src].dist << '\n';
    }
}