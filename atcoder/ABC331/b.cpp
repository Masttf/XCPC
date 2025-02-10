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
	int n,s,m,l;cin>>n>>s>>m>>l;
	int ans=LONG_LONG_MAX;
	for(int i=0;i*6<=n+6;i++){
		int d=n-i*6;
		for(int j=0;j*8<=d+8;j++){
			int t=d-j*8;
			int k=(t+11)/12;
			ans=min(ans,i*s+j*m+k*l);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}