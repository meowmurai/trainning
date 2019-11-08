#include<iostream>
#include<vector>
#include<string.h>
#include<deque>


#define FOR(i,v,n) for(int i = v;i < n;i++)
#define MAX 10000;
using namespace std;

    int n,m,s,t;
    vector<int> *g;
    int visited[10000] = {0};
    vector<int> trace(10000,-1);
    vector<int> pos(10000,-1);
    vector<int> path;

void find_path(int r,int d){
    deque<int> q;
    q.push_back(r);
    trace[r] = r;
    while(!q.empty()){
        int v = q.front();
        if(v == d) break;
        q.pop_front();
        for(int i : g[v]){
            if(trace[i] == -1){
                trace[i] = v;
                q.push_back(i);
            }
        }
    }
    int i = d;
    while(i!= r){
        path.push_back(i);
        i = trace[i];
    }
    path.push_back(r);
    for(int i = 0, j = path.size() - 1; i < j; i++,j--){
        int tmp = path[i];
        path[i] = path[j];
        path[j] = tmp;
    }
    return;
}
int BFS(int s){
    deque<int> q;
    int r = -1;
    q.push_back(s);
    visited[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(int i : g[u]){
            if(!visited[i] && pos[i] < 0){
                q.push_back(i);
                visited[i] = 1;
            }else r = max(pos[i],r);
        }
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s >> t;
    g = new vector<int>[n];
    FOR(i,0,m){
        int u,v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
    }
    find_path(s-1,t-1);
    //set position for each node in path
    for(int i = 1;i<=path.size();i++)
        pos[path[i-1]] = i;
    int r = -1;
    int result = 0;
    for(int i : path){
        if(i != s-1 && i != t-1 && r <= pos[i])
            result ++ ;
        r = max(BFS(i),r);
    }
    cout<<result<<"\n";
    return 0;
}