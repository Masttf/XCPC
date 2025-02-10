#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int b,c,h;cin>>b>>c>>h;
	int d=c+h;
	if(d>=b)cout<<b*2-1<<'\n';
	else cout<<d*2+1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
