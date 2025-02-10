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
	vector<int>a(n+1),c(n+1);
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	map<int,int>m;
	for(int i=1;i<=n;i++){
		if(!m.count(c[i]))m[c[i]]=a[i];
		else m[c[i]]=min(m[c[i]],a[i]);
	}
	int ans=0;
	for(auto x:m){
		ans=max(ans,x.second);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}