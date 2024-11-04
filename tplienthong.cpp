#include <iostream>
#include <fstream>
#include <vector>
#define MAX 50
#define TRUE 1
#define FALSE 0

using namespace std;

int A[MAX][MAX], n, chuaxet[MAX], solt = 0;

void Init() {
    ifstream file("dothi.in");
    if (!file.is_open()) {
        cerr << "\nKhong mo duoc file dothi.in" << endl;
        return;
    }

    file >> n;
    cout << "\nSo dinh do thi: " << n;

    for (int i = 1; i <= n; i++) {
        cout << "\n";
        chuaxet[i] = TRUE;
        for (int j = 1; j <= n; j++) {
            file >> A[i][j];
            cout << A[i][j] << " ";
        }
    }

    file.close();
}

void BFS(int u) {
    int queue[MAX], low = 1, high = 1, s, t;
    queue[low] = u;
    chuaxet[u] = FALSE;

    while (low <= high) {
        s = queue[low];
        low++;
        cout << s << " ";

        for (t = 1; t <= n; t++) {
            if (A[s][t] && chuaxet[t]) {
                high++;
                queue[high] = t;
                chuaxet[t] = FALSE;
            }
        }
    }
}

void DFS(int u) {
    cout << u << " ";
    chuaxet[u] = FALSE;

    for (int v = 1; v <= n; v++) {
        if (A[u][v] && chuaxet[v]) {
            DFS(v);
        }
    }
}

int main() {
    int u;
    Init();

    for (u = 1; u <= n; u++) {
        if (chuaxet[u]) {
            solt++;
            cout << "\nTP.Lien thong " << solt << ": ";
            BFS(u); // Ho?c có th? g?i DFS(u);
        }
    }

    return 0;
}

