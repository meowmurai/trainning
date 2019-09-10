	
#include<algorithm>
	
#include<climits>
	
#include<cstdio>
	
#include<vector>

#include<iostream>

using namespace std;
	
 
	
#define N 200000
	
int n, m, t[N];
	
vector<int> a[N];
	
 
	
void enter() {
	
	scanf("%d%d",&n,&m); int staff = 0;
	cout<<n<<endl;
	for(int i = 0; i < n; ++i) {
	
		scanf("%d", t+i);
	
		int p; scanf("%d", &p); staff += p;
	
		while(p--) {
	
			int tmp; scanf("%d", &tmp);
	
			a[i].push_back(tmp);
	
		}
	
		sort(a[i].begin(), a[i].end());
	
	}
	
	m = min(staff, m);
	
}
	
 
	
void solve() {
	
	int lo = 0, hi = INT_MAX;
	
	while(lo < hi) {
	
		int mid = (lo + hi) / 2;
	
		int cnt = 0;
	
		for(int time = mid, i = 0; i < n && cnt < m; time += t[i++]) 
	
			cnt += upper_bound(a[i].begin(), a[i].end(), time) - a[i].begin();
	
		if(cnt >= m) hi = mid; else lo = mid + 1;
	
	}
	
	for(int i = 0; i < n; lo += t[i++]);
	
	printf("%d\n", lo);
	
}
	
 
	
int main() {
	
#ifndef ONLINE_JUDGE
	
	freopen("input.txt", "r", stdin);
	
#endif
	
	enter();
	
	solve();
	
	return 0;
	
}