#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int A[MAX][MAX], n, chuaxet[MAX], truoc[MAX], s, t;

void Init(void) {
    // Ð?c d? li?u t? file và kh?i t?o các bi?n
    int i, j;
    ifstream file("dothi.in");
    if (!file) {
        cerr << "Khong the mo file dothi.in" << endl;
        exit(1);
    }
    
    file >> n;
    cout << "\nSo dinh do thi: " << n;
    for (i = 1; i <= n; i++) {
        chuaxet[i] = 1; // Ðánh d?u chua duy?t
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
    chuaxet[u] = 0;   // Ðánh d?u dã duy?t
    for (int v = 1; v <= n; v++) {
        if (A[u][v] && chuaxet[v]) {
            truoc[v] = u; // Ghi nh? d?nh tru?c
            DFS(v);
        }
    }
}

void BFS(int i) { // Thu?t toán BFS
    queue<int> q; // S? d?ng hàng d?i STL
    q.push(i); // Thêm d?nh vào hàng d?i
    chuaxet[i] = 0; // Ðánh d?u d?nh dã duy?t

    while (!q.empty()) {
        int u = q.front(); // L?y d?nh d?u hàng d?i
        q.pop(); // Lo?i b? d?nh kh?i hàng d?i
        cout << u << " "; // In ra d?nh dang duy?t

        for (int v = 1; v <= n; v++) {
            if (A[u][v] && chuaxet[v]) { // Ki?m tra n?u có c?nh và chua duy?t
                q.push(v); // Thêm d?nh vào hàng d?i
                truoc[v] = u; // Ghi nh? d?nh tru?c
                chuaxet[v] = 0; // Ðánh d?u d?nh dã duy?t
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

