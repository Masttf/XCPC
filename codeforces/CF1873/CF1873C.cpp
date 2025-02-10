#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[20];
int val[20][20];
void init(){
	for(int k=1;k<=5;k++){
		int r=11-k;
		for(int i=1+k-1;i<=10-k+1;i++)val[i][k]=k,val[i][r]=k;
		for(int i=1+k-1;i<=10-k+1;i++)val[k][i]=k,val[r][i]=k;
	}
	return ;
}
void solve(){
	for(int i=0;i<10;i++){
		cin>>s[i];
	}
	int ans=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(s[i][j]=='X'){
				ans+=val[i+1][j+1];
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
