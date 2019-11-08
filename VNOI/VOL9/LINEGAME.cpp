#include<iostream>
#include<vector>
#include<algorithm>

#define FOR(i,v,n) for(int i = v;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a;
    long int f[n+1][2];
    a.push_back(0);
    FOR(i,0,n){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    f[0][0] = f[0][1] = 0;
    FOR(i,1,n+1){
        f[i][0] = max(f[i-1][1] + a[i], f[i-1][0]);
        f[i][1] = max(f[i-1][0] - a[i], f[i-1][1]);
    }

    cout<< (f[n][0] > f[n][1] ? f[n][0] : f[n][1]) <<"\n";
    return 0;

}