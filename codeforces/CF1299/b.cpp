#include<bits/stdc++.h>
#define int int long long
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
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	if(n%2==1){
		cout<<"NO\n";
		return ;
	}
	int ok=1;
	int tx=a[1].first+a[1+n/2].first;
	int ty=a[1].second+a[1+n/2].second;
	for(int i=1;i<=n/2;i++){
		int nx=a[i].first+a[i+n/2].first;
		int ny=a[i].second+a[i+n/2].second;
		if(nx!=tx||ty!=ny)ok=0;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}