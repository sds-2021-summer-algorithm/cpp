#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m;
    int num1 = 0, num2 = 0;
    //모든 문자 소문자로 변환
    std::transform(str1.begin(), str1.end(), str1.begin(), (int(*)(int))tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), (int(*)(int))tolower);

    for (int i = 0; i < str1.length() - 1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) { //앞 뒤 글자 모두 영문자라면 map에 개수 추가
            string ele = str1.substr(i, 2);
            m[ele]++;
            num1++;
        }
    }
    int inter = 0;
    for (int i = 0; i < str2.length() - 1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) { //앞 뒤 글자 모두 영문자라면 map에 존재하는 문자열인지 확인
            string ele = str2.substr(i, 2);
            if (m[ele]) {
                inter++;    //교집합 개수
                m[ele]--;   //교집합으로 판단된 문자열은 삭제
            }
            num2++;
        }
    }

    if (num1 == 0 && num2 == 0) //A, B 모두 공집합일 경우 65536 반환
        return 65536;
    int sum = num1 + num2 - inter;  //합집합 = A집합 + B집합 - 교집합
    return floor(((double)inter / sum) * 65536);
}
