#include<queue>
#include<iostream>
#include<stdio.h>

using namespace std;
int n,m;
int move_t = 0;
priority_queue<int, vector<int>, greater<int>> q;

void enter(){
    scanf("%d %d",&n,&m);
    for(int i =0;i<n;i++){
        int t,staff;
        scanf("%d%d",&t,&staff);
        for(int j = 0; j < staff; j++){
            int t2;
            scanf("%d",&t2);
            q.push(t2 > move_t ? t2-move_t : 0);
        }
        move_t += t;
    }



}
void solve(){
    if(m > q.size())
        m = q.size();
    int res = 0;
    for(int i = 0; i < m; i++){
        res += q.top();
        printf("q.top: %d\n",q.top());
        printf("res: %d\n",res);
        q.pop();
    }
    printf("%d",res+move_t);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
        enter();
        solve();

    return 0;
}