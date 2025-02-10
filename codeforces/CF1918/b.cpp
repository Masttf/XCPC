#include<bits/stdc++.h>
#define int long long
#define Max 1e18
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
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first;
	for(int i=1;i<=n;i++)cin>>a[i].second;
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		cout<<a[i].first<<" \n"[i==n];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i].second<<" \n"[i==n];
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}