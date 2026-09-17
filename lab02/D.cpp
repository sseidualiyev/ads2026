/*
TASK ABOUT REVERSING THE LINKED LIST
Input format
The first line contains one integer n — the number of songs in the playlist.
The second line contains n integers a1,a2,an — the identifiers of the songs, listed from the head of the list to its tail.

Output format
Print n integers separated by single spaces — the identifiers of the songs from the head of the reversed list to its tail.
Examples
Input
5
1 2 3 4 5
Output
5 4 3 2 1
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

    // PHASE 2: Core Logic - Reverse the linked list
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next; // 1. Save the next node so we don't lose the chain
        curr->next = prev;           // 2. Reverse the current node's pointer backwards
        prev = curr;                 // 3. Move 'prev' one step forward
        curr = nextNode;             // 4. Move 'curr' one step forward
    }
    head = prev; // Update head to the last node processed

    // PHASE 3: Print and clean up memory
    curr = head;
    while (curr != nullptr) {
        cout << curr->val << (curr->next ? " " : "");
        
        Node* temp = curr;
        curr = curr->next;
        delete temp; // Free memory as we go
    }
    cout << "\n";

    return 0;
}
