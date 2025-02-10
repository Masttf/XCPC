#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>d(n+5);
	if(a[1]!=n){
		cout<<"NO\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		int l=1,r=a[i];
		d[l]++;
		d[r+1]--;
	}
	for(int i=1;i<=n;i++)d[i]+=d[i-1];
	int ok=1;
	for(int i=1;i<=n;i++){
		if(d[i]!=a[i])ok=0;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
