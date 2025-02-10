#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[105][105],cnt[105];
void solve(){
	memset(cnt,0,sizeof(cnt));
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			cin>>res[i][j];
		}
	}
	int mx=res[1][1];
	for(int i=1;i<=n;i++){
		cnt[res[i][1]]++;
		if(cnt[res[i][1]]>cnt[mx])mx=res[i][1];
	}
	for(int i=1;i<=n;i++){
		if(res[i][1]!=mx){
			cout<<mx<<' ';
			for(int j=1;j<=n-1;j++)cout<<res[i][j]<<' ';
			break;
		}
	}
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
