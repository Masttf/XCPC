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
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=(k+2)*(k+1)/2;
	ans-=n;
	vector<int>p2;
	vector<int>p1;
	for(int i=1;i<=n;i++){
		ans-=k-a[i];
		if(a[i]%2==0)p2.push_back(a[i]);
		else p1.push_back(a[i]);
	}
	//dbg(ans);
	for(int i=1;i<=n;i++){
		int max=a[i]-2;
		if(a[i]<=1)continue;
		if(a[i]%2==0){
			int k=upper_bound(p2.begin(),p2.end(),max)-p2.begin();
			ans-=max/2+1-k;
		}else{
			int k=upper_bound(p1.begin(),p1.end(),max)-p1.begin();
			ans-=max/2+1-k;
		}
		//dbg(i,ans);
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