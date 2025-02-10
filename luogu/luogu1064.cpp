#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=32005,N=65;
vector<int>res[N];
int dp[N][M],v[N],w[N],id[N],d;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>m>>n;
	int t;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i]>>t;
		if(t)res[t].push_back(i);
		else id[++d]=i;
	}
	for(int i=1;i<=d;i++){
		int p=id[i];
		for(int j=0;j<=m;j++){
			if(w[p]>j)dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[p]]+v[p]*w[p]);
				for(auto x:res[p]){
					if(j>=w[p]+w[x]){
						dp[i][j]=max(dp[i][j],dp[i-1][j-w[p]-w[x]]+v[p]*w[p]+v[x]*w[x]);
					}
				}
				if(res[p].size()==2){
					if(j>=w[p]+w[res[p][0]]+w[res[p][1]]){
						dp[i][j]=max(dp[i][j],dp[i-1][j-(w[p]+w[res[p][0]]+w[res[p][1]])]+v[p]*w[p]+v[res[p][0]]*w[res[p][0]]+v[res[p][1]]*w[res[p][1]]);
					}
				}
			}
		}
	}
	cout<<dp[d][m];
	return 0;
}
