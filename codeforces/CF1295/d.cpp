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
	int a,m;cin>>a>>m;
	int n=m/__gcd(a,m);
	int ans=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) ans=ans/i*(i-1);
		while(n%i==0) n/=i;
	}
	if(n>1) ans=ans/n*(n-1);
	cout<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}