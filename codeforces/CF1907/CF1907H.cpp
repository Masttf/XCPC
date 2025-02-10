#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	auto check = [&](int x)->bool{
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			l=max(l-x,a[i].first);
			r=min(r+x,a[i].second);
			if(r<l)return false;
		}
		return true;
	};
	int l=0,r=1e9;
	int ans=r;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}