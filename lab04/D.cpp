/*
Problem D: Aureole
BST level/depth Level-Order Traversal BFS
Input
1
1
Output
1
1
Input
5
4 3 5 1 2
Output
4
4 8 1 2
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <queue>
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

int main() {
    int n; cin >> n;
    Node* root = 0;

    while (n--) {
        int x; cin >> x;
        insert(root, x);
    }

    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        int k = q.size();
        long long sum = 0;

        while (k--) {
            Node* t = q.front(); q.pop();
            sum += t->v;
            if (t->l) q.push(t->l);
            if (t->r) q.push(t->r);
        }
        cout << sum << ' ';
    }
}
