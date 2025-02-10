#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	vector<int>pre(n+1);
	vector<int>res;
	res.push_back(0);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(s[i]=='A')pre[i]++;
		else res.push_back(i);
	}
	res.push_back(n);
	if(res.size()==2){
		cout<<0<<'\n';
		return ;
	}
	int ans=0;
	int sz=res.size();
	for(int i=0;i<sz-1;i++){
		ans=max(ans,pre[n]-pre[res[i+1]]+pre[res[i]]);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
