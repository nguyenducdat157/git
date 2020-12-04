#include <bits/stdc++.h>
using namespace std;

int T, N, H, L, x[20];

bool check(int v, int k) {
    if(L==H && v==1 ) return false;
    if(L<H && H-L > N-k + 1) return false;
    if(k==N && H-L==1 && v==0 ) return false;
    return true;
}

void printSolution() {
    for (int i = 1; i <= N; i++) {
        cout << x[i];
    }
    cout << endl;
}

void TRY(int k) {
    for (int v = 0; v <= 1; v++) {
        if (check(v, k)) {
            x[k] = v;
            if (x[k] == 1) L++;
            if (k == N) printSolution();
            else TRY(k + 1);
            if (x[k] == 1) L--;
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> H;
        TRY(1);
        cout << endl;
    }

    return 0;
}
