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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int sum=0;
	for(int i=1;i<=n;i++)sum^=a[i];
	if(sum==0){
		cout<<"lose\n";
		return ;
	}else{
		vector<pair<int,int>>res;
		for(int i=1;i<=n;i++){
			int d=sum^a[i];
			if(d<a[i])res.push_back({i,a[i]-d});
		}
		sort(res.begin(),res.end());
		auto [p,d]=res[0];
		cout<<d<<' '<<p<<'\n';
		a[p]-=d;
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" \n"[i==n];
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