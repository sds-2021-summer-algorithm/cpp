#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
* <idea>
* [최솟값]
* 1. dp를 사용 -> 가능한 모든 수 조합에 대해{2 + (n - 2), 3 + (n - 3), ... } 
* 기존에 구한 최솟값들의 조합으로 최솟값 도출 -> 만약 필요한 dp 값이 없다면 새로 구하기
* 
* [최댓값]
* 1. 무조건 "1"과 "7"의 조합 -> 왜냐하면 자릿수가 클수록 큰 수이기 때문에 최대한 적은 값으로 많은 숫자 추가할 수 있게
* 2. 홀수일 때는 7로 시작, 나머지 1 / 짝수일 때는 모든 자리 1
* <difficulty>
* 1. "0"을 사용해 최솟값을 만들 수 있기 때문에 예외가 많았음
* 예를 들어 "13"의 경우 최솟값은 68인데 "0"을 반드시 사용하게 하면 최솟값이 "80"이 됨
* -> 따라서 "0"을 사용할 때와 안 할 때에 대해 모두 수를 구해보고 둘 중 작은 값을 최종 답으로 출력
*/

int T;
string dp[101];

string ToPosNum(string str) {   //0이 맨 앞에 있지 않은 최소 숫자로 만들기
    sort(str.begin(), str.end());
    if (str[0] == '0')
        for (int i = 0; i < str.length(); i++) {
            if (str[i] - '0' > 0) {
                swap(str[0], str[i]);
                break;
            }
        }
    return str;
}

bool isSmaller(string str1, string str2) {  //tmp, ans 크기 비교
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] - '0' < str2[i] - '0')   //tmp가 ans보다 작음
            return true;
        else if (str1[i] - '0' > str2[i] - '0') //ans가 tmp보다 작음 
            return false;
    }
    return false; //ans가 tmp보다 작음 
}

string UpdateAns(string tmp, string ans) {
    if (ans.length() == 0 || tmp.length() < ans.length()) {   //길이가 더 짧은 경우
        ans = tmp;
    }
    else if (tmp.length() == ans.length()) {  //만들 수 있는 숫자가 더 작을 경우
        ans = ToPosNum(ans);
        tmp = ToPosNum(tmp);
        if (isSmaller(tmp, ans))    //tmp가 ans보다 작음
            ans = tmp;
    }
    return ans;
}

string MakeMin(int n) { //가장 작은 수 만들기
    if (dp[n] != "")
        return dp[n];
    string ans = "";
    int left = 2, right = n - 2;
    while (left <= right) {
        if (dp[left] == "")
            MakeMin(left);
        if (dp[right] == "")
            MakeMin(right);
        string tmp;
        tmp = dp[left] + dp[right];
        if (left == 6 || right == 6) {  //더 채워야하는 숫자가 6인 경우 "0" 이용해서 최솟값 만들어보기
            string tmp_zero;
            if (left == 6)
                tmp_zero = "0" + dp[right];
            else
                tmp_zero = "0" + dp[left];
            tmp = UpdateAns(tmp, tmp_zero); //"0"을 사용할 때와 "6"을 사용할 때 중 최솟값 반환
        }

        ans = UpdateAns(tmp, ans);

        left++; right--;
    }

    ans = ToPosNum(ans);
    return dp[n] = ans;
}
void MakeMax(int n) { //가장 큰 수 만들기
    string ans = "";
    if (n % 2) {   //홀수
        cout << "7";
        n -= 3;
    }
    for (int i = 1; i <= (n / 2); i++)
        cout << "1";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[2] = "1"; dp[3] = "7"; dp[4] = "4"; dp[5] = "2"; dp[6] = "6"; dp[7] = "8";   //2 이상의 숫자에 대해 가장 작은 값 부여 (0은 예외)
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << MakeMin(n) << " ";
        MakeMax(n);
        cout << "\n";
    }
}
