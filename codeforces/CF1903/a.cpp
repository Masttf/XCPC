#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ok=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1])ok=0;
	}
	if(ok){
		cout<<"Yes\n";
		return ;
	}else{
		if(k>=2)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}