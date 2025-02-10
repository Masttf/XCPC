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
	vector<double>f(n+1),g(n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+n*1.0/(n-i+1);
		double p=n*1.0/(n-i+1);
		g[i]=g[i-1]+(f[i-1]+p)*p;
	}
	cout<<fixed<<setprecision(2)<<g[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}