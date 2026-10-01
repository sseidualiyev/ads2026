/*
Problem C: Christmas Gifts
find node and print subtree nodes
Input
5
4 2 7 1 3
2
Output
2 1 3 
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int v; Node *l, *r;
    Node(int x) : v(x), l(0), r(0) {}
};

void insert(Node*& root, int x) {
    if (!root) { root = new Node(x); return; }
    if (x < root->v) insert(root->l, x);
    else insert(root->r, x);
}

Node* find(Node* root, int x) {
    while (root) {
        if (root->v == x) return root;
        root = x < root->v ? root->l : root->r;
    }
    return 0;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->v << ' ';
    preorder(root->l);
    preorder(root->r);
}

int main() {
    int n; cin >> n;
    Node* root = 0;

    while (n--) {
        int x; cin >> x;
        insert(root, x);
    }

    int x; cin >> x;
    if (Node* root = find(root, x)) preorder(root);
}
