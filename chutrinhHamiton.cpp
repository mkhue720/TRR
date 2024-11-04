#include <iostream>
#include <fstream>
#include <vector>

#define MAX 50
#define TRUE 1
#define FALSE 0

using namespace std;

int A[MAX][MAX], C[MAX], B[MAX];
int n, d;

void Init() {
    ifstream file("CCHMTON.IN");
    if (!file.is_open()) {
        cerr << "\nKhong co file input" << endl;
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
    for (int i = 1; i <= n; i++)
        C[i] = 0; // Kh?i t?o m?ng C
}

void Result() {
    cout << "\n";
    for (int i = n; i >= 0; i--)
        cout << B[i] << " ";
    d++;
}

void Hamilton(int *B, int *C, int i) {
    for (int j = 1; j <= n; j++) {
        if (A[B[i - 1]][j] == 1 && C[j] == 0) {
            B[i] = j;
            C[j] = 1;
            if (i < n)
                Hamilton(B, C, i + 1);
            else if (B[i] == B[0])
                Result();
            C[j] = 0; // Ðánh d?u l?i d?nh j là chua du?c duy?t
        }
    }
}

int main() {
    B[0] = 1; // B?t d?u t? d?nh 1
    d = 0; // Kh?i t?o bi?n d?m
    Init();
    Hamilton(B, C, 1); // B?t d?u duy?t t? d?nh th? hai
    if (d == 0)
        cout << "\nKhong co chu trinh Hamilton" << endl;

    return 0;
}

