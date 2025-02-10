#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int res[maxn];
int dp[maxn][20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		dp[i][0]=res[i];
	}
	for(int k=1;(1<<k)<=n;k++){
		for(int s=1;s+(1<<k)<=n+1;s++){
			dp[s][k]=min(dp[s][k-1],dp[s+(1<<(k-1))][k-1]);
		}
	}
	int l,r;
	while(m--){
		cin>>l>>r;
		int k=log2(r-l+1);
		cout<<min(dp[l][k],dp[r-(1<<k)+1][k])<<' ';
	}
}
