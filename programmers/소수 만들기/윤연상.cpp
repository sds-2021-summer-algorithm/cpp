#include <vector>
#include <iostream>
using namespace std;

int ans = 0;
int picked[3];
bool isPrime[3001];

// 에레토스테네스의 체를 이용하여 소수를 구함
void find_prime_number() {
    for (int i = 2; i < 3000; i++)
        isPrime[i] = true;

    for (int i = 2; i < 3000; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j < 3000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
// dfs를 이용하여 3개의 수를 선택 후 해당 수가 소수인지 검사
void pick_number(int idx, int cnt, vector<int> nums) {
    if (cnt == 3) {
        int sum = picked[0] + picked[1] + picked[2];
        if (isPrime[sum]) 
            ans++;
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        picked[cnt] = nums[i];
        pick_number(i + 1, cnt + 1, nums);
    }
}

int solution(vector<int> nums) {
    find_prime_number();

    pick_number(0, 0, nums);

    return ans;
}
