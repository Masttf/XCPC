#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	s=' '+s;
	int cnt=0;
	int mx=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')cnt=0;
		else if(s[i]=='2')cnt++;
		mx=max(mx,cnt);
	}
	int ans=mx;
	cnt=0;
	int cnt2=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			ans=max(ans,mx+max(0ll,cnt-(mx-cnt2)-m));
			cnt=0;
			cnt2=0;
		}else if(s[i]=='1')cnt++;
		else cnt2++;
	}
	ans=max(ans,mx+max(0ll,cnt-(mx-cnt2)-m));
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}