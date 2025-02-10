#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
int day[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct node{
	int id,val;
	bool operator <(const node&y)const{
		return id<y.id;
	}
}a[maxn];
int dp[maxn][5*maxn];//表示前i能否到达j
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=12;i++)day[i]+=day[i-1];
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int y,d,v;cin>>y>>d>>v;
		int dd=day[y-1]+d;
		a[i].id=dd;
		a[i].val=v;
	}
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		int l=i-1;
		while(l>0&&a[i].id-a[l].id<k)l--;
		for(int j=0;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			if(a[i].val<=j)dp[i][j]|=dp[l][j-a[i].val];
		}
	}
	for(int i=m;i>=0;i--){
		if(dp[n][i]){
			cout<<i;
			break;
		}
	}
	return 0;
}
/*
  2 15 365
  1 31 5
  1 2 16
 */
