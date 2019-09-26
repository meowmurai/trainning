#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
bool compare(pair<long int,int> a, pair<long int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int findInd(vector<pair<long int,int>> preSum,int val,int n){
    int l = 0;
    int r = n - 1;
    int mid = (l + r)/2;
    int ind = -1;
    while(l < r){
        if(preSum[mid].first <= val){
            ind = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
        mid = (l+r)/2;
    }
    return ind;
}
void enter(vector<pair<long int,int>> &preSum,vector<int> &v,int n,int p){
    int sum = 0;
    for(int i = 0;i<n;i++){
        
        int tmp;
        cin>> tmp;
        tmp -= p;
        v.push_back(tmp);
        sum += tmp;
        preSum.push_back({sum,i});
    }
    sort(preSum.begin(),preSum.end(),compare);
}
int solution(vector<pair<long int,int>> &preSum,vector<int> v, int n,int p,int *minInd,int *start){
    int sum = 0;
    int max = 0;
    start[0] = 0;
    for(int i = 0;i < n;i++){
        sum += v[i];
        if(sum >= 0){
            max = i;
            start[i] = 0;
        }
        else{
            int ind  = findInd(preSum,sum,n);
            if(ind != -1){
                ind = minInd[ind];
                if( (sum - preSum[ind].first >= 0) && (preSum[ind].second < i) ){
                    start[i] = preSum[ind].second + 1;
                    if(i - start[i] + 1 > max - start[max] + 1)
                        max = i;
                }
            }
        }
    }
    return max;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p,max;
    
    cin >> n >> p;

    vector<pair<long int,int>> preSum;
    vector<int> v;
    int minInd[n],start[n];
    max = 0;
    enter(preSum,v,n,p);
    minInd[0] = 0;
    
    for(int i = 1;i<n;i++){
        if(preSum[minInd[i-1]].second > preSum[i].second)
            minInd[i] = i;
        else minInd[i] = minInd[i-1];
    }
    
    int res = solution(preSum, v, n, p, minInd, start);
    cout<<res-start[res]+1<<"\n";
    cout<<start[res]+1<<" "<<res+1<<"\n";
    return 0;
}