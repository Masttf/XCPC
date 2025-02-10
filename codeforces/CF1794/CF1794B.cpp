#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==1)a[i]++;
	}
	for(int i=1;i<=n-1;i++){
		if(a[i+1]%a[i]==0)a[i+1]++;
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
