/*
Problem C: Database;
Keep only unique names, duplicates are guaranteed to come in consecutive positions.
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> ans;
    string prev, curr;

    for (int i = 0; i < n; i++) {
        cin >> curr;

        if (curr != prev)
            ans.push_back(curr);

        prev = curr;
    }

    cout << ans.size() << '\n';

    for (string x : ans)
        cout << x << '\n';
}
