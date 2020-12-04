#include<iostream>
using namespace std;
int lucas(int n){
    if(n==0) return 2;
    if(n==1) return 1;
    return lucas(n-1) + lucas(n-2);
}
int main(){
    printf("Ho va ten: Nguyen Duc Dat\n");
    printf("MSSV: 20183702\n\n");
    int n;
    cin >> n;
    cout << lucas(n);
}
