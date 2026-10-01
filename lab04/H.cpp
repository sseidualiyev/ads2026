/*
Problem H: Greater Sum Tree.
Use BST to calculate suffix sum.
Input
9
4 1 6 0 2 3 5 7 8
Output
8 15 21 26 30 33 35 36 36
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

void convert(Node* root, long long& s) {
    if (!root) return;
    convert(root->r, s);
    s += root->v;
    root->v = s;
    convert(root->l, s);
}

void print(Node* root) {
    if (!root) return;
    print(root->r);
    cout << root->v << ' ';
    print(root->l);
}

int main() {
    int n; cin >> n;
    Node* root = 0;
    while (n--) {
        int x; cin >> x;
        root = insert(root, x);
    }
    long long s = 0;
    convert(root, s);
    print(root);
}
