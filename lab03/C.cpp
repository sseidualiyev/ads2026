/*
Problem C: Debugging
Input format
First line consists of integers N and M - number of blocks and mistakes.
The second line contains N integers ai - number of lines in the i-th block.
Each of the next M lines contains one integer bi - number of line where the i-th mistake was made. 
In other words, every mistake is guaranteed to fall inside the code, so the answer always exists.
Output format
Print M lines, the i-th line must contain the number of block in which the i-th mistake was made.
Examples
Input
2 1
3 4
5
Output
2
Input
3 3
5 7 6
5
10
15
Output
1
2
3
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int findb(const vector<int>& lines, int target) {
    int left = 0, right = lines.size() - 1;

    while (left < right) {
        int mid = (right + left) / 2;

        if (lines[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left + 1; 
}

int main() {
    int n, m;
    cin >> n;

    vector<int> lines(n);
    int currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        currentSum += size;
        lines[i] = currentSum;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        cout << findb(lines, query) << "\n";
        }
    return 0;
}
