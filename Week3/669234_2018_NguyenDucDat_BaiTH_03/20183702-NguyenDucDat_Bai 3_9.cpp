    #include<iostream>
using namespace std;
int N, K1, K2;
int x[200];
int L, c[200];
void solution(){
    for(int i = 1; i <= N; i++){
        cout << x[i];
    }
    cout << endl;
}
int check(int v, int k)
{
    if(k == 1) return 1;
    if(x[k-1] == 0) {
        if(N - k + 1 < K1) return 0;
        return v;
    }
    else {
        if(L < K1) return v;
        else if(L < K2) return 1;
        else return !v;
    }
}
void TRY(int k){
    for(int i = 0; i<=1;i++){
        if(check(i,k)){
            x[k] = i;
            if (x[k] == 1) L++;
            else {
                c[k] = L;
                L = 0;
            }
            // cout<<"x["<<k<<"]="<<i<<endl;
            if(k == N) solution();
            else TRY(k+1);
            if (x[k] == 1) L--;
            else L = c[k];
        }
    }
}
int main(){
    cin >> N >> K1 >> K2;
    TRY(1);
    return 0;
}

