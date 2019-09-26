#include<iostream>

#define rep(i,n) for(int i = 0;i<n;i++)

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,s;
    cin >> n >> m >> s;
    int graph[n+1][n+1];
    rep(i,n+1) rep(j,n+1) graph[i][j] = -1;
    rep(i,n){
        int u,v;
        cin >> u >> v;
        graph[u][v];
    }

}