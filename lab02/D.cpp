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

    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
}
