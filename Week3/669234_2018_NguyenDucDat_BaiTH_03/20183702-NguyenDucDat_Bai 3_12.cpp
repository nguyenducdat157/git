#include <bits/stdc++.h>
#define maxn 32
using namespace std;
int n, k, m;
map<int, vector<int> > e;
bool visited[maxn];
void init(){
    cin >> n >> k >> m;
    int u, v;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
        visited[i] = false;
}
int count_path(int u, int k){
    int res = 0;
    if (k == 0) return 1;
    visited[u] = true;
    for (auto v : e[u]){
        if (!visited[v])
            res += count_path(v, k - 1);
    }
    visited[u] = false;
    return res;
}

int main(){
    printf("Ho va ten: Nguyen Duc Dat\n");
    printf("MSSV: 20183702\n\n");
    init();
    int res = 0;
    for (int i = 1; i <= n; ++i){
        //if (!visited[i])
            res += count_path(i, k);
    }
    cout << res/2;

}
