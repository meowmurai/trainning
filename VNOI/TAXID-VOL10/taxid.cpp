#include<iostream>
#include<math.h>
#include<vector>
#include<map>

#define rep(i,n) for(int i = 1;i<=n;i++)

using namespace std;

//map<int,char> m;
int n,m,p,q,k;
int *c,*base;
int res;
map<int,char> ma;

int baseDet(long int n){
    int res = 0;
    while(n!=0){
        int tmp = n/ 36;
        n = n % 36;
        if(tmp != 0)
            res = tmp > res ? tmp:res;
        else{
            res = n > res ? n:res;
            n = 0;
        }
    }
    return res;
}

void mapInit(){
    int d = 0;
    for(char i = '0';i<= '9';i++,d++)
        ma[d] = i;
    for(char i = 'a';i<= 'z';i++,d++)
        ma[d] = i;
}
void enter(){
    cin >> n >> m >> p >> q;
    k = floor((m-1)/2);
    c = (int*)malloc(sizeof(int)*(k+2));
    base = (int*)malloc(sizeof(int)*(n+1));
    rep(i,k) cin >> c[i];
    rep(i,n) base[i] = baseDet(i);
    c[0] = -1;
    c[k+1] = 37; 
}
void solve(){
    int l,r;
    if( m&1 && p == m){
        l = c[k];
        r = 37; 
    }
    else if(!(m&1) && (p == m-1 || p == m)){
        l = c[k];
        r = 37;
    }
    else if(p == 1 || p == 2){
        l = -1;
        r = c[1];
    }
    else{
        int tmp = (int)ceil((float)p/2);
        l = c[tmp - 1];
        r = c[tmp];
    }
    rep(i,n){
        if(base[i] <= l || base[i] >= r)
            base[i] = -1;
    }
    int count = 0;
    if(p & 1)
        rep(i,n){
            if(base[i] != -1){
                count ++;
            }
            if(count == q) res = i;
        }
    else
        for(int i = n; i > 0; i--){
            if(base[i] != -1) count ++;
            if(count == q) res = i;
        }
}
string baseChange(int a){
    string _res = "";
    int _n = a;
    while(_n!=0){
        int tmp = _n/ 36;
        _n = _n % 36;
        if(tmp != 0)
            _res += ma[tmp];
        else{
            _res += ma[_n];
            _n = 0;
        }
    }
    return _res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mapInit();
    enter();
    solve();

    cout<<baseChange(res)<<"\n";

    free(base);
    free(c);
    return 0;
}