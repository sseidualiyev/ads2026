/*
Problem C: Database
The KBTU database has crashed and the list of all students came back damaged: some names got duplicated.
The way the crash worked, all copies of the same name always ended up in consecutive positions.
For instance, the name “Dana” may occupy positions 2,3,4, but it can never occupy positions 2,3,5, because those are not consecutive.
Keep only the first record of every group of equal neighbours, without changing the order of the list.

Input format
The first line contains one integer N — the number of records.
Each of the next N lines contains one name: a non-empty string of at most 20 Latin letters.
Both uppercase and lowercase letters may occur, and they are considered different: “Aa” and “aA” are two different names.
All records of the same name are guaranteed to occupy consecutive positions.

Output format
On the first line print one integer — how many students are left after the duplicates are removed.
Then print those names, one per line, in the same order in which they appear in the input.

Examples
Input
5
Alice
Dana
Dana
Dana
Bob
Output
3
Alice
Dana
Bob
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> answer;
    string prev = "";
    string curr;

    // PHASE 1: Read and filter consecutive duplicates
    for (int i = 0; i < n; i++) {
        cin >> curr;

        // If the current word is different from the one right before it, save it
        if (curr != prev) {
            answer.push_back(curr);
        }
        
        // Update previous word for the next loop iteration
        prev = curr; 
    }

    // PHASE 2: Print results
    cout << answer.size() << "\n";
    for (const string& name : answer) {
        cout << name << "\n";
    }

    return 0;
}
