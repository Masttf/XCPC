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
	vector<int>l(n+1);
	vector<int>r(n+1);
	int ans=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	auto dfs = [&](auto self,int now,int val)->void{
		int res=val;
		if(s[now]=='U')res++;
		if(!l[now]&&!r[now])ans=min(ans,val);
		if(l[now])self(self,l[now],res+(s[now]=='R'));
		if(r[now])self(self,r[now],res+(s[now]=='L'));
		return ;
	};
	dfs(dfs,1,0);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}