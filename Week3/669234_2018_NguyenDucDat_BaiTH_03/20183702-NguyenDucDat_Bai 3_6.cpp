#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){

    //# Khử đệ quy
    while(b!=0){
        int sd = a%b;
        a = b;
        b = sd;
    }
    return a;

}

int main() {
    printf("Ho va ten: Nguyen Duc Dat\n");
    printf("MSSV: 20183702\n\n");
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
