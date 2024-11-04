// code by NMK
#include <bits/stdc++.h>
#define MAX 50
#define TRUE 1
#define FALSE 0

using namespace std;

int A[MAX][MAX], n, chuaxet[MAX];

void Init() {
    ifstream file("DOTHI.IN");
    if (!file.is_open()) {
        cerr << "Khong the mo file DOTHI.IN" << endl;
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

void DFS_Dequi(int u) {
    cout << u << " ";
    chuaxet[u] = FALSE;

    for (int v = 1; v <= n; v++) {
        if (A[u][v] && chuaxet[v]) {
            DFS_Dequi(v);
        }
    }
}

void DFS_Stack(int u) {
    int Stack[MAX], dau = 0; 
    Stack[dau++] = u;       
    chuaxet[u] = FALSE;     
    cout << u << " ";

    while (dau > 0) {
        int s = Stack[--dau];
        bool found = false;   
        for (int t = 1; t <= n; t++) {
            if (chuaxet[t] && A[s][t]) {
                cout << t << " ";  
                chuaxet[t] = FALSE; 
                Stack[dau++] = s;   
                Stack[dau++] = t;   
                found = true;      
                break;          
            }
        }
    }
}

int main() {
    Init();
    int u;
    cout << "\nDinh bat dau duyet: ";
    cin >> u;
    DFS_Stack(u);
    return 0;
}

