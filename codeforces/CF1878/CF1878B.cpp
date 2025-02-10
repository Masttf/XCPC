#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>ans(n+1);
	ans[1]=1,ans[2]=3;
	int now=4;
	for(int i=3;i<=n;i++){
		if(now*3%(ans[i-1]+ans[i-2])==0)now++;
		ans[i]=now;
		now++;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
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
