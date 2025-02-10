#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int x,y,xx,yy;cin>>x>>y>>xx>>yy;
	int t2,t;
	if(x+y<n+1){
		t=min(x,y);
	}else {
		t=n+1-max(x,y);
	}
	if(xx+yy<n+1){
		t2=min(xx,yy);
	}else t2=n+1-max(xx,yy);
	cout<<abs(t2-t)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
