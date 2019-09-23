#include<iostream>
#include<algorithm>

#define rep(i,n) for(int i = 0;i<n;i++)
#define SZ 1005

using namespace std;

int main(){
    int n,m;
    int a[SZ],b[SZ], f[SZ][SZ];

    cin >> n >> m;
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];

    rep(i,m) if(a[0] == b[i]) f[0][i] = 1;
    rep(i,n) if(b[0] == a[i]) f[i][0] = 1;

    for(int i = 1;i < n;i++)
        for(int j = 1;j < m;j++){
            if(i == 1 || j == 1){
                if(a[i] == b[j])
                    f[i][j] = max(1 ,max( f[i-1][j], f[i][j-1]) );
                else f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
            else if(a[i] == b[j] )
                f[i][j] = max(f[i-2][j-2] + 1, max(f[i-1][j], f[i][j-1]) );
            else
                f[i][j] = max(f[i-1][j], f[i][j-1]);

        // 4 9 2 4
        // 1 9 7 3 4



        }

    cout<<f[n-1][m-1]<<"\n";
    return 0;
}