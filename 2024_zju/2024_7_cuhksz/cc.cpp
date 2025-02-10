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
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int N=1<<18;
	vector<int>cnt(N+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	vector<int>vis(N+1);
	vector<int>d(N+1,Max);
	d[a[1]]=0;
	q.push({d[a[1]],a[1]});
	int ans=0;
	vector<pair<int,int>>res;
	while(!q.empty()){
		auto [w,u]=q.top();
		q.pop();
		if(cnt[u]&&vis[u])continue;
		if(cnt[u])ans+=w;
		// if(cnt[u]){
		// 	dbg(u);
		// 	//res.push_back({u,w});
		// }
		vis[u]=1;
		for(int i=17;i>=0;i--){
			int v=u^(1<<i);
			if(cnt[u]){
				if(d[v]>1){
					d[v]=1;
					q.push({d[v],v});
				}
			}else{
				if(d[v]>d[u]+1){
					d[v]=d[u]+1;
					q.push({d[v],v});
				}
			}
		}
	}
	cout<<ans<<'\n';
	// sort(res.begin(),res.end());
	// for(auto [x,w]:res){
	// 	cout<<x<<' '<<w<<'\n';
	// }
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}