/*
Problem G: Cyclic Shift to the end
Output format
Print the N words of the shifted poem, separated by single spaces.
Examples
Input
5 2
the show must go on
Output
must go on the show 
Input
5 3
another one bites the dust
Output
the dust another one bites 
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string x) : word(x), next(nullptr) {}
};

int main() {
    int n, k;
    if (!(cin >> n >> k) || n <= 0) return 0;

    // PHASE 1: Build the linked list
    string word;
    cin >> word;
    Node* head = new Node(word);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> word;
        tail->next = new Node(word);
        tail = tail->next;
    }

    // PHASE 2: Core Logic - Left Rotate the list
    k = k % n; // Remove redundant full rotations
    if (k > 0) {
        tail->next = head;     // 1. Connect the end to the start (make a circle)
        
        Node* curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next; // 2. Walk to the new tail
        }
        
        head = curr->next;     // 3. Set the node right after it as the new head
        curr->next = nullptr;  // 4. Break the circle
    }

    // PHASE 3: Print and clean up memory
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->word << (curr->next ? " " : "");
        
        Node* temp = curr;
        curr = curr->next;
        delete temp; // Free memory as we go
    }
    cout << "\n";

    return 0;
}
