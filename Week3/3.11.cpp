#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3;

int N, T;
int c[MAX][MAX];
int visited[MAX], x[MAX], numBetweenCity;
long long cost;
long long best;
int cmin;
vector<int> route;
int lastCity;

void solution() {
    if (c[x[numBetweenCity]][lastCity] != 0) {
        int curr = cost + c[x[numBetweenCity]][lastCity];
        if (curr < best) best = curr;
    }
}

void init() {
    while (!route.empty()) {
        route.pop_back();
    }
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    string str;
    getline(cin, str);
    str += ' ';
    int tmp = (int)str[0] - 48;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] != ' ' && str[i - 1] != ' ') {
            tmp = tmp * 10 + (int)str[i] - 48;
        } else if (str[i] != ' ' && str[i - 1] == ' '){
            tmp = (int)str[i] - 48;
        } else {
            route.push_back(tmp);
        }
    }
    best = INT_MAX;
    cost = 0;
    numBetweenCity = route.size() - 1;
    x[1] = route[0];
    visited[route[0]] = 1;
    lastCity = route[route.size() - 1];
}

bool check(int city, int k) {
    if (visited[city]) return false;
    if (c[x[k-1]][city] == 0) return false;
    return true;
}

void TRY(int k) {
    if (cost + cmin * (numBetweenCity - k + 2) < best) {
        for (int i = 1; i < route.size() - 1; i++) {
            if (check(route[i], k)) {
                x[k] = route[i];
                //cout << x[k] << endl;
                cost += c[x[k-1]][x[k]];
                visited[x[k]] = 1;
                if (k == numBetweenCity) solution();
                else TRY(k+1);
                cost -= c[x[k-1]][x[k]];
                visited[x[k]] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> T;
    cmin = INT_MAX;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> c[i][j];
            cmin = min(c[i][j], cmin);
        }
    }
    /// read the enter from keyboard
    string str;
    getline(cin, str);
    while(T--) {
        init();
        TRY(2);
        if (best == INT_MAX) cout << 0 << endl;
        else cout << best << endl;
    }
    return 0;
}

