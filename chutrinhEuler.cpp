// code by NMK
#include <bits/stdc++.h>

#define MAX 50
#define TRUE 1
#define FALSE 0

using namespace std;

int A[MAX][MAX], n, u = 1;

void Init() {
    ifstream file("CTEULER.IN");
    if (!file.is_open()) {
        cerr << "Khong the mo file CTEULER.IN" << endl;
        return;
    }

    file >> n;
    cout << "\nSo dinh do thi: " << n;
    cout << "\nMa tran ke:";
    
    for (int i = 1; i <= n; i++) {
        cout << "\n";
        for (int j = 1; j <= n; j++) {
            file >> A[i][j];
            cout << A[i][j] << " ";
        }
    }

    file.close();
}

int Kiemtra() {
    int s, d = 0;
    for (int i = 1; i <= n; i++) {
        s = 0;
        for (int j = 1; j <= n; j++)
            s += A[i][j];
        if (s % 2) d++;
    }
    return (d > 0) ? FALSE : TRUE;
}

void Euler_Cycle(int u) {
    int v, x, top, dCE;
    int stack[MAX], CE[MAX];
    top = 1; 
    stack[top] = u;
    dCE = 0;

    do {
        v = stack[top];
        x = 1;

        while (x <= n && A[v][x] == 0)
            x++;

        if (x > n) {
            dCE++;
            CE[dCE] = v;
            top--;
        } else {
            top++;
            stack[top] = x;
            A[v][x] = 0; // Xóa c?nh
            A[x][v] = 0; // Xóa c?nh ngu?c
        }
    } while (top != 0);

    cout << "\nCo chu trinh Euler: ";
    for (x = dCE; x > 0; x--)
        cout << CE[x] << " ";
}

int main() {
    Init();
    if (Kiemtra())
        Euler_Cycle(u);
    else
        cout << "\nKhong co chu trinh Euler";

    return 0;
}

