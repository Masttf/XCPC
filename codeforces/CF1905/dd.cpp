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
	vector<int>a(2*n+1);
	for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
	stack<pair<int,int>>s;
	vector<int>vis(n+1);
	int ans=0;
	int res=0;
	int now=0;
	for(int i=1;i<=n;i++){
		vis[a[i]]=1;
		while(vis[now])now++;
		ans+=now;
		res+=now;
		while(!s.empty()&&now<=s.top().first){
			s.pop();
		}
		s.push({now,i});
	}
	//dbg(ans,res);
	for(int i=1+n;i<=2*n;i++){
		while(!s.empty()&&a[i]<=s.top().first){
			int d=s.top().first;
			int r=s.top().second;
			s.pop();
			int l;
			if(!s.empty())l=s.top().second;
			else l=i-n-1;
			res-=d*(r-l);
			//dbg(l,r,a[i]);
		}
		int l;
		if(!s.empty())l=s.top().second;
		else l=i-n;
		//dbg(i,res,l,a[i]);
		res+=n+a[i]*(i-1-l);
		//dbg(i,res);
		s.push({a[i],i-1});
		s.push({n,i});
		ans=max(ans,res);
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