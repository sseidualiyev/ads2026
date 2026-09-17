/*
Problem E: Delete the Middle Node
Output format
Print the n-1 remaining identifiers separated by single spaces, from the head of the list to its tail.
If n=1, the list becomes empty — print an empty line.
Examples
Input
5
10 20 30 40 50
Output
10 20 40 50
Input
4
1 2 3 4
Output
1 2 4
Input
1
42
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
    int n, val;
    if (!(cin >> n) || n <= 0) return 0;

    // PHASE 1: Build the linked list
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    // PHASE 2: Core Logic - Delete the middle node
    if (n == 1) {
        delete head; // Fix memory leak from original code
        cout << "\n";
        return 0;
    }

    Node* curr = head;
    int steps = (n / 2) - 1; // Calculate exactly how many steps to the node BEFORE the middle

    for (int i = 0; i < steps; i++) {
        curr = curr->next;
    }

    Node* temp = curr->next; // 1. Identify the middle node
    curr->next = temp->next; // 2. Bypass it
    delete temp;             // 3. Free the memory

    // PHASE 3: Print and clean up memory
    curr = head;
    while (curr != nullptr) {
        cout << curr->val << (curr->next ? " " : "");
        
        Node* temp = curr;
        curr = curr->next;
        delete temp; // Free the remaining nodes as we print them
    }
    cout << "\n";

    return 0;
}
