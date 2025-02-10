#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	map<int,int>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]=i;
	}
	int now=m[-1];
	for(int i=1;i<=n-1;i++){
		cout<<now<<' ';
		now=m[now];
	}
	cout<<now<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}