/*
Problem I: Doubly linked list
commands:
add_front <title> — add a book to the beginning of the list. Print ok.
add_back <title> — add a book to the end of the list. Print ok.
erase_front — remove the first book. Print the title of the removed book.
erase_back — remove the last book. Print the title of the removed book.
front — print the title of the first book, without removing it.
back — print the title of the last book, without removing it.
clear — remove every book from the list. Print ok.
exit — print goodbye and stop.

If the list is empty when erase_front, erase_back, front or back is called, there is nothing to report — print error instead and leave the list as it is.
The commands clear and exit always work, even on an empty list.

Input format
Each line of the input contains one command from the list above. The commands add_front and add_back are followed on the same line, after a single space, by the title of the book:
a non-empty string of at most 20 characters, each of them a Latin letter, a digit or an underscore.
The last command of the input is always exit, and it is the only occurrence of exit.

Output format
For each command print its answer on a separate line, as described above.
Examples
Input
add_front Harry_Potter
add_back Light
erase_front
erase_back
erase_front
add_front Happy
back
add_back Autumn
add_front Alchemy
clear
front
exit
Output
ok
ok
Harry_Potter
Light
error
ok
Happy
ok
ok
ok
error
goodbye
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    Node* next;
    Node* prev;

    Node(string x) : title(x), next(nullptr), prev(nullptr) {}
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    string cmd, title;

    while (cin >> cmd) {

        if (cmd == "add_front") {
            cin >> title;

            Node* node = new Node(title);

            if (!head) {
                head = tail = node;
            } else {
                node->next = head;
                head->prev = node;
                head = node;
            }

            cout << "ok\n";
        }

        else if (cmd == "add_back") {
            cin >> title;

            Node* node = new Node(title);

            if (!tail) {
                head = tail = node;
            } else {
                node->prev = tail;
                tail->next = node;
                tail = node;
            }

            cout << "ok\n";
        }

        else if (cmd == "erase_front") {
            if (!head) {
                cout << "error\n";
            } else {
                Node* temp = head;
                cout << temp->title << '\n';

                head = head->next;

                if (head)
                    head->prev = nullptr;
                else
                    tail = nullptr;

                delete temp;
            }
        }

        else if (cmd == "erase_back") {
            if (!tail) {
                cout << "error\n";
            } else {
                Node* temp = tail;
                cout << temp->title << '\n';

                tail = tail->prev;

                if (tail)
                    tail->next = nullptr;
                else
                    head = nullptr;

                delete temp;
            }
        }

        else if (cmd == "front") {
            if (head)
                cout << head->title << '\n';
            else
                cout << "error\n";
        }

        else if (cmd == "back") {
            if (tail)
                cout << tail->title << '\n';
            else
                cout << "error\n";
        }

        else if (cmd == "clear") {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }

            tail = nullptr;
            cout << "ok\n";
        }

        else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
}
