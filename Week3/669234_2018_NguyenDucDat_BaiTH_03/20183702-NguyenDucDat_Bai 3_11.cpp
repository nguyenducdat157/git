#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n,r, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int cur = 0; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX][MAX];
int t[MAX][MAX];
int s[MAX];
int inTour[MAX][MAX];

void input()
{
    cin>>n>>r;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
                cmin = min(cmin, c[i][j]);
        }
    }
    for(int i = 1; i<=r; i++)
    {
        string str;
        if(i==1) cin.ignore();
        getline(cin, str);

        s[i] = 0;
        for(int j = 0; j<str.length(); j++)
        {
            if(str[j]!=' ')
            {
                s[i]++;
                t[i][s[i]] = str[j] - '0';
                inTour[i][t[i][s[i]]] = 1;
            }
        }

    }


}
void Clear(){
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
    }
    cur = 0;
    best = INT_MAX;
}
int Done(int k)
{
    for(int i = 2; i<=s[k];i++){
        if(!mark[t[k][i]]) return 0;
    }
    return 1;
}

void TRY(int k, int j)
{
    for(int i = 1; i<=n; i++)
    {
        if(!mark[i] && c[x[j][k-1]][i] && inTour[j][i])
        {
            x[j][k] = i;
            mark[i] = 1;
            cur = cur + c[x[j][k-1]][x[j][k]];
            if(Done(j) && x[j][k]==t[j][s[j]])
            {
                if(best>cur)
                {

                    best = cur;
                }

            }
            else TRY(k+1,j);
            mark[i] = 0;
            cur = cur - c[x[j][k-1]][x[j][k]];
        }
    }
}
int main()
{
    printf("Ho va ten: Nguyen Duc Dat\n");
    printf("MSSV: 20183702\n\n");
    input();

    for(int i = 1; i<=r;i++){
         x[i][1] = t[i][1];
         mark[t[i][1]] = 1;
         TRY(2,i);
         if(best==INT_MAX) cout<<0<<endl;
         else cout << best << endl;
         Clear();
    }

    return 0;
}
