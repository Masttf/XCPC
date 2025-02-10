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
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<string>name(k+1);
	vector<vector<pair<int,int>>>g(k+1);
	for(int i=1;i<=k;i++){
		cin>>name[i];
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			int l,r;cin>>l>>r;
			g[i].push_back({l,r});
		}
	}
	vector<string>ans;
	vector<int>vis(n+1);
	int cnt=0;
	while(cnt<n){
		int ook=0;
		for(int i=1;i<=k;i++){
			int ok=0;
			int flag=1;
			for(auto [p,x]:g[i]){
				if(vis[p])continue;
				if(x==a[p])ok=1;
				else flag=0;
			}
			if(flag&&ok){
				for(auto [p,x]:g[i]){
					if(!vis[p]){
						vis[p]=1;
						cnt++;
					}
				}
				ans.push_back(name[i]);
				ook=1;
				break;
			}
		}
		if(!ook){
			cout<<"IMPOSSIBLE\n";
			return ;
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans)cout<<x<<' ';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}