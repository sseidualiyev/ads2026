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
    int n, m, val;

    // PHASE 1: Build List A
    cin >> n;
    Node* headA = nullptr;
    Node* tailA = nullptr;
    if (n > 0) {
        cin >> val;
        headA = tailA = new Node(val);
        for (int i = 1; i < n; i++) {
            cin >> val;
            tailA->next = new Node(val);
            tailA = tailA->next;
        }
    }

    // PHASE 1.5: Build List B
    cin >> m;
    Node* headB = nullptr;
    Node* tailB = nullptr;
    if (m > 0) {
        cin >> val;
        headB = tailB = new Node(val);
        for (int i = 1; i < m; i++) {
            cin >> val;
            tailB->next = new Node(val);
            tailB = tailB->next;
        }
    }

    // PHASE 2: Core Logic - Merge the two lists
    Node dummy(0);         // The "dummy node" trick simplifies the logic
    Node* tail = &dummy;   // 'tail' will build the new merged list
    Node* a = headA;
    Node* b = headB;

    // Compare and attach the smaller node
    while (a != nullptr && b != nullptr) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next; // Advance the tail pointer
    }

    // Attach whatever is left over (one of them will be nullptr)
    tail->next = (a != nullptr) ? a : b;

    // PHASE 3: Print and clean up memory
    Node* curr = dummy.next; // The real merged list starts after the dummy node
    while (curr != nullptr) {
        cout << curr->val << (curr->next ? " " : "");
        
        Node* temp = curr;
        curr = curr->next;
        delete temp; // Free memory as we go
    }
    cout << "\n";

    return 0;
}
