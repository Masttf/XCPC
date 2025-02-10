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
const int Max=1e18;
const int mod=1e9+7;
const int maxn=1e7+5;
vector<int>p;
vector<int>vis(maxn);
void init(){
	for(int i=2;i<=maxn-5;i++){
		if(!vis[i])p.push_back(i);
		for(int j=0;p[j]*i<=maxn-5;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
void solve(){
	int n;cin>>n;
	vector<int>ans(n+1);
	auto dfs = [&](auto self,int n)->void{
		if(n==0)return ;
		int k=upper_bound(p.begin(),p.end(),n)-p.begin();
		int d=p[k]-n;
		int res=n;
		//dbg(n,d);
		for(int i=d;i<=n;i++){
			ans[i]=res--;
		}
		self(self,d-1);
		return ;
	};
	dfs(dfs,n);
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	init();
	while(t--)solve();
	return 0;
}