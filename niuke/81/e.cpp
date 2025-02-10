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
	vector<pair<int,int>>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		mx=max(mx,a[i].first);
	}
	sort(a.begin()+1,a.end());
	auto check = [&](int x)->bool{
		int res=0;
		for(int i=1;i<=n;i++){
			//if(a[i].first<=x)continue;
			res+=max(min(a[i].first-a[i].second,a[i].first-x),0ll);
		}
		return res<=m;
	};  
	int ans=mx;
	int l=0,r=mx;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	int sum=0;
	for(int i=n;i>=1;i--){
		int d=min(a[i].first-a[i].second,a[i].first-ans);
		if(d<=0)continue;
		m-=d;
		sum+=d*(2*a[i].first-d);
		a[i].first-=d;
	}
	for(int i=n;i>=1;i--){
		if(!m)break;
		if(a[i].first==a[i].second)continue;
		m--;
		sum+=(a[i].first*2-1);
		a[i].first--;
	}
	
	cout<<sum<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}