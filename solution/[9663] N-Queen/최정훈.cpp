#include <iostream>
#define MAX_N 15

using namespace std;

int N, total = 0;
int columns[MAX_N]; // columns[row] = row에서 선택된 col

void put_queen(int row);
bool check_vaild(int row);

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;

    put_queen(0);    // 0번 row부터 시작
    cout << total << '\n';

    return 0;
}

void put_queen(int row) {
    // 마지막 row를 넘어가면
    if (row == N) {
        total++;
        return;
    }

    // 현재 row의 모든 col에 대해
    for (int col = 0; col < N; col++) {
        columns[row] = col;  // col 선택

        // queen이 가능한 경우, go
        if (check_vaild(row)) {
            put_queen(row + 1);
        }
    }
}

bool check_vaild(int row) {
    // 이전 row에 대해
    for (int r = 0; r < row; r++) {
        // 같은 col에 있거나, 대각선(col 차이와 row 차이가 같을 때)인 경우
        if (columns[row] == columns[r] || abs(columns[row] - columns[r]) == row - r) {
            return false;
        }
    }
    // 가능한 col인 경우
    return true;
}