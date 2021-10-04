#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int dp[2001][2001];
vector<int> nums;

int palindrome(int s, int e) {
    int left = s, right = e;
    while (left < right) {  //양끝부터 dp 적용하면서 팰린드롬 여부 확인
        if (dp[left][right] != -1)
            return dp[s][e] = dp[left][right];
        if (nums[left] != nums[right])
            return dp[s][e] = dp[left][right] = 0;
        left++; right--;
    }
    return dp[s][e] = 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nums.push_back(-1);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    //dp 배열 초기화
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++)
        dp[i][i] = 1;

    cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        cout << palindrome(s, e) << "\n";
    }
}
