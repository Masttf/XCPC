#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,s,k;cin>>n>>s>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		sum+=x*y;
	}
	if(sum<s)sum+=k;
	cout<<sum<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}