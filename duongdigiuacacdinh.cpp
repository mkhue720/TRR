#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int A[MAX][MAX], n, chuaxet[MAX], truoc[MAX], s, t;

void Init(void) {
    // �?c d? li?u t? file v� kh?i t?o c�c bi?n
    int i, j;
    ifstream file("dothi.in");
    if (!file) {
        cerr << "Khong the mo file dothi.in" << endl;
        exit(1);
    }
    
    file >> n;
    cout << "\nSo dinh do thi: " << n;
    for (i = 1; i <= n; i++) {
        chuaxet[i] = 1; // ��nh d?u chua duy?t
        truoc[i] = 0;   // Ghi nh? d?nh tru?c
        cout << "\n";
        for (j = 1; j <= n; j++) {
            file >> A[i][j];
            cout << A[i][j] << " ";
        }
    }
    file.close();
}

void DFS(int u) {
    cout << u << " "; // In ra d?nh dang duy?t
    chuaxet[u] = 0;   // ��nh d?u d� duy?t
    for (int v = 1; v <= n; v++) {
        if (A[u][v] && chuaxet[v]) {
            truoc[v] = u; // Ghi nh? d?nh tru?c
            DFS(v);
        }
    }
}

void BFS(int i) { // Thu?t to�n BFS
    queue<int> q; // S? d?ng h�ng d?i STL
    q.push(i); // Th�m d?nh v�o h�ng d?i
    chuaxet[i] = 0; // ��nh d?u d?nh d� duy?t

    while (!q.empty()) {
        int u = q.front(); // L?y d?nh d?u h�ng d?i
        q.pop(); // Lo?i b? d?nh kh?i h�ng d?i
        cout << u << " "; // In ra d?nh dang duy?t

        for (int v = 1; v <= n; v++) {
            if (A[u][v] && chuaxet[v]) { // Ki?m tra n?u c� c?nh v� chua duy?t
                q.push(v); // Th�m d?nh v�o h�ng d?i
                truoc[v] = u; // Ghi nh? d?nh tru?c
                chuaxet[v] = 0; // ��nh d?u d?nh d� duy?t
            }
        }
    }
}

void Duongdi(void) {
    if (truoc[t] == 0) {
        cout << "\nKhong ton tai duong di" << endl;
        return;
    }
    cout << "\nDuong di: ";
    int j = t;
    cout << j;
    while (truoc[j] != s) {
        cout << " <= " << truoc[j];
        j = truoc[j];
    }
    cout << " <= " << s << endl; 
}

int main(void) {
    Init();
    cout << "\nDinh dau: "; cin >> s;
    cout << "\nDinh cuoi: "; cin >> t;
//    cout << "DFS: " << endl;
//    DFS(s); 
//    Duongdi(); 
    cout << "BFS: " << endl;
    BFS(s); 
    Duongdi(); 
    return 0;
}

