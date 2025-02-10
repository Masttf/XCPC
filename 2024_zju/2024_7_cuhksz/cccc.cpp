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
	int N=1<<18;
	vector<int>a(n+1);
	vector<int>vis(N+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=1;
	}
	vector<int>d(N+1,Max);
	int ans=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	d[a[1]]=0;
	q.push({d[a[1]],a[1]});
	while(!q.empty()){
		auto [w,u]=q.top();
		if(vis[u]){
			ans+=d[u];
			d[u]=0;
		}
		q.pop();
		for(int i=17;i>=0;i--){
			int v=u^(1<<i);
			if(d[v]>d[u]+1){
				d[v]=d[u]+1;
				q.push({d[v],v});
			}
			
		}
	}
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