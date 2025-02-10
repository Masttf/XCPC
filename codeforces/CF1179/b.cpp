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
	int n,m;cin>>n>>m;
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=m;j++){
			cout<<i<<' '<<j<<'\n';
			cout<<n-i+1<<' '<<m-j+1<<'\n';
		}
	}
	if(n%2==1){
		int nw=(n+1)/2;
		for(int i=1;i<=m/2;i++){
			cout<<nw<<' '<<i<<'\n';
			cout<<nw<<' '<<m-i+1<<'\n';
		}
		if(m%2==1)cout<<nw<<' '<<(m+1)/2<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}