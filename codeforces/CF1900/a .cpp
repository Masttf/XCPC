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
	string s;cin>>s;
	s=' '+s;
	int ans=0;
	int ok=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='#')continue;
		int j=i;
		while(j<=n&&s[j]=='.')j++;
		int len=j-i;
		if(len>=3)ok=1;
		ans+=len;
		i=j-1;
	}
	if(ok)cout<<2<<'\n';
	else cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}