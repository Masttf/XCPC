#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,x,y;cin>>n>>m>>x>>y;
	if(y<x){
		cout<<"No\n";
		return ;
	}
	if(n-m>=y-x){
		cout<<"Yes\n";
		return ;
	}
	cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}