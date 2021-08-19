#include <iostream>
#define MAX_N 1025

using namespace std;

int N, M;
int map[MAX_N][MAX_N];
int sum[MAX_N][MAX_N];

void update(int x, int y, int diff);
int query(int x1, int y1, int x2, int y2);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> map[r][c];
            sum[r][c] = map[r][c] + sum[r][c - 1]; // accumulate each row
        }
    }

    int w, x, y, c, x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        cin >> w;

        if (w == 0) {
            cin >> x >> y >> c;
            update(x, y, c); // update row sum
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1, y1, x2, y2) << '\n';
        }
    }

    return 0;
}

void update(int x, int y, int value) {
    int diff = value - map[x][y];

    for (int c = y; c <= N; c++) {
        sum[x][c] += diff;
    }
    map[x][y] = value; // change number
}

int query(int x1, int y1, int x2, int y2) {
    int result = 0;
    for (int r = x1; r <= x2; r++) {
        result += sum[r][y2] - sum[r][y1 - 1];
    }
    return result;
}