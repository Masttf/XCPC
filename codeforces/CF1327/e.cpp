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
const int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<int>p(n+1);
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*10%mod;
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			cout<<10<<'\n';
		}else{
			int ans=p[n-i]*18%mod+(n-i-1)*p[n-i-1]*81%mod;
			ans%=mod;
			cout<<ans<<' ';
		}
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