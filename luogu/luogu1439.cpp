#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],b[maxn];
int dp[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][n];
	return 0;
}
