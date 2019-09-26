#include<iostream>
#include<math.h>

using namespace std;
#define max 1000000007
#define inver 333333336
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
    
    s1 = (((l*l) % max) * (inver % max)) % max;
    s2 = (doPow(4,n+1) - 1 + max) % max;
    s = (s1*s2) % max;
    //s3 = doPow(3,max-2);
    //s = (s*s3)%max;
    
    s %= max;
    cout<<s<<"\n";
    return 0;
}