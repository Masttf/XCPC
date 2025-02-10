#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5,M=1e7+5;
int val[maxn],w[maxn];
int dp[M];//定义容量为多少时最大的价值为多少
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t,m;cin>>t>>m;
	for(int i=1;i<=m;i++) cin>>w[i]>>val[i];
	for(int i=1;i<=m;i++){
		for(int j=w[i];j<=t;j++){
			dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
		}
	}
	cout<<dp[t];
	return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
int val[maxn],w[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t,m;cin>>t>>m;
	vector<vector<int> >dp(m+5,vector<int>(t+5,0));
	for(int i=1;i<=m;i++) cin>>w[i]>>val[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t;j++){
			for(int z=0;z<=j/w[i];z++){
				dp[i][j]=max(dp[i][j],dp[i-1][j-z*w[i]]+z*val[i]);
			}
		}
	}
	cout<<dp[m][t];
	return 0;
}
*/
