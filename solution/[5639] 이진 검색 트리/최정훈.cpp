#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) { 
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert_node(Node* node, Node* newNode) {
    if (node == nullptr) {
        return node = newNode;
    }
    
    if (newNode->data < node->data) {
        node->left = insert_node(node->left, newNode);
    }
    else {
        node->right = insert_node(node->right, newNode);
    }
    
    return node;
}

void print_post(Node* node) {
    if (node->left != nullptr) {
        print_post(node->left);
    }
    if (node->right != nullptr) {
        print_post(node->right);
    }
    cout << node->data << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt", "r", stdin);

    Node* root = nullptr;
    int value;

    while (cin >> value) {
        Node* tmp = new Node(value);
        root = insert_node(root, tmp);
    }

    print_post(root);

    return 0;
}