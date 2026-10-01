/*
Problem I: More One Night
find leaves in bst (nodes which have no children).
Input
1
1
Output
1
Input
5
4 3 5 1 2
Output
2
*/
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int v; Node *l, *r;
    Node(int x) : v(x), l(0), r(0) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->v) root->l = insert(root->l, x);
    else root->r = insert(root->r, x);
    return root;
}

int leaves(Node* root) {
    if (!root) return 0;
    if (!root->l && !root->r) return 1;
    return leaves(root->l) + leaves(root->r);
}

int main() {
    int n; cin >> n;
    Node* root = 0;
    while (n--) {
        int x; cin >> x;
        root = insert(root, x);
    }
    cout << leaves(root);
}
