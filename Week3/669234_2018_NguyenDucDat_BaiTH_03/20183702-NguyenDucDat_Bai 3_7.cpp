
#include <bits/stdc++.h>
using namespace std;
int L = 0;
int n, k;
int x[25];

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    printf("Ho va ten: Nguyen Duc Dat\n");
    printf("MSSV: 20183702\n\n");
    cin >> n >> k;
    stack<state> s;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        cout<<"top.j = "<<top.j<<endl;
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }

        if (top.j > 0)
            L = top.old_L;
        if (top.j > 1){
            s.pop();
            continue;
        }
        if (L + 1 < k || top.j == 0){
            ///x[k] = v
            x[top.i] = top.j;
            //cout<<"x["<<top.i<<"] = "<<x[top.i]<<endl;
            top.old_L = L;
            L = top.j ? L + 1 : 0;
            s.push(state(top.i + 1, 0));
        }
        ++top.j;
    }
    return 0;
}
