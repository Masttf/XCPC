#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int xa,ya,xb,yb,xc,yc;
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	int dx1=xb-xa,dy1=yb-ya;
	int dx2=xc-xa,dy2=yc-ya;
	int ans=0;
	if(dx1*dx2>0&&dy1*dy2>0){
		ans=max(ans,min(abs(dx1),abs(dx2))+min(abs(dy1),abs(dy2)));
	}
	else if(dy1*dy2>0){
		ans=max(ans,min(abs(dy1),abs(dy2)));
	}else if(dx1*dx2>0){
		ans=max(ans,min(abs(dx1),abs(dx2)));
	}
	ans++;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
