#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>vis(n+1);
	vector<int>res;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		res.push_back(i);
		vis[i]=1;
		int now=i;
		while(now*2<=n&&!vis[now*2])now*=2,res.push_back(now),vis[now]=1;
	}
	for(auto x:res)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
