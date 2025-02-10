#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<vector<int>>a(n);
	int mi=INT_MAX;
	int sum=0;
	for(int i=0;i<n;i++){
		int m;cin>>m;
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			mi=min(mi,x);
			a[i].push_back(x);
		}
		sort(a[i].begin(),a[i].end());
		sum+=a[i][1];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,sum+mi-a[i][1]);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
