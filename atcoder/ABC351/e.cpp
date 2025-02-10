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
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	int ans=0;
	vector<pair<int,int>>res0;
	vector<pair<int,int>>res1;
	for(int i=1;i<=n;i++){
		if(a[i].first%2==a[i].second%2)res0.push_back(a[i]);
		else res1.push_back(a[i]);
	}
	auto get = [&](vector<pair<int,int>>&res)->int{
		int sum=0;
		int sz=res.size();
		vector<int>x(sz+1),y(sz+1);
		for(int i=0;i<sz;i++){
			auto [l,r]=res[i];
			x[i+1]=l+r;
			y[i+1]=l-r;
		}
		sort(x.begin()+1,x.end());
		vector<int>pre(sz+1);
		for(int i=1;i<=sz;i++){
			pre[i]=pre[i-1]+x[i];
		}
		for(int i=1;i<=sz;i++){
			sum+=(i-1)*x[i]-pre[i-1]+pre[sz]-pre[i]-(sz-i)*x[i];
		}
		sort(y.begin()+1,y.end());
		for(int i=1;i<=sz;i++){
			pre[i]=pre[i-1]+y[i];
		}
		for(int i=1;i<=sz;i++){
			sum+=(i-1)*y[i]-pre[i-1]+pre[sz]-pre[i]-(sz-i)*y[i];
		}
		return sum;
	};
	ans+=get(res0);
	ans+=get(res1);
	ans/=4;
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