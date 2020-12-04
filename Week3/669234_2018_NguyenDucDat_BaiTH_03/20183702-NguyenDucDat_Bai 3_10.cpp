#include<iostream>
using namespace std;
int x[200], Y[200];
int N, H, T;
void solution(int n){
    for(int i = 1; i <= n; i++){
        cout<<Y[i];
    }
    cout<<endl;
}

void ToHop (int i, int n, int h)  {
    if(h<=0 || n<h){
        for(int i = 1; i <= n; i++){
        Y[i] = 0;
        cout<<Y[i];
    }
    }
    else
    {
        for (int j = x[i-1] + 1; j <= n-h+i; j++)  {
        x[i] = j;
        Y[x[i]] = 0;
        if (i == h)
            solution(n);
        else
            ToHop(i+1,n,h);
        Y[x[i]] = 1;
    }
    }
}
int main(){
    printf("Ho va ten: Nguyen Duc Dat\n");
    printf("MSSV: 20183702\n\n");
    cin >> T;
    while (T--) {
        cin >> N >> H;
        for(int i = 1; i<=N; i++){
            Y[i] = 1;
        }
        ToHop(1, N, H);
        cout << endl;
    }
    return 0;
}
