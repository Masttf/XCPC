#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
const int maxn=2e6+5;
vector<int>p;
bool vis[maxn];
void init(){
	for(int i=2;i<=maxn-5;i++){
		if(!vis[i])p.push_back(i);
		for(int j=0;p[j]*i<=maxn-5;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	return ;
}
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<int>>g(n+1);
	for(int i=1;i<=n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	

	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}