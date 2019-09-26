#include<iostream>
#include<math.h>

using namespace std;
#define max 1000000007
long long int doPow(int b,unsigned p){
    long long int res = 1;
    
    while(p > 0){
        if(p & 1)
            res = (res * b) % max;
        p = p >> 1;
        b = (b*b) % max;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n,l,s,s1,s2,s3;
    cin>>n>>l;
    
    s1 = l*l;
    s = s1;
    for(int i = 1;i <= n;i++){
        s1 *= 4;
        s += s1;
    }
    
    s %= max;
    cout<<s<<"\n";
    return 0;
}