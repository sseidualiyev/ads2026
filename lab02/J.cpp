/*
inserts — add a node on position p.
remove — remove the node from position p.
print — print all values of list separated by a space.
replace — move the node from position p1 and to position p2. Position p2 is considered at the moment after its removal.
reverse — reverse the entire list.
cyclic_left — do a cyclic shift to the left x times.
cyclic_right — do a cyclic shift to the right x times.
Also, there are indicated the commands that need to be executed in order for the door to open. It is known that each command calls a specific function. Help Zoro to restore functions.
Input format
Each line of input starts with integer which indicates command:
If command 0, exit the program.
If command 1, then the same line of input contains numbers x and p. Add a new node with value x to the position p. It is guaranteed that p does not exceed the length of the list.
If command 2, then the same line of input contains number p. Delete the node from position p. It is guaranteed that p is less than the length of the list.
If command 3, print the whole list. Print -1 if list is empty.
If command 4, then the same line of input contains numbers p1 and p2. Move node from position p1 to position p2. 
Position p2 is counted from the moment when we have already retrieved the node from position p1. It is guaranteed that p1 and p2 are less than the length of the list.
if command 5, reverse whole list.
If command 6, then the same line of input contains number x. Make left cyclic shift x times. It is guaranteed that x is less than the length of the list.
If command 7, then the same line of input contains number x. Make right cyclic shift x times. It is guaranteed that x is less than the length of the list.
Subtasks
(20%) Implement each function in O(N^2) or faster.
(20%) Implement functions inserts, remove, print and replace in O(N).
(20%) Implement functions inserts, remove, print and reverse in O(N).
(20%) Implement functions inserts, remove, print, cyclic_left and cyclic_right in O(N).
(20%) Implement all of the functions in O(N).

Output format
For each print command, print all values of the list separated by single spaces.
Note
Each function except print must return the head of the linked list.
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// --- CORE OPERATIONS ---

Node* insert(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    
    Node* curr = head;
    for (int i = 0; i < p - 1; i++) curr = curr->next; // Walk to node BEFORE insert
    
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* curr = head;
    for (int i = 0; i < p - 1; i++) curr = curr->next; // Walk to node BEFORE delete
    
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << "\n";
        return;
    }
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << (curr->next ? " " : "");
        curr = curr->next;
    }
    cout << "\n";
}

// --- ADVANCED OPERATIONS ---

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head; // No movement needed

    // STEP 1: Extract the node from p1
    Node* target = nullptr;
    if (p1 == 0) {
        target = head;
        head = head->next;
    } else {
        Node* curr = head;
        for (int i = 0; i < p1 - 1; i++) curr = curr->next;
        target = curr->next;
        curr->next = target->next;
    }

    // STEP 2: Insert the extracted node at p2
    if (p2 == 0) {
        target->next = head;
        return target;
    }
    
    Node* curr = head;
    for (int i = 0; i < p2 - 1; i++) curr = curr->next;
    target->next = curr->next;
    curr->next = target;
    
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || head->next == nullptr) return head;

    // 1. Find the tail and calculate length (n)
    Node* tail = head;
    int n = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        n++;
    }

    x = x % n;
    if (x == 0) return head;

    // 2. Walk to the new tail (x steps from start)
    Node* curr = head;
    for (int i = 1; i < x; i++) curr = curr->next;

    // 3. Re-link to form the rotated list
    Node* newHead = curr->next;
    curr->next = nullptr; // Break circle
    tail->next = head;    // Connect old tail to old head

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || head->next == nullptr) return head;

    // A Right Rotation of 'x' is just a Left Rotation of 'n - x'
    Node* tail = head;
    int n = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        n++;
    }
    
    x = x % n;
    if (x == 0) return head;
    
    return cyclic_left(head, n - x); // Re-use the left rotation logic!
}

// --- MAIN COMMAND LOOP ---

int main() {
    Node* head = nullptr;
    int command, x, p, p1, p2;

    while (cin >> command && command != 0) {
        switch (command) {
            case 1: cin >> x >> p;  head = insert(head, x, p); break;
            case 2: cin >> p;       head = remove(head, p); break;
            case 3:                 print(head); break;
            case 4: cin >> p1 >> p2; head = replace(head, p1, p2); break;
            case 5:                 head = reverse(head); break;
            case 6: cin >> x;       head = cyclic_left(head, x); break;
            case 7: cin >> x;       head = cyclic_right(head, x); break;
        }
    }

    // Clean up memory before exiting
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
