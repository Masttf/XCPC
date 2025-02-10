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
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	auto check = [&](int x)->bool{
		vector<int>temp;
		for(int i=0;i<x;i++)temp.push_back(cnt[i]);
		sort(temp.begin(),temp.end());
		int nw=1;
		for(auto x:temp){
			if(x<nw)return false;
			if(nw==1)nw++;
		}
		return true;
	};
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
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