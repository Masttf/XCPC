#include<bits/stdc++.h>
using namespace std;
pair<double,double>res[20];
double dp[1<<20][20];//表示在第i种情况中以j为最后一个点
double js(pair<double,double>a,pair<double,double>b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<(1<<(n+1));i++){
		for(int j=1;j<=n+1;j++)dp[i][j]=INT_MAX;
	}
	for(int i=2;i<=n+1;i++)cin>>res[i].first>>res[i].second;
	dp[1][1]=0;
	for(int s=1;s<(1<<(n+1));s++){
		for(int j=0;j<n+1;j++){
			if((s>>j)&1){
				for(int k=0;k<n+1;k++){
					if(((s^(1<<j))>>k)&1){
						dp[s][j+1]=min(dp[s][j+1],dp[s^(1<<j)][k+1]+js(res[k+1],res[j+1]));
					}
				}
			}
		}
	}
	double mi=999999999;
	for(int i=2;i<=n+1;i++)mi=min(mi,dp[(1<<(n+1))-1][i]);
	cout<<fixed<<setprecision(2)<<mi;
	return 0;
}
