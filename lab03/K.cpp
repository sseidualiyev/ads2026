/*
Problem K: 2d array snake format
find values in array and print their indices.
Input
5 // number of values needed to find
10 15 13 8 23 // values that are to be found
3 4 // size of snake array
25 23 20 19 // values
13 15 17 18
12 10 9 8
Output
2 1 // position of 10 in array is 3rd row 2nd column and minus 1 gives us 2 and 1
1 1 // 15 is 2nd row 2nd column
1 0 // 13 is 2nd row 1st column
2 3 // 8 is 3rd row 4th column
0 1 // 23 is in the 1st row and 2nd column
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int searchRow(const vector<long long>& row, long long target, bool isIncreasing) {
    int left = 0;
    int right = row.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (row[mid] == target) return mid; 

        if (isIncreasing) {
            if (row[mid] < target) left = mid + 1;
            else right = mid - 1;
        } else {
            if (row[mid] > target) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int q, n, m;
    cin >> q;

    vector<long long> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i];

    cin >> n >> m;
    vector<vector<long long>> matrix(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> matrix[i][j];
    }

    for (long long target : queries) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            bool isIncreasing = (i % 2 == 1); 

            int col = searchRow(matrix[i], target, isIncreasing);

            if (col != -1) {
                cout << i << " " << col << '\n';
                found = true;
                break; 
            }
        }

        if (!found) cout << -1 << '\n';
    }

    return 0;
}
