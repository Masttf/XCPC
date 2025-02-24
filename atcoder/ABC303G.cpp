#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3005;
int dp[maxn][maxn];
int val[maxn];
int pre[maxn],suf[maxn];
int st[maxn][maxn][20];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+val[i];
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+val[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int r=j+i-1;
			dp[i][j]=max(val[j]-dp[i-1][j+1],val[r]-dp[i-1][j]);
			if(i<=b){
				dp[i][j]=max(dp[i][j],pre[r]-pre[j-1]-a);
			}else{
				int len=i-b;
//				for(int k=j;k+len-1<=r;k++){
//					dp[i][j]=max(dp[i][j],pre[k-1]-pre[j-1]+suf[k+len]-suf[r+1]-dp[len][k]-a);
//				}
				int dd=r+1-len-j+1;
				dd=log2(dd);
				dp[i][j]=max(dp[i][j],max(st[len][j][dd],st[len][r+1-len-(1LL<<dd)+1][dd])-pre[j-1]-suf[r+1]-a);
			}
			if(i<=d){
				dp[i][j]=max(dp[i][j],pre[r]-pre[j-1]-c);
			}else{
				int len=i-d;
//				for(int k=j;k+len-1<=r;k++){
//					dp[i][j]=max(dp[i][j],pre[k-1]-pre[j-1]+suf[k+len]-suf[r+1]-dp[len][k]-c);
//				}
				int dd=r+1-len-j+1;
				dd=log2(dd);
				dp[i][j]=max(dp[i][j],max(st[len][j][dd],st[len][r+1-len-(1LL<<dd)+1][dd])-pre[j-1]-suf[r+1]-c);
			}
		}
		for(int k=1;k<=n-i+1;k++){
			st[i][k][0]=pre[k-1]+suf[k+i]-dp[i][k];
		}
		for(int len=1;(1LL<<len)<=n-i+2;len++){
			for(int s=1;s+(1LL<<len)-1<=n-i+1;s++){
				st[i][s][len]=max(st[i][s][len-1],st[i][s+(1LL<<(len-1))][len-1]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;(1LL<<j)<=n-i+2;j++){
//			cout<<j<<'\n';
//			for(int k=1;k<=n-i+1;k++){
//				cout<<st[i][k][j]<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<'\n';
//	}
	cout<<dp[n][1];
	return 0;
}
