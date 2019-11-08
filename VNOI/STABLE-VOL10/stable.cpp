#include<iostream>
#include<vector>
#include<queue>

#define rep(i,n) for(int i = 0;i<n;i++)
#define MAX 10005;

using namespace std;


void solve(int s,vector<int> e[],int distance[],int stable[],int n){
    int visited[n] = {0};
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    int d = 0;
    while(!q.empty()){
        s = q.front();
        q.pop();
        d ++;
        for(int i = 0;i < e[s].size();i++){
            int v = e[s][i];
            if(distance[v] > d){
                distance[v] = d;
                stable[v] = 1;
            }
            else if(distance[v] == d)
                stable[v]++;
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
            
        }
    }
}
void addedge(vector<int> e[],int u,int v){
    e[u].push_back(v);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,s;
    cin >> n >> m >> s;
    
    vector<int> e[n + 1];
    rep(i,m){
        int u,v;
        cin >> u >> v;
        addedge(e,u, v);
    }
    int distance[n+1];
    int stable[n+1] = {1};
    rep(i,n+1){
        distance[i] = MAX; 
        stable[i] = 1;
    }
    solve(s,e,distance,stable,n);
    int count = 0;
    rep(i,n+1)
        if(stable[i] >= 2)
            count++;
    cout<<count<<"\n";
    return 0;
}