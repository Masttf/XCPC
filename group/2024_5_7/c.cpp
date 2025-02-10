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
	int n,k,b;cin>>n>>k>>b;
	vector<int>a(n+1,0);
	for(int i=1;i<=b;i++){
		int x;cin>>x;
		a[x]=1;
	}
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=k;
	for(int i=1;i+k-1<=n;i++){
		ans=min(ans,pre[i+k-1]-pre[i-1]);
	}
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