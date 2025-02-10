#include<bits/stdc++.h>
#define int long long
using namespace std;
//对于这种问题考虑逐位考虑
void solve(){
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	vector<set<int>>p(26);
	for(int i=0;i<n;i++){
		p[a[i]-'a'].insert(i);
	}
	int ok=1;
	for(int i=0;i<m;i++){
		if(p[b[i]-'a'].empty()){
			ok=0;
			break;
		}
		int x=*p[b[i]-'a'].begin();
		p[b[i]-'a'].erase(p[b[i]-'a'].begin());
		for(int j=0;j<b[i]-'a';j++){
			while(!p[j].empty()&&*p[j].begin()<x)p[j].erase(p[j].begin());
		}
	}
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}