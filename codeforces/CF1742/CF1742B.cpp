#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	set<int>se;
	int n;cin>>n;
	int x;
	for(int i=1;i<=n;i++)cin>>x,se.insert(x);
	if(se.size()==n)cout<<"yes\n";
	else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
