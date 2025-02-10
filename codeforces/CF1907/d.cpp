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
	vector<pair<int,int>>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second,mx=max(mx,a[i].second);
	auto check = [&](int k)->bool{
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			int ll=l-k;
			int rr=r+k;
			if(a[i].first<=ll&&rr<=a[i].second){
				l=ll;
				r=rr;
			}else if(ll<=a[i].first&&a[i].second<=rr){
				l=a[i].first;
				r=a[i].second;
			}else if(ll>=a[i].first&&ll<=a[i].second){
				l=ll;
				r=min(rr,a[i].second);
			}else if(rr>=a[i].first&&rr<=a[i].second){
				r=rr;
				l=max(ll,a[i].first);
			}else return false;
			//dbg(l,r,k);
		}
		return true;
	};
	int l=a[1].first,r=mx;
	int ans=mx;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
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