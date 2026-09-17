/*
Problem B: Kuanyshbek
Kuanyshbek has been studying how multithreading works in operating systems. He wrote a program that starts a single thread which writes to a single file.
Being careless, he actually launched two threads with different parameters writing into the same file.
The OS lets only one thread write at a time, so the two threads took turns: the first record came from thread one, the second from thread two, the third from thread one again, and so on.
Kuanyshbek only needs the data of the first thread. Help him throw away everything the second thread wrote — that is, every element standing at an even position, counting from 1.
Solve this problem with a linked list: build the list, then delete every second node.

Input format
The first line contains one integer N — how many records ended up in the file.
The second line contains N integers separated by single spaces — the records in the order they were written.

Output format
Print the values that are left in the list after every second one has been deleted, separated by single spaces — that is, the records at positions 1,3,5...
Examples
Input
5
1 2 3 4 5
Output
1 3 5 
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int main() {
    int n, val;
    if (!(cin >> n) || n <= 0) return 0;

    // PHASE 1: Build the linked list
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head; // 'tail' makes it clear we are appending to the end

    for (int i = 1; i < n; ++i) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    // PHASE 2: Core Logic - Delete alternating nodes
    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        Node* temp = curr->next;  // 1. Identify the node to delete
        curr->next = temp->next;  // 2. Bypass it in the chain
        delete temp;              // 3. Free the memory
        curr = curr->next;        // 4. Advance to the next surviving node
    }

    // PHASE 3: Print and clean up the remaining nodes
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
