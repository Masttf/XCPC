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
const int mod=1e9+7;
void solve(){
	int n;cin>>n;
	string x;cin>>x;
	int y;cin>>y;
	int yy=1;
	for(int i=1;i<n;i++)yy*=10;
	if(n==1)yy=0;
	int ty=0;
	int flag=-1;
	map<char,int>m;
	map<int,int>mm;
	for(auto i:x){
		if(i>='0'&&i<='9')continue;
		if(!m.count(i)){
			m[i]=++ty;
			if(i=='_')flag=ty;
		}
	}
	int ans=0;
	vector<int>vis(10);
	auto dfs = [&](auto self,int k)->void{
		if(k==ty+1){
			int res=0;
			for(auto i:x){
				if(i>='0'&&i<='9')res=res*10+i-'0';
				else res=res*10+mm[m[i]];
			}
			if(res%8==0&&res>=yy&&res<=y)ans++;
			return ;
		}
		for(int i=0;i<10;i++){
			if(k==flag){
				mm[k]=i;
				self(self,k+1);
			}else{
				if(vis[i])continue;
				vis[i]=1;
				mm[k]=i;
				self(self,k+1);
				vis[i]=0;
			}
		}
	};
	dfs(dfs,1);
	ans%=mod;
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