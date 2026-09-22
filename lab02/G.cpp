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
    cin >> n >> k;

    if (n <= 0) return 0;

    string x;
    cin >> x;

    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    k %= n;

    if (k) {
        tail->next = head;       // make circle

        Node* curr = head;
        for (int i = 1; i < k; i++)
            curr = curr->next;

        head = curr->next;       // new head
        curr->next = nullptr;    // break circle
    }

    while (head) {
        cout << head->word << ' ';
        head = head->next;
    }
}
