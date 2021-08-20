#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int N;
int* input;
int** dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt", "r", stdin);

    cin >> N;

    input = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        if (input[i] > min(i, (N - 1) - i)) {
            cout << 0 << '\n';
            return 0;
        }
    }
    
    int maxHeight = (N + 1) / 2;
    dp = new int*[N];
    for (int i = 0; i < N; i++) {
        dp[i] = new int[maxHeight];
    }

    dp[0][0] = 1;
    int height;
    for (int idx = 1; idx < N; idx++) {
        maxHeight = min(idx, (N - 1) - idx);

        height = input[idx];
        if (height >= 0) {
            for (int d = -1; d <= 1; d++) {
                if (height + d < 0) continue;
                dp[idx][height] += dp[idx - 1][height + d];
                dp[idx][height] %= MOD;
            }
            continue;
        }
        
        for (height = 0; height <= maxHeight; height++) {
            for (int d = -1; d <= 1; d++) {
                if (height + d < 0) continue;
                dp[idx][height] += dp[idx - 1][height + d];
                dp[idx][height] %= MOD;
            }
        }
    }

    cout << dp[N - 1][0] << '\n';

    return 0;
}