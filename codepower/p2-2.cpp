#include<iostream>
#include<vector>

using namespace std;
void solution(vector<int> v, int n, int &length,int &ind){
    int sum = 0,tmp = 0;
    for(int i = 0;i < n;i++){
        sum += v[i];
        tmp ++;
        if((sum >= 0) && (tmp > length)){
            length = tmp;
            ind = i - tmp + 1;
        }
        else if(sum < 0){
            sum = 0;
            tmp = 0;
        }
    }
}
int main(){
    int n,p;
    vector<int> v;
    cin>>n>>p;

    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        tmp -= p;
        v.push_back(tmp);
    }

    int length = 0;
    int ind = 0;
    solution(v,n,length,ind);
    cout<<length<<"\n";
    cout<<ind<<" "<<ind + length - 1<<"\n";
    return 0;
}