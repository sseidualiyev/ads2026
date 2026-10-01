/*
Problem B: get subtree
The main concept is finding a node in a BST and then counting all nodes below it.
Input
7
4 2 6 1 3 5 7
4
Output
7
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        if (root->v == x) return t;
        root = x < root->v ? root->l : root->r;
    }
    return 0;
}

int size(Node* t) {
    if (!root) return 0;
    return 1 + size(root->l) + size(root->r);
}

int main() {
    int n; cin >> n;
    Node* root = 0;
    while (n--) {
        int x; cin >> x;
        insert(root, x);
    }
    int x; cin >> x;
    cout << size(find(root, x)) << '\n';
}
