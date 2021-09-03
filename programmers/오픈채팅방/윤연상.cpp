#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
map<string, string> idtoName;
vector<vector<string>> new_record;

vector<string> split(string s, char delim) {
    vector<string> ret;
    stringstream os(s);
    string tmp;

    while (getline(os, tmp, delim)) {
        ret.push_back(tmp);
    }
    return ret;
}

vector<string> solution(vector<string> record) {
    for (string& s : record) {
        vector<string> result = split(s, ' ');
        
        if (result[0] == "Enter" || result[0] == "Change") {
            idtoName[result[1]] = result[2];
        }

        new_record.push_back(result);
    }

    for (vector<string> v : new_record) {
        if (v[0] == "Enter") {
            string tmp = idtoName[v[1]];
            tmp.append("님이 들어왔습니다.");
            ans.push_back(tmp);
        }
        else if (v[0] == "Leave") {
            string tmp = idtoName[v[1]];
            tmp.append("님이 나갔습니다.");
            ans.push_back(tmp);
        }
    }

    return ans;
}