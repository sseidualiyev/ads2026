/*
Problem F: Merge Two Sorted Lists
Print n+m integers in non-decreasing order, separated by single spaces — the merged waiting list from its head to its tail.
If both lists are empty, print an empty line.
Examples
Input
3 1 3 5
3 2 4 6
Output
1 2 3 4 5 6
Input
0
3 2 4 6
Output
2 4 6
Input
0
0
Output

*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int main() {
    int n, m, x;
    cin >> n;

    Node *headA = nullptr, *tailA = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!headA)
            headA = tailA = node;
        else {
            tailA->next = node;
            tailA = node;
        }
    }

    cin >> m;

    Node *headB = nullptr, *tailB = nullptr;

    for (int i = 0; i < m; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!headB)
            headB = tailB = node;
        else {
            tailB->next = node;
            tailB = node;
        }
    }

    Node dummy(0);
    Node* tail = &dummy;

    Node* a = headA;
    Node* b = headB;

    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    tail->next = a ? a : b;

    while (dummy.next) {
        cout << dummy.next->val << ' ';
        dummy.next = dummy.next->next;
    }
}
