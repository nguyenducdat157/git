#include <bits/stdc++.h>
using namespace std;

int n, K1, K2;
int mem[200];

int countPlan(int N) {
    if (mem[N]) return mem[N]; /// memoization recursive technique
    /// stop condition
    if (N == 0) return 1;
    if (N < K1 && N != 0) return 0;

    for (int i = K1; i <= K2; i++) {
        mem[N] += countPlan(N - i - 1);
    }
    if (N <= K2) mem[N]++;
    return mem[N];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n >> K1 >> K2;
    cout << countPlan(n - 1) + countPlan(n);
    return 0;
}
