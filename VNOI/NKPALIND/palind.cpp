#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i = 0;i< n; i++)
#define _rep(i,n) for(int i = 0;i< n-1; i++)
#define MAX 2000

using namespace std;

int main(){
    char s[2000];
    scanf("%s",s);
    int n = strlen(s);
    vector<vector<int>> f(2000,vector<int> (2000,0) );
    
    rep(i,n) f[i][i] = 1;
    _rep(i,n) f[i][i+1] = s[i] == s[i+1] ? 2 : 1;
    for(int l = 2;l < n;l++)
        for(int i = 0;i <= n -l;i ++){
            int j = i + l;
            if(s[i] == s[j])
                f[i][j] = max(f[i+1][j-1] + 2,max(f[i][j-1], f[i+1][j]) );
            else f[i][j] = max(f[i][j-1], f[i+1][j]);
        }
    
    int t[2000] = {0}; 
    int l = 0; int r = n-1;int len = f[0][n-1];

    while(l <= r && len > 0){
        if(s[l] == s[r]){
            t[l] = t[r] = 1;
            len-= 2;l++; r--;
        }
        else if(f[l][r-1] == len){
            r--;
        }
        else l++;

    }
    rep(i,n)
        if(t[i]) printf("%c",s[i]);
    return 0;
}