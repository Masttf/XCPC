#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	int mi=1e18;
	int mx=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
	}
	if(mx-mi>k)cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=mi;j++)cout<<1<<' ';
			for(int j=mi+1;j<=a[i];j++)cout<<j-mi<<' ';
			cout<<'\n';
		}
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