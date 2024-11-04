// code by NMK
#include <bits/stdc++.h>

#define MAX 50
#define TRUE 1
#define FALSE 0

using namespace std;

int A[MAX][MAX], n, chuaxet[MAX];

void Init() {
    ifstream file("dothi.in");
    if (!file.is_open()) {
        cerr << "Khong the mo file dothi.in" << endl;
        return;
    }

    file >> n;
    cout << "\nSo dinh do thi: " << n << endl;

    for (int i = 1; i <= n; i++) {
        chuaxet[i] = TRUE;
        for (int j = 1; j <= n; j++) {
            file >> A[i][j];
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    file.close();
}

void BFS(int u) {
    int queue[MAX], low = 1, high = 1, v;
    queue[low] = u;
    chuaxet[u] = FALSE;

    cout << "\nKet qua: ";
    while (low <= high) {
        u = queue[low]; 
        low++; 
        cout << u << " "; 
        for (v = 1; v <= n; v++) {
            if (A[u][v] && chuaxet[v]) {
                high++; 
                queue[high] = v; 
                chuaxet[v] = FALSE; 
            }
        }
    }
}

int main() {
    Init();
    int u;
    cout << "\nDinh bat dau duyet: ";
    cin >> u;
    BFS(u);
    return 0;
}

