/**********************************************************************
작성일 : 2021-08-25
작성자 : 윤연상
문제 :
	간선들의 입력을 받아서 해당 그래프의 트리 여부를 출력(노드가 없어도 트리)
		1. 루트는 들어오는 간선이 없다(indegree = 0)
		2. 루트 노드를 제외한 모든 노드는 반드시 단 하나의 들어오는 간선이 존재한다.
		3. 루트에서 다른 노드로 가는 경로는 반드시 가능하며, 유일하다. 이는 루트를 제외한 모든 노드에 성립해야 한다.
풀이 :
	문제의 조건이 불충분해서 조금 방황했던 문제, 공집합을 고려하는 것이 함정이였음
	애초에 노드 번호의 범위가 없고 랜덤으로 입력되기 때문에 map과 set을 자료구조를 사용
	루트를 제외한 노드는 indegree가 1이여야함
	set은 모든 노드를 저장, map은 indegree 정보를 저장
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(m*n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

set<int> node;
map<int, int> indegree;

bool _input() {
	set<int>().swap(node);
	map<int, int>().swap(indegree);

	while (1) {
		int u, v; cin >> u >> v;

		if (u == 0 && v == 0) 
			break;
		else if (u == -1 && v == -1) 
			return false;

		node.insert(u);
		node.insert(v);

		indegree[v]++;
	}
	return true;
}

bool isTree() {
	int nodesize = node.size();
	int insize = indegree.size();

	if (nodesize == 0)	// 공집합은 무조건 트리
		return true;
	else if (nodesize - insize != 1)	// 루트의 개수는 반드시 1개
		return false;

	map<int, int>::iterator iter;
	for (iter = indegree.begin(); iter != indegree.end(); iter++) {	// indegree 검사
		if (iter->second != 1)
			return false;
	}

	return true;
}

int main(void) {
	fastio;

	int tc = 1;

	while (_input()) {
		if (isTree())
			cout << "Case " << tc << " is a tree.\n";
		else
			cout << "Case " << tc << " is not a tree.\n";

		tc++;
	}

	return 0;
}