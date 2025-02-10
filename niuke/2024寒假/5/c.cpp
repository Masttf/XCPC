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
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans1=0;
	int ans2=0;
	int d=a[1]-1;
	for(int i=2;i<=n;i++){
		int k=a[i]-1;
		int res=min(k,d);
		ans1+=res;
		d=k-res;
	}
	ans1+=d;
	ans2=a[1]-1;
	d=0;
	for(int i=2;i<=n;i++){
		int k=a[i]-1;
		int res=min(k,d);
		ans2+=res;
		d=k-res;
	}
	ans2+=d;
	cout<<max(ans1,ans2)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}