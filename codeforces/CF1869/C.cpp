#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int> >ans(n+1,vector<int>(m+1));
	if(m==1){
		cout<<0<<'\n';
		for(int i=1;i<=n;i++)cout<<0<<'\n';
		return ;
	}
	int d=1;
	if(n>=m){
		d=n-m+1;
		for(int i=1;i<=d;i++){
			for(int j=1;j<=m;j++)ans[i][j]=j-1;
		}
		d++;
	}
	//cout<<d<<endl;
	int s=0;
	for(int i=d;i<=n;i++){
		for(int j=1;j<=m;j++)ans[i][j]=(s+j-1)%m;
		s++;		
	}
	if(n>=m)cout<<m<<'\n';
	else cout<<n+1<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<ans[i][j]<<" \n"[j==m];
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}