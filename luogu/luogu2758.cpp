#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a,b;cin>>a>>b;
	int la=a.size(),lb=b.size();
	for(int i=1;i<=lb;i++)dp[0][i]=i;
	for(int i=1;i<=la;i++)dp[i][0]=i;
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
			else{
				dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
			}
		}
	}
	cout<<dp[la][lb];
	return 0;
}
