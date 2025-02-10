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
constexpr int N=2005;
constexpr int M=1000;
void solve(){
	int n,m;cin>>n>>m;
	vector a(n+1,vector<int>(m+1));
	vector f(N,vector<bitset<N>>(M));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			f[j][a[i][j]][i]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bitset<N>g={};
		for(int j=1;j<=m;j++){
			g^=f[j][a[i][j]];
		}
		g[i]=0;
		ans+=g.count();
	}
	ans/=2;
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