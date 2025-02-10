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
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
const int Max=1e18;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1),b(m+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	int mx1=a[1];
	int res1=mx1;
	int mi1=a[1];
	int res2=mi1;
	for(int i=2;i<=n;i++){
		mx1=max(mx1+a[i],a[i]);
		mi1=min(mi1+a[i],a[i]);
		res1=max(res1,mx1);
		res2=min(res2,mi1);
	}
	int mx2=b[1];
	int res3=mx2;
	int mi2=b[1];
	int res4=mi2;
	for(int i=2;i<=m;i++){
		mx2=max(mx2+b[i],b[i]);
		mi2=min(mi2+b[i],b[i]);
		res3=max(res3,mx2);
		res4=min(res4,mi2);
	}
	int ans=max({res1*res3,res2*res4,res1*res4,res2*res3});
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}