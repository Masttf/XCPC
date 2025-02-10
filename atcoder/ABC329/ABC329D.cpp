#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	int mx=0;
	vector<set<int>>a(m+1);
	for(int i=1;i<=n;i++)a[0].insert(i);
	vector<int>cnt(n+1);
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		int d=cnt[x];
		a[d].erase(x);
		cnt[x]++;
		a[cnt[x]].insert(x);
		mx=max(mx,cnt[x]);
		cout<<*(a[mx].begin())<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}