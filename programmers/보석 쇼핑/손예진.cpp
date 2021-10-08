#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

/*
* <idea>
* 1. sliding window 문제
* 2. set 사용해서 필요한 보석 모두 골랐는지 확인
* <difficulty>
* 마지막에 answer에 답을 대입 안해줘서 틀림 -> 출력으로 테스트 해보기
*/

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    vector<pair<int, int>> section;
    map<string, int> m;
    set<string> s, tmp;
    for (auto gem : gems) {
        s.insert(gem);
    }
    int min_len = gems.size();
    int left = 0, right = -1;
    while (true) {
        if (tmp.size() < s.size()) {
            if (++right >= gems.size())
                break;
            tmp.insert(gems[right]);
            m[gems[right]]++;
        }
        else {
            int len = right - left + 1;
            if (len <= min_len) {
                if (len < min_len) {
                    section.clear();
                    min_len = len;
                }
                section.push_back({ left + 1, right + 1 });
            }
            if (--m[gems[left]] == 0)
                tmp.erase(gems[left]);
            left++;
        }

    }
    sort(section.begin(), section.end());   //논리적으로 봤을 때는 안해도 됨 - 근데 불안해서 sort
    answer[0] = section[0].first;
    answer[1] = section[0].second;

    return answer;
}
