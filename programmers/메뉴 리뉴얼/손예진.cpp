#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int max_ordered;
map<string, int> m;

void Combination(string order, string str, int index, int course) {
    if (str.length() == course) {
        sort(str.begin(), str.end());
        m[str]++;
        max_ordered = (m[str] > max_ordered ? m[str] : max_ordered);
        return;
    }
    if (index >= order.length()) return;
    Combination(order, str, index + 1, course);
    str.push_back(order[index]);
    Combination(order, str, index + 1, course);
}

vector<string> solution(vector<string> orders, vector<int> courses) {
    vector<string> answer;
    for (int k = 0; k < courses.size(); k++) {
        int course = courses[k];
        max_ordered = 2;
        m.clear();
        for (int i = 0; i < orders.size(); i++) {
            string order = orders[i];
            Combination(order, "", 0, course);
        }
        auto iter = m.begin();
        while (iter != m.end()) {
            if (iter->second == max_ordered)
                answer.push_back(iter->first);
            iter++;
        }
    } 
    sort(answer.begin(), answer.end());

    return answer;
}
