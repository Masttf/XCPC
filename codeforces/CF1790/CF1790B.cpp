#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,r,s;cin>>n>>s>>r;
	int x=s-r;
	if(n>1){
		int t=(s-x)/(n-1);
		cout<<x<<' ';
		int l=(s-x)%(n-1);
		for(int i=1;i<=n-1;i++){	
			if(i<=l){
				cout<<t+1<<' ';
			}else cout<<t<<' ';
		}
		cout<<'\n';
	}else cout<<r<<'\n';
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
