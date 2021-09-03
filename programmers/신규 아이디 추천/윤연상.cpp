#include <bits/stdc++.h>

using namespace std;

string ans = "";
deque<char> str;

void make_str() { for (char& ch : str) ans.push_back(ch); }
void remove_dot() {
	while (!str.empty()) {
		if (str.front() == '.') str.pop_front();
		else break;
	}
	while (!str.empty()) {
		if (str.back() == '.') str.pop_back();
		else break;
	}
}
char tolower(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 'a';
	}
	return ch;
}

string solution(string new_id) {
	// 1단계 : 대문자 => 소문자
	for (char& ch : new_id)
		str.push_back(tolower(ch));
	
	// 2단계 : 허용문자 외 제거
	for (int i = 0; i < (int)new_id.size(); i++) {
		char ch = str.front(); str.pop_front();

		if (ch >= '0' && ch <= '9') str.push_back(ch);
		else if (ch >= 'a' && ch <= 'z') str.push_back(ch);
		else if (ch == '-' || ch == '_' || ch == '.') str.push_back(ch);
	}

	// 3단계 : 연속된 . 제거
	char prev = '.';
	deque<char> tmp;
	for (char& ch : str) {
		if (prev == '.' && ch == '.')
			continue;
		tmp.push_back(ch);
		prev = ch;
	}
	str = tmp;

	// 4단계 : 앞뒤의 . 제거
	remove_dot();

	// 5단계 : 빈 문자열 처리
	if (str.empty()) str.push_back('a');

	int Len = (int)str.size();

	if (Len > 15) {		// 6단계 : 긴 문자열 처리
		for (int i = 0; i < Len - 15; i++)
			str.pop_back();
	}
	else if (Len < 3) {	// 7단계 : 짧은 문자열 처리
		for (int i = 0; i < 3 - Len; i++)
			str.push_back(str.back());
	}

	remove_dot();
	make_str();

	return ans;
}