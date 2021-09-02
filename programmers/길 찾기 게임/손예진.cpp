#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct node {
    int n, y, x;
    node* left = nullptr;
    node* right = nullptr;
};

bool cmp(node n1, node n2) {    //node 정의되기 전에 함수 정의해서 unknown-type됨
    if (n1.y == n2.y) {
        return n1.x < n2.x;
    }
    return n1.y > n2.y;
}

vector<node> tree;

void SetNode(node *root, int idx) { //tree 채우기
    int n = tree[idx].n, x = tree[idx].x, y = tree[idx].y;
    node* parent = root;
    node* child = root;
    while (true) {
        if (x < parent->x) {
            if (parent->left == nullptr) {
                parent->left = &tree[idx];
                break;
            }
            parent = parent->left;
        }
        else {
            if (parent->right == nullptr) {
                parent->right = &tree[idx];
                break;
            }
            parent = parent->right;
        }
    }
}

vector<int> ans1, ans2;

void PreOrder(node *ptr) {    //전위 순회
    if (ptr == nullptr)
        return;
    ans1.push_back(ptr->n);
    PreOrder(ptr->left);
    PreOrder(ptr->right);
}

void PostOrder(node* ptr) { //후위 순회
    if (ptr == nullptr)
        return;
    PostOrder(ptr->left);
    PostOrder(ptr->right);
    ans2.push_back(ptr->n);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for (int i = 0; i < nodeinfo.size(); i++) {
        node n;
        n.n = i + 1; 
        n.x = nodeinfo[i][0]; 
        n.y = nodeinfo[i][1];
        tree.push_back(n);
    }
    sort(tree.begin(), tree.end(), cmp);    //tree의 상하, 좌우 순으로 원소 정렬

    node* root = &tree[0];
    for (int i = 1; i < tree.size(); i++) {
        SetNode(root, i);
    }
    PreOrder(root);
    PostOrder(root);
    answer.push_back(ans1);
    answer.push_back(ans2);

    return answer;
}
