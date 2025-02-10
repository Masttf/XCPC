#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>vis(n+1);
	int ans=0;
	vector<pair<int,int>>res;
	auto get = [&](auto self,vector<pair<int,int>>&temp,int l,int r)->void{
		if(l==r)return ;
		self(self,temp,l,r-1);
		temp.push_back({l,r});
		temp.push_back({l,r-1});
		self(self,temp,l,r-1);
	};
	auto dfs = [&](auto self,int now)->void{
		if(now==n+1){
			int sum=0;
			vector<pair<int,int>>temp;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					int j=i;
					while(j<=n&&!vis[j])j++;
					int len=j-i;
					sum+=len*len;
					int ok=0;
					for(int k=i;k<=j-1;k++){
						if(!a[k])ok=1;
					}
					temp.push_back({i,j-1});
					if(ok) temp.push_back({i,j-1});
					get(get,temp,i,j-1);
					temp.push_back({i,j-1});
					i=j-1;
				}else sum+=a[i];
			}
			if(ans<sum){
				ans=sum;
				res=temp;
			}
			return ;
		}
		self(self,now+1);
		vis[now]=1;
		self(self,now+1);
		vis[now]=0;
	};
	dfs(dfs,1);
	cout<<ans<<' '<<res.size()<<'\n';
	for(auto [l,r]:res)cout<<l<<' '<<r<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}