/*
Problem B: Delete every second node in linked list.
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
    int n, x;
    cin >> n;

    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    Node* curr = head;

    while (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        curr = curr->next;
    }

    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }

    return 0;
}
