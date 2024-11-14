// code by NMK
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<int>> ds(n); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                ds[i].push_back(j + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "List(" << (i + 1) << ") = ";
        for (int j : ds[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

