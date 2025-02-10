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
//constexpr int mod=1e9+7;
void solve(){
	int n,a,x,y;cin>>n>>a>>x>>y;
	map<int,double>m;
	auto dfs = [&](auto self,int now)->double{
		if(now==0)return 0;
		if(m.count(now))return m[now];
		m[now]=self(self,now/a)+x;
		double ans=0;
		for(int i=2;i<=6;i++){
			ans+=self(self,now/i);
		}
		ans+=y*6;
		ans/=5;
		m[now]=min(m[now],ans);
		return m[now];
	};
	cout<<fixed<<setprecision(10)<<dfs(dfs,n)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}