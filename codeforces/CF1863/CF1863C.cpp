#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	
	k%=(n+1);
	int mx=0;
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	for(int i=0;i<=n;i++){
		if(!cnt[i]){
			mx=i;
			break;
		}
	}
	a[0]=mx;
	int l=1-k;
	if(l<0)l+=n+1;
	for(int j=0;j<n;j++){
		cout<<a[(l+j)%(n+1)]<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
