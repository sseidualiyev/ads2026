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
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    if (n == 1) return 0;

    Node* curr = head;

    for (int i = 0; i < n / 2 - 1; i++)
        curr = curr->next;

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
}
